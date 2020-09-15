/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_read.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:15:47 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/15 20:37:24 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static char	*ft_adv_spc(const char *str)
{
	return (0);
}

void		ft_cases_res(t_vectors *v, const char *str)
{
	int width;
	int	height;

	width = ft_atoi(++str);
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	while (*str == '-' || *str == '+' || (*str >= '0' && *str <= '9'))
		str++;
	if (!ft_chars_in_str("0123456789", str))
		ft_error("Cub file config resolution info is invalid!");
	height = ft_atoi(str);
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	while (*str == '-' || *str == '+' || (*str >= '0' && *str <= '9'))
		str++;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str)
		ft_error("Cub file config resolution info is invalid! Too many params given");
	v->screen_h = height;
	v->screen_w = width;
	if (height > SCREEN_HEIGHT_UL)
	{
		ft_putstr("Screen height res too low, using minimum val\n");
		v->screen_h = SCREEN_HEIGHT_UL;
	}
	if (height < SCREEN_HEIGHT_LL)
	{
		ft_putstr("Screen height res too high, using max val\n");
		v->screen_h = SCREEN_HEIGHT_LL;
	}
	if (width > SCREEN_WIDTH_UL)
	{
		ft_putstr("Screen height res too low, using minimum val\n");
		v->screen_w = SCREEN_WIDTH_UL;
	}
	if (width < SCREEN_WIDTH_LL)
	{
		ft_putstr("Screen height res too high, using max val\n");
		v->screen_w = SCREEN_WIDTH_LL;
	}
}

void		ft_cases_texture(t_vectors *v, const char *str)
{

}

void		ft_cases_sprite(t_vectors *v, const char *str)
{

}

void		ft_cases_floor(t_vectors *v, const char *str)
{

}

void		ft_cases_ceiling(t_vectors *v, const char *str)
{

}

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
		ft_cases_texture(v, str);
	if (*str == 'S')
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
	//start map reading section
	else if (ft_chars_in_str("012NSWE", s))
	{
		*flag_map = 1;
		ft_add_to_tmp_map(v, s, tmp_map);
		free((void *)s);
		return ;
	}
	if (*flag_map)
	{
		ft_error("Invalid map, don't add empty lines to map!!");
		free((void *)s);
	}
	//end of map reading section
}