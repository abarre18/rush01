/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:34:27 by rparodi           #+#    #+#             */
/*   Updated: 2023/08/12 19:34:42 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_line_consigne(int **pablo, int y, int *consigne);
int	ft_check_col_consigne(int **pablo, int x, int *consigne);

int	ft_check_line(int **pablo, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != x)
			if (pablo[y][x] == pablo[y][i])
				return (0);
		i++;
	}
	return (1);
}

int	ft_check_col(int **pablo, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != y)
			if (pablo[y][x] == pablo[i][x])
				return (0);
		i++;
	}
	return (1);
}

int	ft_is_valid(int **pablo, int x, int y, int *consigne)
{
	if (!ft_check_line(pablo, x, y))
		return (0);
	if (!ft_check_col(pablo, x, y))
		return (0);
	if (x == 3)
		if (!ft_check_line_consigne(pablo, y, consigne))
			return (0);
	if (y == 3)
		if (!ft_check_col_consigne(pablo, x, consigne))
			return (0);
	return (1);
}
