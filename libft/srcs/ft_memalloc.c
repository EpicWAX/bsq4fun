/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:48:03 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/17 11:41:59 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*var;

	if (!(var = (void*)malloc(sizeof(*var) * size)))
		return (NULL);
	var = ft_memset(var, 0, size);
	return (var);
}
