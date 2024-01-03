/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:39:00 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/14 15:06:00 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(int n)
{
	int	lenint;

	lenint = 0;
	while (n > 9)
	{
		n = n / 10;
		lenint++;
	}
	return (lenint);
}

static char	*ft_itoa_neg(int n)
{
	int		lenint;
	char	*nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n = n * -1;
	lenint = ft_len_int(n) + 1;
	nbr = malloc((lenint + 2) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	nbr[0] = '-';
	nbr[lenint + 1] = '\0';
	while (lenint > 0)
	{
		nbr[lenint] = n % 10 + 48;
		n = n / 10;
		lenint--;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	int		lenint;
	char	*nbr;

	if (n < 0)
	{
		nbr = ft_itoa_neg(n);
		return (nbr);
	}
	lenint = ft_len_int(n);
	nbr = malloc((lenint + 2) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	nbr[lenint + 1] = '\0';
	while (lenint >= 0)
	{
		nbr[lenint] = n % 10 + 48;
		n = n / 10;
		lenint--;
	}
	return (nbr);
}

/* int main()
{
	int nbr = -2147483648;
	char *ptr;
	ptr = ft_itoa(nbr);
	printf("\"%s\"\nstrlen : %zu\n", ptr, ft_strlen(ptr));
	free(ptr);
	return (0);
} */
