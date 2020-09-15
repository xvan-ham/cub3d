/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:43:49 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/15 18:40:09 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_error(char *s)
{
	ft_putstr("\nFatal Error: ");
	if (s)
		ft_putstr(s);
	ft_putstr("\n");
	exit(1);
}
