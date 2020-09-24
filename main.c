/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 20:10:45 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/24 20:27:20 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_cubfile(char *s)
{
	if (!s)
		return (1);
	if (ft_strlen(s) < 4)
	{
		ft_putstr("Invalid cub file name");
		return (1);
	}
	s += ft_strlen(s) - 4;
	if (!ft_strstr(s, ".cub"))
	{
		ft_putstr("Error. First argument is not a .cub file\n");
		return (1);
	}
	return (0);
}

static int	ft_check_save_flag(char *s, int *save_flag)
{
	if (!s)	
		return (1);
	if (!ft_strstr(s, "--save"))
	{
		ft_putstr("Error. Unknown argument. Did you mean --save?");
		return (1);
	}
	*save_flag = 1;
	return (0);
	
}

int	main(int argc, char **argv)
{
	int	err;
	int	save_flag;

	save_flag = 0;
	err = 0;
	if (argc < 2)
		ft_putstr("Error: Not enough arguments.\n");
	if (argc > 3)
		ft_putstr("Error: Too many arguments.\n");
	if (argc < 2 || argc > 3)
		return (0);
	err = ft_check_cubfile(argv[1]);
	if (err)
		return (0);
	if (argc == 3)
		err = ft_check_save_flag(argv[2], &save_flag);
	if (err)
		return (0);
	ft_cub3d(argv[1], save_flag);
	return (0);
}
