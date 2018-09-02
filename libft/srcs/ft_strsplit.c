/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:47:13 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/18 19:43:44 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		n_word(const char *s, char c)
{
	int n;
	int i;

	n = 0;
	i = 0;
	if (s && s[i] && s[i] != c)
	{
		while (s[i] && s[i] != c)
			i++;
		n++;
	}
	while (s && s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			n++;
		i++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	char				**tab;
	int					ti;
	unsigned int		start;
	int					len;
	int					nbw;

	ti = 0;
	start = 0;
	len = 0;
	nbw = n_word(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (nbw + 1))))
		return (NULL);
	while (ti < nbw)
	{
		while (s && s[start] && s[start] == c)
			start++;
		len = start;
		while (s && s[len] && s[len] != c)
			len++;
		tab[ti] = ft_strsub(s, start, (len - start));
		start = len;
		ti++;
	}
	tab[ti] = NULL;
	return (tab);
}
