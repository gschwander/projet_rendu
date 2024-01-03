/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:45:05 by gschwand          #+#    #+#             */
/*   Updated: 2023/12/21 12:29:32 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	ft_type(char c, va_list ptr);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_put_address(void *ptr);
int	ft_putnbr(int nbr);
int	ft_putnbr_unsigned(unsigned int nbr);
int	ft_putnbr_hexal(unsigned int nbr);
int	ft_putnbr_hexau(unsigned int nbr);
int	ft_put_p(unsigned long nbr);

#endif