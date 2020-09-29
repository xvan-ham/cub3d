/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:43:19 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/28 19:55:49 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putnbr(double n, const char *base)
{
	int baselen;

	if (!base)
		ft_error(" received null pointer: ft_putnbr");
	baselen = ft_strlen(base);
	if (n >= baselen)
	{
		ft_putnbr(n / baselen, base);
		ft_putnbr((int)n % baselen, base);
	}
	else
		write(1, &base[(int)n], 1);
}
