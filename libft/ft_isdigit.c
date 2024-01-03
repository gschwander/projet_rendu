/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:40:02 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/09 09:42:50 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (ft_isascii(c) == 0)
		return (0);
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}