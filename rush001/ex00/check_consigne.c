/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_consigne.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:41:15 by rparodi           #+#    #+#             */
/*   Updated: 2023/08/12 19:41:19 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_line_consigne_right_left(int **pablo, int y, int *consigne)
{
	int	i;
	int	max;
	int	res;

	max = 0;
	res = 0;
	i = 3;
	while (i >= 0)
	{
		if (pablo[y][i] > max)
		{
			max = pablo[y][i];
			res++;
		}
		i--;
	}
	if (consigne[12 + y] != res)
		return (0);
	return (1);
}

int	ft_check_line_consigne(int **pablo, int y, int *consigne)
{
	int	i;
	int	max;
	int	res;

	max = 0;
	res = 0;
	i = 0;
	while (i < 4)
	{
		if (pablo[y][i] > max)
		{
			max = pablo[y][i];
			res++;
		}
		i++;
	}
	if (consigne[8 + y] != res)
		return (0);
	return (ft_check_line_consigne_right_left(pablo, y, consigne));
}

int	ft_check_col_consigne_down_top(int **pablo, int x, int *consigne)
{
	int	i;
	int	max;
	int	res;

	max = 0;
	res = 0;
	i = 3;
	while (i >= 0)
	{
		if (pablo[i][x] > max)
		{
			max = pablo[i][x];
			res++;
		}
		i--;
	}
	if (consigne[4 + x] != res)
		return (0);
	return (1);
}

int	ft_check_col_consigne(int **pablo, int x, int *consigne)
{
	int	i;
	int	max;
	int	res;

	max = 0;
	res = 0;
	i = 0;
	while (i < 4)
	{
		if (pablo[i][x] > max)
		{
			max = pablo[i][x];
			res++;
		}
		i++;
	}
	if (consigne[x] != res)
		return (0);
	return (ft_check_col_consigne_down_top(pablo, x, consigne));
}
