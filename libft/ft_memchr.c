/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:40:19 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/09 09:48:18 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uns;
	size_t			index;

	uns = c;
	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == uns)
			return ((unsigned char *)(s + index));
		else
			index++;
	}
	return (NULL);
}
