/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:13:27 by gschwand          #+#    #+#             */
/*   Updated: 2023/11/09 09:32:19 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	index;
	int	n;

	res = 0;
	index = 0;
	n = 0;
	while ((((char *)str)[index] >= 9 && ((char *)str)[index] <= 13)
		|| ((char *)str)[index] == 32)
		index++;
	if (((char *)str)[index] == '-')
	{
		n = 1;
		index++;
	}
	else if (((char *)str)[index] == '+')
		index++;
	while (((char *)str)[index] >= '0' && ((char *)str)[index] <= '9')
	{
		res = res * 10 + ((char *)str)[index] - 48;
		index++;
	}
	if (n != 0)
		res = res * -1;
	return (res);
}

/* int main()
{
	const char *nbr = "1";
	int res;

	res = ft_atoi(nbr);
	printf("%d\n", res);
	return (0);
} */