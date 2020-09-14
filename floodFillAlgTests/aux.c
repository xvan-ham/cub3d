/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:12:28 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/11 18:08:51 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood.h"

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

void	ft_putstr(const char *s)
{
	if (!s)
		ft_error(" received null pointer: ft_putstr");
	write(1, s, ft_strlen(s));
}

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

int		digits(int n)
{
	int digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
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


/*
** Function: char	*ft_strndup(const char *src, size_t chars)
** Allocates sufficient memory for a freeable copy of the string
** 'src', does the copy, and returns a pointer to it.
** Copies at most 'chars' characters from the string
** 'src' always NUL terminating the copied string.
*/

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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*cdst;

	cdst = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	while (n && i++ < n)
		*(cdst++) = *(char *)(src++);
	return (dst);
}