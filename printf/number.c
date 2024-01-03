/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:50:22 by gschwand          #+#    #+#             */
/*   Updated: 2023/12/21 12:29:42 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		i = write(1, "-2", 2);
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		i = write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr < 10)
	{
		i += ft_putchar(nbr % 10 + '0');
		return (i);
	}
	i += ft_putnbr(nbr / 10);
	i += ft_putchar(nbr % 10 + '0');
	return (i);
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr < 10)
	{
		i = ft_putchar(nbr % 10 + '0');
		return (i);
	}
	i += ft_putnbr_unsigned(nbr / 10);
	i += ft_putchar(nbr % 10 + '0');
	return (i);
}

int	ft_putnbr_hexal(unsigned int nbr)
{
	int		i;
	char	*hexal;

	i = 0;
	hexal = "0123456789abcdef";
	if (nbr < 16)
	{
		i = ft_putchar(hexal[nbr % 16]);
		return (i);
	}
	i += ft_putnbr_hexal(nbr / 16);
	i += ft_putchar(hexal[nbr % 16]);
	return (i);
}

int	ft_putnbr_hexau(unsigned int nbr)
{
	int		i;
	char	*hexal;

	i = 0;
	hexal = "0123456789ABCDEF";
	if (nbr < 16)
	{
		i = ft_putchar(hexal[nbr % 16]);
		return (i);
	}
	i += ft_putnbr_hexau(nbr / 16);
	i += ft_putchar(hexal[nbr % 16]);
	return (i);
}
