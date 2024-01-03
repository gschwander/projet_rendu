/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:32:07 by gschwand          #+#    #+#             */
/*   Updated: 2023/12/21 11:29:05 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstnew_n_addfront(char *content, t_list *elem)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (ft_lstclear(&elem, free), free(content), NULL);
	new->content = content;
	if (!elem)
		new->next = NULL;
	else
		new->next = elem;
	return (new);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(del)((*lst)->content);
		free(*lst);
		(*lst) = tmp;
	}
	*lst = NULL;
}

char	*ft_alloc_buf(t_list *elem, char *buf)
{
	char	*rest;
	char	*content;
	int		i;

	i = 0;
	content = NULL;
	rest = NULL;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			content = ft_strjoin_gnl(content, buf, i + 1);
			elem->content = content;
			if (i != ft_strlen(buf))
				rest = ft_strjoin_gnl(rest, buf + i + 1, ft_strlen(buf + i)
						- 1);
			free(buf);
			return (rest);
		}
		i++;
	}
	content = ft_strjoin_gnl(content, buf, ft_strlen(buf));
	elem->content = content;
	free(buf);
	return (rest);
}

t_list	*ft_read_alloc(int fd, char *rest, t_list *elem)
{
	char	*buf;
	int		n;

	buf = NULL;
	if (rest)
		buf = rest;
	rest = NULL;
	while (rest == NULL)
	{
		if (buf == NULL)
		{
			buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
			if (buf == NULL)
				return (NULL);
			n = read(fd, buf, BUFFER_SIZE);
			if (n <= 0)
				return (free(buf), elem);
			buf[n] = 0;
		}
		rest = ft_alloc_buf(elem, buf);
		elem = ft_lstnew_n_addfront(rest, elem);
		buf = NULL;
	}
	return (elem);
}
