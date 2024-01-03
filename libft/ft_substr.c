/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:39:47 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/09 16:36:08 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup("\0"));
	if (ft_strlen(s + start) >= len)
	{
		dup = malloc((len + 1) * sizeof(char));
		if (dup == NULL)
			return (NULL);
		ft_strlcpy(dup, s + start, len + 1);
	}
	else
	{
		dup = malloc((ft_strlen(s + start) + 1) * sizeof(char));
		if (dup == NULL)
			return (NULL);
		ft_strlcpy(dup, s + start, ft_strlen(s + start) + 1);
	}
	return (dup);
}

/* int main()
{
	char const s[] = "tripouille";
	unsigned int start = 1;
	size_t len = 1;
	printf("Pour \"%s\" \n start vaut %d \n len vaut
		%zu \n on obtient : \"%s\"  sa longueur est %zu", s, start, len,
		ft_substr(s, start, len), ft_strlen(ft_substr(s, start, len)));
} */
