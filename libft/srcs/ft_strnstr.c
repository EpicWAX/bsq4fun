/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:33:35 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/19 20:45:29 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t i;
	size_t len;

	if (little[0] == '\0' || ft_strcmp(big, little) == 0)
		return ((char*)big);
	i = 0;
	len = ft_strlen(little);
	while (big[i] && i < n)
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(big + i, little, len) == 0 && i + len < n)
				return ((char*)big + i);
		}
		i++;
	}
	return (NULL);
}
