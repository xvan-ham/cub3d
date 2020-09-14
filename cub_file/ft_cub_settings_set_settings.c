/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_set_settings.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:35:24 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/14 19:25:52 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_check_config(t_vectors *v, const char *c)
{
	if ((ft_chars_in_str("012NSWE", c)))
		return ;

}