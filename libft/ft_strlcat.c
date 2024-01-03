/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:40:57 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/09 17:45:31 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	lendst;
	size_t	lensrc;

	if (size == 0 && (dst == NULL || src == NULL))
		return (0);
	index = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	while (lendst < size && (index + lendst) < size - 1 && src[index])
	{
		dst[index + lendst] = (char)src[index];
		index++;
	}
	if (size < lendst)
		return (lensrc + size);
	if (size <= (lendst + lensrc))
		dst[index + lendst] = '\0';
	else
		dst[lendst + lensrc] = '\0';
	return (lendst + lensrc);
}

/* int main()
{
	char dst[30] = "BBBB\0";
	char const src[] = "AAAAAAAAA";

	printf("%zu\n", ft_strlcat(dst, src, 3));
	printf("%s\n", dst);
} */

/* {
	size_t index;
	size_t lendst;

	index = 0;
	if (src == NULL)
		return (0);
	lendst = ft_strlen(dst);
	if (size < 0)
		return (ft_strlen(src) + lendst);
	while (index < size - 1 && dst[lendst + index] && src[index])
	{
		dst[lendst + index] = src[index];
		index++;
	}
	dst[lendst + index] = '\0';
	if (size > lendst)
		return(ft_strlen(src) + lendst);
	return (ft_strlen(src) + size);
} */
