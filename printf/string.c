/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:50:26 by gschwand          #+#    #+#             */
/*   Updated: 2023/12/21 12:54:02 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_put_address(void *ptr)
{
	int	i;

	if (!ptr)
		return (write(1, "(nil)", 5));
	i = write(1, "0x", 2);
	i += ft_put_p((unsigned long)ptr);
	return (i);
}

int	ft_put_p(unsigned long nbr)
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
	i += ft_put_p(nbr / 16);
	i += ft_putchar(hexal[nbr % 16]);
	return (i);
}
