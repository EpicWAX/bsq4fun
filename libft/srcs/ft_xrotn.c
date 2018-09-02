/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xrotn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:07:11 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/19 13:08:20 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_xrotn(char *s, int n)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(s);
	i = -1;
	while (tmp && tmp[++i])
	{
		if (tmp[i] > 64 && tmp[i] < 91)
			tmp[i] = ((tmp[i] - 65 + n) % 26 + 65);
		if (tmp[i] > 96 && tmp[i] < 123)
			tmp[i] = ((tmp[i] - 97 + n) % 26 + 97);
	}
	i = -1;
	while (tmp && tmp[++i])
	{
		if (tmp[i] > 64 && tmp[i] < 91)
			tmp[i] = 'Z' - tmp[i] + 'A';
		if (tmp[i] > 96 && tmp[i] < 127)
			tmp[i] = 'z' - tmp[i] + 'a';
	}
	tmp[i] = '\0';
	return (tmp);
}
