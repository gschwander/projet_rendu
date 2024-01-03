/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:39:23 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/09 16:41:54 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;
	unsigned int	nb;

	if (!s)
		return ;
	nb = 0;
	index = 0;
	while (s[index])
	{
		(*f)(nb, s);
		nb++;
		s++;
	}
}
