/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:44:20 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/18 20:59:08 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;
	void	*c;

	if (!(c = (void*)ft_memalloc(content_size)))
		return (NULL);
	if (content == NULL)
	{
		c = NULL;
		content_size = 0;
	}
	else
		c = ft_memcpy(c, content, content_size);
	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	lst->content = c;
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}
