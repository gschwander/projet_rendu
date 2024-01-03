/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:39:19 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/14 15:05:27 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_chr_chr(char c, char set)
{
	if (c == set)
		return (1);
	else
		return (0);
}

static int	ft_countword(const char *s, char c)
{
	int	index;
	int	word;
	int	letter;

	index = 0;
	letter = 0;
	word = 0;
	while (index == 0 || s[index - 1])
	{
		if ((ft_check_chr_chr(s[index], c) == 1 || !s[index]) && letter > 0)
		{
			word++;
			letter = 0;
		}
		else if (ft_check_chr_chr(s[index], c) == 0)
			letter++;
		index++;
	}
	return (word);
}

static int	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	return (0);
}

static int	ft_alloc_words(const char *s, char c, char **tab)
{
	int	index;
	int	word;
	int	letter;

	index = 0;
	letter = 0;
	word = 0;
	while (index == 0 || s[index - 1])
	{
		if ((ft_check_chr_chr(s[index], c) == 1 || !s[index]) && letter > 0)
		{
			tab[word] = malloc((letter + 1) * sizeof(char));
			if (tab[word] == NULL)
				return (ft_free(tab));
			ft_strlcpy(tab[word], s + index - letter, letter + 1);
			word++;
			letter = 0;
		}
		else if (ft_check_chr_chr(s[index], c) == 0)
			letter++;
		index++;
	}
	tab[word] = NULL;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		countword;
	char	**tab;

	if (!s)
		return (NULL);
	countword = ft_countword(s, c);
	tab = malloc((countword + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	ft_alloc_words(s, c, tab);
	return (tab);
}
/* int main()
{
	const char *s = "  tripouille  42  ";
	char c = ' ';
	char **tab;
	int i = 0;

	tab = ft_split(s, c);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free (tab[i]);
		i++;
	}
} */
