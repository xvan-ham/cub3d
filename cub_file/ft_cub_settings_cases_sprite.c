/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_cases_sprite.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:15:36 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/16 19:51:00 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static char	*ft_get_str(const char *str)
{
	const char	*ptr;

	while (*str == ' ')
		str++;
	ptr = str;
	while (*ptr && *ptr != ' ')
		ptr++;
	return (ft_strndup(str, (ptr > str ? ptr - str : str - ptr)));
}

void		ft_cases_sprite(t_vectors *v, const char *str)
{
	v->tex_files[4] = ft_get_str(str);
	while (*str == 32)
		str++;
	str += ft_strlen(ft_get_str(str));
	while (*str && *str != ' ')
		str++;
	while (*str == 32)
		str++;
	if (*str)
		ft_error("Too many params given in the sprite setting (cub file)");
}
