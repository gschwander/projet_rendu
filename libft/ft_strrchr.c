/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:41:18 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/09 09:50:23 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				index;
	unsigned char	uns;

	uns = c;
	index = ft_strlen((char *)s);
	if (s == NULL)
		return (0);
	while (index >= 0)
	{
		if (s[index] == uns)
			return ((char *)s + index);
		else
			index--;
	}
	return (NULL);
}
