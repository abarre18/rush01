/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:30:38 by rparodi           #+#    #+#             */
/*   Updated: 2023/08/12 19:38:19 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_is_valid(int **pablo, int x, int y, int *consigne);
int		is_valid_input(char *str);
int		*split_and_convert(char *str);
void	print_pablo(int **pablo, int side_len);

int	ft_solver(int **pablo, int x, int y, int *consigne)
{
	int	i;
	int	res;

	i = 1;
	if (y == 4)
	{
		print_pablo(pablo, 4);
		return (1);
	}
	while (i <= 4)
	{
		pablo[y][x] = i;
		if (ft_is_valid(pablo, x, y, consigne))
		{
			if (x < 3)
				res = ft_solver(pablo, x + 1, y, consigne);
			else
				res = ft_solver(pablo, 0, y + 1, consigne);
			if (res)
				return (1);
		}
		i++;
	}
	pablo[y][x] = 0;
	return (0);
}

int	**ft_init_pablo(void)
{
	int	i;
	int	**pablo;

	i = 0;
	pablo = (int **) malloc(sizeof(int *) * 4);
	if (!pablo)
		return (NULL);
	while (i < 4)
	{
		pablo[i] = (int *) malloc(sizeof(int) * 4);
		if (!pablo[i])
			return (NULL);
		i++;
	}
	return (pablo);
}

void	liberez_tous_mes_copains(int **pablo)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(pablo[i]);
		i++;
	}
	free(pablo);
}

int	main(int argc, char *argv[])
{
	int	*converted;
	int	**pablo;
	int	res;

	pablo = ft_init_pablo();
	if (argc == 2)
	{
		if (is_valid_input(argv[1]))
		{
			converted = split_and_convert(argv[1]);
			if (converted != NULL)
			{
				res = ft_solver(pablo, 0, 0, converted);
				if (!res)
					write(1, "Error\n", 6);
				liberez_tous_mes_copains(pablo);
				return (0);
			}
		}
	}
	liberez_tous_mes_copains(pablo);
	write(1, "Error\n", 6);
	return (0);
}
