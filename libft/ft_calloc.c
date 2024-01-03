/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:38:45 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/13 11:24:58 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	nb;

	if (count == 0 || size == 0)
		return (ft_strdup("\0"));
	nb = count * size;
	if (nb / count != size)
		return (NULL);
	ptr = malloc(nb);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nb);
	return (ptr);
}
