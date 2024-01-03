/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:40:48 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/09 15:49:13 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t			index;
	unsigned char	uns;

	uns = c;
	index = 0;
	while (s[index])
	{
		if (s[index] == uns)
			return ((char *)(s + index));
		else
			index++;
	}
	if (s[index] == c)
		return ((char *)s + index);
	return (NULL);
}
