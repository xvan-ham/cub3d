/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_read.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:15:47 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/29 17:49:30 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_cases(t_vectors *v, const char *str)
{
	while (*str == ' ')
		str++;
	if (*str == 0)
		return ;
	if (ft_strlen(str) < 2 && !ft_chars_in_str("012", str))
		ft_error("Cub file config info is invalid!");
	if (*str == 'R')
		ft_cases_res(v, str);
	if ((*str == 'N' && str[1] == 'O') || (*str == 'S' && str[1] == 'O') ||
		(*str == 'W' && str[1] == 'E') || (*str == 'E' && str[1] == 'A'))
		ft_cases_tex(v, str);
	else if (*str == 'S')
		ft_cases_sprite(v, str + 1);
	if (*str == 'F')
		ft_cases_floor(v, str + 1);
	if (*str == 'C')
		ft_cases_ceiling(v, str + 1);
}

void		ft_parse_line(t_vectors *v, const char *s, t_str_list **tmp_map,
	int *flag_map)
{
	if (!(*flag_map) && ft_chars_in_str("RNSWEFC", s))
		ft_check_cases(v, s);
	else if (ft_chars_in_str("012NSWE", s))
	{
		*flag_map = 1;
		ft_add_to_tmp_map(v, s, tmp_map);
		free((void *)s);
		return ;
	}
	free((void *)s);
}
