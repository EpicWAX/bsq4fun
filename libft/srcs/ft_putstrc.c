/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:35:53 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/19 11:52:50 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrc(char *s_color, char *s_printable, char *s_color_stop)
{
	if (ft_strncmp(s_color, "\x1b[38;5;", 7) == 0)
		ft_putstr(s_color);
	else
		return (ft_putstr(s_printable));
	ft_putstr(s_printable);
	return (ft_putstr(s_color_stop));
}
