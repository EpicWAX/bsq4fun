/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:24:43 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/08 14:46:37 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	if (!(new = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = 0;
		i++;
	}
	new[i] = '\0';
	return (new);
}
