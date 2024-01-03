/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:34:05 by gschwand          #+#    #+#             */
/*   Updated: 2023/12/21 11:03:38 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strlcpy(char *dst, char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && str[i])
	{
		dst[i] = str[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin_gnl(char *s1, char *s2, size_t len)
{
	char	*str;
	int		lens1;

	if (!s1)
		lens1 = 0;
	else
		lens1 = ft_strlen(s1);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (!s1)
	{
		ft_strlcpy(str, s2, len);
		str[len] = 0;
		return (str);
	}
	ft_strlcpy(str, s1, len);
	ft_strlcpy(str + lens1, s2, len - lens1);
	str[len] = 0;
	return (str);
}

char	*ft_write(t_list **linked_list, t_list *elem)
{
	char	*line;
	int		lenline;

	lenline = 0;
	while (elem)
	{
		lenline = lenline + ft_strlen(elem->content);
		elem = elem->next;
	}
	line = malloc((lenline + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	line[lenline] = 0;
	elem = *linked_list;
	while (elem)
	{
		lenline = lenline - ft_strlen(elem->content);
		ft_strlcpy(line + lenline, elem->content, ft_strlen(elem->content));
		elem = elem->next;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	t_list		*elem;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(rest), NULL);
	elem = ft_lstnew_n_addfront(NULL, NULL);
	elem = ft_read_alloc(fd, rest, elem);
	rest = elem->content;
	elem->content = NULL;
	line = ft_write(&(elem->next), elem->next);
	if (!*line)
		return (ft_lstclear(&elem, free), free(line), free(rest), NULL);
	return (ft_lstclear(&elem, free), line);
}
