/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:39:40 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/14 15:04:44 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_chr_set(char c, char *set)
{
	int	index;

	index = 0;
	while (set[index])
	{
		if (c == set[index])
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		indexc;
	int		indexd;
	char	*str;

	if (!set || !s1)
		return (NULL);
	indexc = 0;
	while (ft_check_chr_set(((char *)s1)[indexc], (char *)set) == 1
		&& s1[indexc])
		indexc++;
	indexd = ft_strlen(s1) - 1;
	while (ft_check_chr_set(((char *)s1)[indexd], (char *)set) == 1
		&& indexd > 0)
		indexd--;
	if (indexd == 0)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = malloc((indexd - indexc + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + indexc, indexd - indexc + 2);
	return (str);
}

/* int main()
{
	const char *s1 = "   xxx   xxx";
	const char *set = " x";
	char *ptr;

	ptr = ft_strtrim(s1, set);
	printf("%s\n", ptr);
	free(ptr);
} */
