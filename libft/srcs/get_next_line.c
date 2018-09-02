/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:05:06 by qhusler           #+#    #+#             */
/*   Updated: 2016/12/11 13:29:11 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freejoin(char *s1, char *s2)
{
	char	*s;

	if (!(s = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(s, s1);
	ft_strdel(&s1);
	ft_strncat(s, s2, ft_strlen(s2));
	ft_strclr(s2);
	return (s);
}

int		line_load(char **line, char **s)
{
	char *tmp;
	char *nl;

	nl = ft_strchr(*s, '\n');
	if (nl)
	{
		*line = ft_strsub(*s, 0, nl - *s);
		tmp = ft_strsub(*s, (nl - *s + 1), ft_strlen(*s));
		ft_strdel(s);
		*s = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (1);
	}
	if (ft_strlen(*s) > 0)
	{
		*line = ft_strdup(*s);
		ft_strclr(*s);
		return (1);
	}
	return (0);
}

t_list	*find_fd(t_list **list, const int fd)
{
	t_list	*elem;

	elem = *list;
	if (elem)
		while (elem)
		{
			if ((int)elem->content_size == fd)
				return (elem);
			elem = elem->next;
		}
	elem = ft_lstnew("\0", 1);
	elem->content_size = fd;
	ft_lstadd(list, elem);
	return (elem);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*link;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	link = find_fd(&list, fd);
	while (!ft_strchr(link->content, '\n'))
	{
		ret = read(fd, &buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (line_load(line, (char**)&link->content));
		buf[ret] = '\0';
		link->content = ft_freejoin(link->content, buf);
	}
	return (line_load(line, (char**)&link->content));
}
