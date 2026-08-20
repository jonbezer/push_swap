*This project has been created as part of the 42 curriculum by efeijo, jonbezer.*

# push_swap

## Description

O `push_swap` ordena um conjunto de inteiros distintos usando **duas pilhas** (`a` e `b`)
e um conjunto restrito de onze operações. O programa não exibe os números ordenados:
ele calcula e imprime na saída padrão a **sequência de operações** que, ao ser executada,
deixa a pilha `a` ordenada em ordem crescente e a pilha `b` vazia.

O objetivo do projeto é tornar concreta a noção de **complexidade algorítmica**. Neste
modelo, o custo de um algoritmo não é medido em tempo de CPU, mas no **número de
operações push_swap geradas**. Um algoritmo que executa rápido em C mas emite vinte mil
rotações é pior, pelas regras do projeto, do que um algoritmo mais lento que emite
setecentas.

O binário embarca **quatro estratégias distintas**, selecionáveis em tempo de execução.

### Operações disponíveis

| Operação | Efeito |
| --- | --- |
| `sa` / `sb` / `ss` | troca os dois elementos do topo de `a` / de `b` / de ambas |
| `pa` / `pb` | move o topo de uma pilha para o topo da outra |
| `ra` / `rb` / `rr` | rotaciona para cima: o primeiro elemento vai para o fim |
| `rra` / `rrb` / `rrr` | rotaciona para baixo: o último elemento vai para o início |

---

## Instructions

### Compilação

```bash
make          # compila a libft e gera o binário push_swap
make clean    # remove os objetos (.o)
make fclean   # remove objetos, binário e a libft.a
make re       # fclean + all
```

O `Makefile` compila com `-Wall -Wextra -Werror` e constrói primeiro a `libft/`,
através do Makefile próprio da biblioteca.

### Execução

```bash
./push_swap [seletor] <lista de inteiros>
```

Os inteiros podem ser passados como argumentos separados ou como uma única string
delimitada por espaços:

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

### Seletores de estratégia

| Flag | Estratégia | Classe |
| --- | --- | --- |
| `--simple` | seleção com extração do mínimo | O(n²) |
| `--medium` | bucket sort com `⌈√n⌉` faixas | O(n√n) |
| `--complex` | radix sort binário (LSD) | O(n log n) |
| `--adaptive` | escolhe a estratégia pela desordem medida | variável |
| *(nenhuma)* | equivale a `--adaptive` | variável |

A flag `--bench` pode ser combinada com qualquer seletor e emite métricas na
**saída de erro** (`stderr`), de modo que a saída padrão permaneça limpa para ser
consumida pelo `checker`.

### Exemplos

```bash
# ordenação simples
./push_swap 2 1 3 6 5 8

# forçando uma estratégia e validando com o checker
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG

# contando operações em uma entrada grande
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l

# benchmark separado das operações
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG
cat bench.txt
```

Saída do modo benchmark:

```
[bench] disorder: 49.93%
[bench] strategy: Complex / O(n log n)
[bench] total_ops: 6231
[bench] sa: 0 sb: 0 ss: 0 pa: 2000 pb: 2000
[bench] ra: 1231 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

### Tratamento de erros

O programa escreve `Error` seguido de `\n` em `stderr` e retorna `1` quando encontra:

- argumentos que não são inteiros válidos
- valores fora do intervalo de um `int` (`-2147483648` a `2147483647`)
- valores duplicados
- flags desconhecidas

Sem argumentos, o programa não imprime nada e devolve o prompt.

---

## Technical choices

### Estrutura de dados

Cada pilha é uma **lista duplamente ligada terminada em `NULL`**, encapsulada numa
struct que mantém ponteiros para o primeiro e o último nó, além do tamanho corrente:

```c
typedef struct s_stack
{
    t_node  *head;
    t_node  *tail;
    int     size;
    t_stats *stats;
}   t_stack;
```

Duas decisões merecem justificativa:

**Lista dupla, e não simples.** As seis operações de rotação (`ra`, `rb`, `rr`, `rra`,
`rrb`, `rrr`) representam mais da metade do repertório e são as mais executadas. O
ponteiro `prev` permite navegação reversa em custo constante, o que torna `rra` e `rrb`
simétricas a `ra` e `rb` em vez de exigirem travessia completa.

**Terminada em `NULL`, e não circular.** Uma lista circular tornaria as rotações uma
única atribuição, mas troca falhas ruidosas por falhas silenciosas: um erro na condição
de parada produz um laço infinito em vez de um segfault. O ponteiro `tail`, mantido pela
struct, recupera boa parte do custo constante que a versão circular ofereceria.

O campo `stats` é compartilhado entre as duas pilhas e acumula a contagem por tipo de
operação, permitindo o modo `--bench` sem recorrer a variáveis globais — proibidas pelo
subject.

### Normalização por rank

Antes de qualquer ordenação, `ft_assign_index` substitui cada valor pelo seu **rank**:
a posição que ele ocuparia numa lista ordenada, no intervalo `0..n-1`. O rank de um nó é
a contagem de quantos valores da pilha são menores que ele — cálculo exato, já que
duplicatas são rejeitadas no parsing.

Essa normalização elimina três classes de caso especial de uma vez:

- **valores negativos** deixam de existir, o que dispensa deslocamento de origem nas
  fórmulas de particionamento;
- **escalas extremas** desaparecem: a entrada `1 2 3 1000000` produz ranks
  `0 1 2 3`, uniformemente distribuídos;
- **overflow** em expressões como `max - min` — que estouraria um `int` para a entrada
  `-2147483648 2147483647` — nunca chega a ser calculado.

A normalização custa O(n²) em C, mas **zero operações push_swap**. No modelo de custo
deste projeto, portanto, é gratuita.

### Métrica de desordem

A desordem é a razão entre o número de **inversões** e o número total de pares. Um par
`(i, j)` com `i < j` é uma inversão quando `a[i] > a[j]`.

```
desordem = inversões / (n × (n-1) / 2)
```

O valor é 0 para uma lista já ordenada e 1 para a ordem completamente invertida. A
medição ocorre **antes de qualquer movimento**, como o subject exige.

Para evitar aritmética de ponto flutuante, o resultado é armazenado como inteiro em
escala de 10000 — isto é, `4000` representa `40,00%`. A exibição separa parte inteira e
centésimos por divisão e resto, preenchendo com zero à esquerda quando o resto é menor
que dez. A multiplicação é feita em `long` antes da divisão, o que evita tanto o
truncamento da divisão inteira quanto o estouro do produto `inversões × 10000` para
entradas grandes.

---

## Algorithms

### Simple — O(n²)

Ordenação por **seleção com extração do mínimo**. Enquanto restarem mais de três
elementos em `a`, o algoritmo localiza o menor, traz o menor até o topo escolhendo entre
`ra` e `rra` conforme a distância, e o empurra para `b`. Os três últimos elementos são
ordenados por um caso fechado de cinco possibilidades. Ao final, todos os elementos
retornam de `b` para `a` em ordem crescente.

Cada extração pode exigir até `n/2` rotações, e há `n` extrações — daí O(n²).

### Medium — O(n√n)

**Bucket sort** sobre os ranks, com faixas de tamanho `⌈√n⌉`.

*Fase 1 — distribuição.* As faixas são percorridas em ordem crescente. A cada passo, o
topo de `a` é examinado: se o rank pertence à faixa corrente, o elemento vai para `b`
via `pb`; caso contrário, `ra` avança a pilha. Como cada `pb` insere no topo de `b`, a
última faixa empurrada — a dos maiores ranks — termina no topo.

*Fase 2 — extração.* Os elementos saem de `b` em ordem **decrescente** de rank. Cada
`pa` insere no topo de `a`, de modo que o maior elemento, extraído primeiro, termina no
fundo. O elemento procurado está sempre na faixa do topo de `b`, nunca enterrado nas
camadas inferiores: a busca é confinada a `⌈√n⌉` posições. A distância até o topo é
comparada nos dois sentidos, e a rotação mais curta (`rb` ou `rrb`) é escolhida.

O custo é `n` transferências em cada fase, mais no máximo `√n` rotações por elemento —
o que fecha em O(n√n). É o tamanho da faixa, e não o tamanho da pilha, que limita a
janela de busca; essa é a razão de `√n` ser o ponto ótimo, e não um valor arbitrário.

### Complex — O(n log n)

**Radix sort binário (LSD)** sobre os ranks.

Como só há duas pilhas disponíveis, o algoritmo opera em base 2: cada bit dos ranks
define um dos dois destinos. Para cada posição de bit, do menos significativo ao mais
significativo, o algoritmo percorre `a` uma vez — elementos cujo bit é `0` vão para `b`
via `pb`, elementos cujo bit é `1` permanecem em `a` via `ra`. Ao fim da passada, todo o
conteúdo de `b` retorna para `a`.

Como os ranks pertencem ao intervalo `0..n-1`, bastam `⌈log₂ n⌉` passadas — nove para
`n = 500`. Cada passada custa no máximo `2n` operações, o que resulta em O(n log n).

A normalização por rank é o que viabiliza esta estratégia: operar sobre bits de valores
com sinal produziria resultados incorretos para números negativos.

### Adaptive

Não é um algoritmo próprio, mas um **seletor**. Mede a desordem antes de qualquer
movimento e delega para uma das três estratégias anteriores conforme o regime:

| Desordem medida | Estratégia | Classe |
| --- | --- | --- |
| < 20% | Simple | O(n²) |
| 20% – 50% | Medium | O(n√n) |
| ≥ 50% | Complex | O(n log n) |

**Racional dos limiares.** Os valores `0.2` e `0.5` são os fixados pelo subject. A
lógica por trás deles é que algoritmos de seleção têm custo proporcional ao deslocamento
real dos elementos: numa lista quase ordenada, a maioria já está em posição e poucas
rotações são gastas, de modo que o O(n²) teórico não se materializa. À medida que a
desordem cresce, esse comportamento se degrada e vale pagar o custo fixo de estratégias
com melhor limite assintótico.

Como a desordem é armazenada em escala de 10000, a comparação é feita contra os
inteiros `2000` e `5000`, sem qualquer uso de ponto flutuante.

### Limites de espaço

Todas as estratégias operam sobre os nós já alocados no parsing e não alocam memória
adicional durante a ordenação. O consumo é O(n) em todos os regimes.

---

## Resources

### Documentação e referências

- Subject oficial do projeto (42)
- `man 3 malloc`, `man 3 free`, `man 2 write`
- VisuAlgo — visualizador interativo de algoritmos de ordenação:
  <https://visualgo.net/en/sorting>
- Big-O Cheat Sheet — referência de classes de complexidade:
  <https://www.bigocheatsheet.com>

### Uso de IA

A ferramenta utilizada foi o **Claude (Anthropic)**, empregada pela dupla como mentor
técnico. O uso descrito abaixo foi semelhante entre os dois integrantes.

A interação foi conduzida sob a instrução explícita de **não fornecer soluções prontas**:
explicar conceitos, decompor problemas, apontar erros de raciocínio e formular perguntas
que levassem à solução, em vez de entregar implementações. Todo o código deste projeto
foi escrito manualmente pela dupla.

**Explicação de conceitos.** Listas simplesmente e duplamente ligadas; listas circulares
e o compromisso entre elas; a diferença entre `t_node *` e `t_node **` e por que uma
função precisa de duplo ponteiro para redirecionar o ponteiro do chamador; a distinção
entre `stdout` e `stderr` e por que ela é funcional neste projeto; overflow de inteiros
com sinal como comportamento indefinido; o modelo de custo do subject, em que a
complexidade é medida em operações geradas e não em tempo de CPU. Também houve discussão
conceitual dos algoritmos disponíveis — insertion sort, bucket sort e radix sort — e da
razão de `√n` ser o tamanho ótimo de faixa no bucket sort.

**Revisão de código e apoio à depuração.** Revisões das funções escritas pela dupla, com
identificação de erros e discussão das causas, e apoio no diagnóstico de falhas durante o
desenvolvimento. Todas as correções foram implementadas pela dupla.

**Verificação final.** Execução de uma bateria de testes sobre o repositório: compilação
com as flags exigidas, validação com o `checker` em treze tamanhos distintos de entrada,
medição de desempenho das quatro estratégias, verificação de vazamentos de memória com
AddressSanitizer e teste de relink do Makefile.

**Redação desta documentação.** O texto deste README foi redigido com apoio da
ferramenta, a partir da leitura do código-fonte do projeto, e revisado pela dupla.

**Sem apoio de IA.** A implementação de todas as funções, a decisão de manter a lista
ligada não circular, a definição dos formatos de entrada aceitos e a integração entre os
módulos foram realizadas pela dupla.

---

## Contributions

Este projeto foi desenvolvido em dupla, conforme exigido pelo subject. A arquitetura
geral — estrutura de dados, organização dos módulos e divisão das responsabilidades — foi
discutida e decidida em conjunto pelos dois integrantes.

`jonbezer` implementou o recebimento e o tratamento dos parâmetros, incluindo o split dos
argumentos e todas as validações de entrada (`srcs/parser/`), bem como a estrutura de
dados das pilhas e seus utilitários (`srcs/utils/ft_stack_utils.c`). São dele também a
normalização por rank (`ft_assign_index.c`), a verificação de ordenação
(`ft_is_sorted.c`), o modo benchmark com os contadores por tipo de operação
(`ft_print_bench.c`) e o Makefile. No campo dos algoritmos, `jonbezer` implementou as
estratégias Simple, de complexidade O(n²), e Complex, de complexidade O(n log n).

`efeijo` implementou a métrica de desordem — o cálculo por contagem de inversões, a
representação em escala inteira e sua exibição formatada (`srcs/utils/ft_disorder.c`) — e
a estratégia Medium, de complexidade O(n√n), incluindo a distribuição por faixas de rank,
a extração em ordem decrescente e a escolha da rotação mais curta em cada sentido
(`srcs/algorithms/ft_medium_sort.c` e `ft_medium_sort_utils.c`).

Foram desenvolvidos em conjunto os módulos de infraestrutura compartilhada pelas três
estratégias: as onze operações do Push_swap (`srcs/operations/`), a seleção adaptativa por
regime de desordem (`ft_execute_strategy.c`) e a integração no ponto de entrada do
programa (`srcs/main.c`).

Ambos os integrantes revisaram o código um do outro ao longo do desenvolvimento e são
capazes de explicar e defender qualquer parte da implementação, incluindo os módulos que
não escreveram diretamente.
