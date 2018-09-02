/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:16:18 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/18 19:42:26 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sizeof_int(int n)
{
	int i;

	i = (n < 0) ? 2 : 1;
	while ((n /= 10) != 0)
		i++;
	return (i);
}

static int		ft_abs(int n)
{
	return ((n < 0) ? n * -1 : n);
}

char			*ft_itoa(int n)
{
	int		i;
	int		absn;
	char	*s;

	absn = ft_abs(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = sizeof_int(n);
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	while ((n < 0) ? i > 1 : i > 0)
	{
		s[i - 1] = absn % 10 + '0';
		absn /= 10;
		i--;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
