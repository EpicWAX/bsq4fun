/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:09:42 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/13 13:29:28 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;

	i = -1;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[++i])
		if (big[i] == little[0])
			if (ft_strncmp(big + i, little, ft_strlen(little)) == 0)
				return ((char*)big + i);
	return (NULL);
}
