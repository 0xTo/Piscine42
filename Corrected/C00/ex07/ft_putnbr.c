/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheoM-e <marvin@42.fr>                      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/00/00 00:00:00 by TheoM-e            #+#    #+#            */
/*   Updated: 2022/00/00 00:00:00 by TheoM-e           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_impl(int nb)
{
	char	c;

	if (nb < 0)
	{
		putchar('-');
		nb = -nb;
	}
	if (0 == nb)
		return ;
	ft_putnbr_impl(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (-2147483648 == nb)
		write(1, "-2147483648", 11);
	else if (0 == nb)
		write(1, "0", 1);
	else
		ft_putnbr_impl(nb);
}
