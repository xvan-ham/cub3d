/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cond.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:41:28 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/22 18:41:47 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_print_cond(const char *s, int flag)
{
	if (flag)
	{
		ft_putstr(s);
		ft_putstr("\n");
	}
}
