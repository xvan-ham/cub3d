/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:42:33 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/28 19:55:49 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putstr(const char *s)
{
	if (!s)
		ft_error(" received null pointer: ft_putstr");
	write(1, s, ft_strlen(s));
}
