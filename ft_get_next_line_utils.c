/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:36:29 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/02 20:34:32 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Function: char	char	*ft_strdup(const char *src)
** Allocates sufficient memory for a freeable copy of the string
** 'src', does the copy, and returns a pointer to it.
** Copies full length of string 'src' always NUL terminating the copied string.
*/

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*ptr;

	if (!(str = malloc(ft_strlen((char *)src) + 1)))
		return (0);
	ptr = str;
	while (*src)
		*(ptr++) = *(src++);
	*ptr = 0;
	return (str);
}

/*
** Function: char	*ft_strjoin(char const *s1, char const *s2)
** Allocates sufficient memory for the new freeable string which
** will be the concatenation of 's2' to 's1' always NUL terminating
** the copied string. Works with NULL pointers, only if both are
** NULL pointers will the function return a NULL pointer.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*str;
	char	*wrptr;
	char	*rptr;

	if ((!s1 && !s2))
		return (0);
	s1len = s1 ? ft_strlen(s1) : 0;
	s2len = s2 ? ft_strlen(s2) : 0;
	str = malloc(s1len + s2len + 1);
	if (!str)
		return (0);
	wrptr = str;
	rptr = (char *)s1;
	while (rptr && *rptr)
		*(wrptr++) = *(rptr++);
	rptr = (char *)s2;
	while (rptr && *rptr)
		*(wrptr++) = *(rptr++);
	*wrptr = 0;
	return (str);
}