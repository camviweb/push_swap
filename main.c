#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	a;
	int	b;
	int	c;

	i = 1;
	if (argc == 3)
	{
		while (i < argc)
		{
		}
	}
    if (argc == 4)
	{
		while (i < argc)
		{
		}
	}
	while (i < argc)
	{
		ft_printf("%d", ft_atoi(argv[i++]));
	}
}

// Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
void	swapa(void)
{
	ft_printf("\nsa");
}

// Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
void	swapb(void)
{
	ft_printf("\nsb");
}

void	ss(void)
{
	swapa();
	swapb();
	ft_printf("\nss");
}

// Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
void	pusha(void)
{
	ft_printf("\npa");
}

// Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
void	pushb(void)
{
	ft_printf("\npb");
}

// Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
void	rotatea(void)
{
	ft_printf("\nra");
}

// Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
void	rotateb(void)
{
	ft_printf("\nrb");
}

void	rr(void)
{
	rotatea(); // issue, affichage 
	rotateb();
	ft_printf("\nrr");
}

// Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
void	reverserotatea(void)
{
	ft_printf("\nrra");
}

// Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.
void	reverserotateb(void)
{
	ft_printf("\nrrb");
}

void	rrr(void)
{
	reverserotatea();
	reverserotateb();
	ft_printf("\nrrr");
}
