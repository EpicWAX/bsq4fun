/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:36:10 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/18 17:33:01 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*d;
	const char		*s;
	unsigned int	dstlen;
	size_t			n;

	d = dst;
	n = size;
	s = src;
	while (*d != '\0' && n-- != 0)
		d++;
	dstlen = d - dst;
	n = size - dstlen;
	if (n == 0)
		return (dstlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dstlen + (s - src));
}
