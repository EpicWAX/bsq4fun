/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:05:31 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/13 13:24:17 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fs;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(fs = ft_strdup(s)))
		return (NULL);
	while (s && s[i])
	{
		fs[i] = f(i, fs[i]);
		i++;
	}
	return (fs);
}
