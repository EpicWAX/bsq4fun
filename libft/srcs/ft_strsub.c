/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:55:13 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/10 14:38:37 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	int		i;

	i = 0;
	if (!(ns = ft_strnew(len)))
		return (NULL);
	while (s && s[start] && len--)
	{
		ns[i] = s[start];
		i++;
		start++;
	}
	ns[i] = '\0';
	return (ns);
}
