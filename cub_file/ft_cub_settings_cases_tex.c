/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_cases_tex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:47:37 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/18 20:31:59 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static char	*ft_get_str(const char *str)
{
	const char	*ptr;

	str += 2;
	while (*str == ' ')
		str++;
	ptr = str;
	while (*ptr && *ptr != ' ')
		ptr++;
	return (ft_strndup(str, (ptr > str ? ptr - str : str - ptr)));
}

void		ft_cases_tex(t_vectors *v, const char *str)
{
	char	*s;

	if (!(s = ft_get_str(str)))
		ft_error("Could not duplicate str (ft_cases_str) (malloc)");
	if (*str == 'N' && str[1] == 'O')
		v->tex_files[0] = s;
	if (*str == 'S' && str[1] == 'O')
		v->tex_files[1] = s;
	if (*str == 'W' && str[1] == 'E')
		v->tex_files[2] = s;
	if (*str == 'E' && str[1] == 'A')
		v->tex_files[3] = s;
	if (*str == 'E' && str[1] == 'A')
		v->tex_files[4] = s;
	str += 2;
	while (*str == 32)
		str++;
	str += ft_strlen(s);
	while (*str && *str != ' ')
		str++;
	while (*str == 32)
		str++;
	if (*str)
		ft_error("Too many params given in a texture setting (cub file)");
}
