/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:59:02 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/17 19:06:45 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*ft_new_sprite(int x, int y)
{
	t_sprite	*sprite;

	if (!(sprite = malloc(sizeof(t_sprite))))
		ft_error("Not enough memory for sprite (malloc)");
	sprite->x = x + 0.5;
	sprite->y = y + 0.5;
	return (sprite);
}
