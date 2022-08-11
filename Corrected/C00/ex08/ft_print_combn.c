/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheoM-e <marvin@42.fr>                      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/00/00 00:00:00 by TheoM-e            #+#    #+#            */
/*   Updated: 2022/00/00 00:00:00 by TheoM-e           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	inc_digit(int comb[], int *i, int n)
{
	int	actual_dig;
	int	x;
	int	max;

	max = 10;
	x = 0;
	while (x < n)
	{
		ft_putchar(comb[x] + '0');
		x++;
	}
	*i = n;
	while ((*i)--)
	{
		actual_dig = comb[*i];
		if (actual_dig < --max)
		{
			while (*i < n)
				comb[(*i)++] = ++actual_dig;
			ft_putchar(',');
			ft_putchar(' ');
			break ;
		}
	}	
}

void	ft_print_combn(int n)
{
	int	comb[9];
	int	i;

	i = 0;
	if (n <= 0 || n >= 10)
	{
		return ;
	}
	while (i < n)
	{
		comb[i] = i;
		i++;
	}
	while (i > 0)
	{
		inc_digit(comb, &i, n);
	}
}
