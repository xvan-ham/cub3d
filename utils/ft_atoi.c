/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:44:40 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/16 19:52:38 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *string)
{
	int	sign;
	int	total;

	sign = 1;
	total = 0;
	while (*string == 32 || (*string > 8 && *string < 14))
		string++;
	if (*string == '-')
		sign *= -1;
	if (*string == '-' || *string == '+')
		string++;
	while (*string && *string >= 48 && *string <= 57)
		total = total * 10 + (*(string++) - '0');
	return (total * sign);
}
