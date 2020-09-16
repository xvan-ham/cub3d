/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_cases.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:23:32 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/16 16:46:11 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_sort_res_cases(t_vectors *v, int width, int height)
{
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
		ft_error("Too many params given in the resolution setting (cub file)");
	v->screen_h = height;
	v->screen_w = width;
	ft_sort_res_cases(v, width, height);
}
