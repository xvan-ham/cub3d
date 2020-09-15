/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:36:13 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/15 17:39:25 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		ft_strlen(const char *s)
{
	int len;

	len = 0;
	if (!s)
		ft_error(" received null pointer: ft_strlen");
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (0);
}

char	*ft_strndup(const char *src, size_t chars)
{
	char	*str;
	char	*strptr;

	if (!src)
		return (0);
	if (!(str = malloc((chars + 1) * sizeof(char))))
		return (0);
	strptr = str;
	while (*src && chars--)
		*(strptr++) = *(src++);
	*strptr = 0;
	return (str);
}

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;

	while (*s1 && (s1 = ft_strchr(s1, *s2)))
	{
		i = 0;
		while (*(s2 + i))
		{
			if (*(s1 + i) != *(s2 + i))
				break ;
			i++;
		}
		if (*(s2 + i) == 0)
			return ((char *)s1);
		s1++;
	}
	return (0);
}

char	*ft_chars_in_str(const char *chars, const char *str)
{
	if (*str == 0)
		return (0);
	while (*str && !(ft_strchr(chars, *str)))
		str++;
	if (*str == 0)
		return (0);
	return (ft_strchr(chars, *str));
}
