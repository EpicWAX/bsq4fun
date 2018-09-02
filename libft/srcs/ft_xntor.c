/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xntor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:08:29 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/19 13:09:14 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_xntor(char *s, int n)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(s);
	i = -1;
	while (tmp && tmp[++i])
	{
		if (tmp[i] > 64 && tmp[i] < 91)
			tmp[i] = 'A' - tmp[i] + 'Z';
		if (tmp[i] > 96 && tmp[i] < 127)
			tmp[i] = 'a' - tmp[i] + 'z';
	}
	i = -1;
	while (tmp && tmp[++i])
	{
		if (tmp[i] > 64 && tmp[i] < 91)
			tmp[i] = ((tmp[i] - 90 - n) % 26 + 90);
		if (tmp[i] > 96 && tmp[i] < 123)
			tmp[i] = ((tmp[i] - 122 - n) % 26 + 122);
	}
	tmp[i] = '\0';
	return (tmp);
}
