#include "push_swap.h"
#include <stdio.h> // Apenas para os printf's de teste!

static void	ft_debug_print_stack(t_stack *stack)
{
	t_node	*curr;

	printf("--- ESTADO DA PILHA A ---\n");
	printf("Tamanho (size): %zu\n", stack->size);
	if (stack->head)
		printf("Topo (head): %d\n", stack->head->value);
	if (stack->tail)
		printf("Fundo (tail): %d\n", stack->tail->value);
	
	printf("Elementos (head -> tail): ");
	curr = stack->head;
	while (curr)
	{
		printf("[%d] ", curr->value);
		curr = curr->next;
	}
	printf("\n-------------------------\n");
}

static void	ft_debug_print_config(t_config *config)
{
	printf("--- CONFIGURAÇÃO ---\n");
	printf("Estratégia: %d (0:ADAPTIVE, 1:SIMPLE, 2:MEDIUM, 3:COMPLEX)\n", config->strategy);
	printf("Modo Bench: %s\n", config->bench ? "ATIVO" : "DESATIVADO");
	printf("--------------------\n");
}

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_config	config;
	int			disorder;

	if (argc < 2)
		return (0);
	stack_a.head = NULL;
	stack_a.tail = NULL;
	stack_a.size = 0;
	config.strategy = STRAT_ADAPTIVE;
	config.bench = 0;

	if (!ft_parse_args(argc, argv, &stack_a, &config))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (stack_a.size == 0)
		return (0);

	/* PRINTS DE TESTE (Remover antes de entregar!) */
	ft_debug_print_config(&config);
	ft_debug_print_stack(&stack_a);

	disorder = ft_compute_disorder(&stack_a);
	printf("Desordem calculada: %d (em escala 0-10000)\n", disorder);
	ft_print_disorder(disorder, 1); // Testando a função no stdout (fd 1)

	ft_clear_stack(&stack_a);
	return (0);
}
