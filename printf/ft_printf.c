/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:44:58 by gschwand          #+#    #+#             */
/*   Updated: 2023/12/21 12:53:37 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char c, va_list ptr)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		i = ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
		i = ft_put_address(va_arg(ptr, void *));
	else if (c == 'd' || c == 'i')
		i = ft_putnbr(va_arg(ptr, int));
	else if (c == 'u')
		i = ft_putnbr_unsigned(va_arg(ptr, unsigned int));
	else if (c == 'x')
		i = ft_putnbr_hexal(va_arg(ptr, unsigned int));
	else if (c == 'X')
		i = ft_putnbr_hexau(va_arg(ptr, unsigned int));
	else if (c == '%')
		i = write(1, "%", 1);
	else
	{
		i = write(1, "%", 1);
		i += write(1, &c, 1);
	}
	return (i);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		vari;
	va_list	ptr;

	if (!string)
		return (-1);
	i = 0;
	vari = 0;
	va_start(ptr, string);
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1])
		{
			i++;
			vari += ft_type(string[i], ptr) - 2;
		}
		else if (string[i] == '%' && !string[i + 1])
			return (-1);
		else
			ft_putchar(string[i]);
		i++;
	}
	va_end(ptr);
	return (i + vari);
}
