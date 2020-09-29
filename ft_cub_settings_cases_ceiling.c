/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_cases_ceiling.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:23:57 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/28 19:55:43 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_cases_ceiling(t_vectors *v, const char *str)
{
	(v->sky)->r = ft_atoi(str);
	while (*str == ' ')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != ',')
		ft_error("Invalid syntax for floor-color setting (cub file)");
	while (*(str + 1) == ' ')
		str++;
	(v->sky)->g = ft_atoi(++str);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != ',')
		ft_error("Invalid syntax for floor-color setting (cub file)");
	while (*(str + 1) == ' ')
		str++;
	(v->sky)->b = ft_atoi(++str);
}
