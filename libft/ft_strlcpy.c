/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:41:01 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/09 15:50:36 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (index < size - 1 && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (ft_strlen((char *)src));
}

/* int main()
{
	const char *src = "coucou";
	char dst[10] = "AAAAAAAAAA";

	printf("Pour \"%s\" \n on a strlen qui vaut :%zu\ndst : %s\n", src,
		ft_strlcpy(dst, src, 1), dst + 1);
} */
