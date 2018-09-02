/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:03:20 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/16 15:55:39 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fs;
	int		i;

	if (!s || !f)
		return (NULL);
	fs = ft_strdup(s);
	i = 0;
	while (fs && fs[i])
	{
		fs[i] = f(fs[i]);
		i++;
	}
	return (fs);
}
