/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwand <gschwand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:43:01 by gautier           #+#    #+#             */
/*   Updated: 2023/12/21 10:59:55 by gschwand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
t_list				*ft_lstnew_n_addfront(char *content, t_list *elem);
t_list				*ft_read_alloc(int fd, char *rest, t_list *elem);
char				*ft_alloc_buf(t_list *elem, char *buf);
char				*ft_strjoin_gnl(char *s1, char *s2, size_t len);
char				*ft_strlcpy(char *dst, char *str, size_t len);
int					ft_strlen(char *str);
char				*ft_write(t_list **linked_list, t_list *elem);
void				ft_lstclear(t_list **lst, void (*del)(void *));

#endif
