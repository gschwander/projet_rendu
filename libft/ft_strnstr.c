/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:25:41 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/09 09:37:17 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ib;
	size_t	il;

	ib = 0;
	il = 0;
	if (!*little)
		return ((char *)big);
	while (ib < len && big[ib])
	{
		il = 0;
		while ((ib + il) < len && big[ib + il] == little[il])
		{
			il++;
			if (!little[il])
				return ((char *)(big + ib));
		}
		ib++;
	}
	return (NULL);
}

/* int	main(void)
{
	const char *big = "";
	const char *little = "";

	printf("%s\n", ft_strnstr(big, little, 0));
	return (0);
} */
