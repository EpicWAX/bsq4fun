/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:29:13 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/17 15:50:31 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		slen;
	int		elen;
	int		flen;
	char	*trim;

	if (!s)
		return (NULL);
	slen = 0;
	if (ft_isblank(s[slen]) == 1 || s[slen] == '\n')
		while (ft_isblank(s[slen]) == 1 || s[slen] == '\n')
			slen++;
	elen = ft_strlen(s);
	if (slen == elen)
		return (ft_strdup(""));
	if (ft_isblank(s[elen - 1]) == 1 || s[elen - 1] == '\n')
		while (ft_isblank(s[elen - 1]) == 1 || s[elen - 1] == '\n')
			elen--;
	flen = (elen - slen);
	if (!(trim = ft_strnew(flen)))
		return (NULL);
	ft_strncpy(trim, s + slen, flen);
	return (trim);
}
