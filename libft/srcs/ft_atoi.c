/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:46:09 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/11 11:05:42 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int ret;
	int sign;
	int	i;

	ret = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(s[i]) == 1)
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		ret = ret * 10 + (s[i] - '0');
		i++;
	}
	return (ret * sign);
}
