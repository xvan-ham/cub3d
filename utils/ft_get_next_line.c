/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:35:01 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/15 18:44:34 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/*
** Function: size_t	ft_strlen_delim(const char *s, char delim)
** Returns number of characters until delimiter (not including delimeter).
** If no delim is found, returns strlen.
*/

static size_t	ft_strlen_delim(const char *s, char delim)
{
	size_t	len;

	len = 0;
	while (*s && *(s++) != delim)
		len++;
	return (len);
}

/*
** Function: static char *ft_parsebuffer(char *str, char **residual)
** Function parses string, looking for character '\n'.
** If character '\n' is found, characters up to '\n' are copied to a new string
** and returned; characters beyond '\n' (if within array bounds) are copied to
** a new ** residual string and 'residual' is made to point to it, freeing
** previous (residual) string.
** If there are no characters beyond '\n', 'residual' points to an empty string.
** If no '\n' is found in 'str', function returns a NULL pointer.
*/

static char		*ft_parsebuffer(char *str, char **residual)
{
	char *newstr;

	if (*residual)
		free(*residual);
	if (!str)
		return (NULL);
	if ((ft_strlen(str) - ft_strlen_delim(str, '\n')))
	{
		*residual = ft_strdup(str + ft_strlen_delim(str, '\n') + 1);
		newstr = ft_strndup(str, ft_strlen_delim(str, '\n'));
		if (str)
			free(str);
		return (newstr);
	}
	*residual = ft_strdup(str);
	if (str)
		free(str);
	return (NULL);
}

/*
** Function: int get_next_line(int fd, char **line)
** Function reads from static char *residual and parses string if it is present,
** looking for character '\n'.
** If character '\n' is not found, it reads from 'fd' and loads 'buffer'.
** If character '\n' is still not found it copies the contents from 'buffer' to
** the residual string 'residual' and reads from 'fd' again, merging the
** contents of 'buffer' with the contents of 'residual', parsing with new string
** again. This is repeated until either '\n' is found or EOF is reached
** (returns 0 if EOF is reached).
** Once character '\n' is found, characters up to '\n' are copied to a new
** string and 'line' will point to this new string returning 1 to indicate a
** successful read; characters beyond '\n' (if within array bounds) are copied
** to a new residual string and 'residual' is made to point to it, freeing
** previous (residual) string. If there are no characters beyond '\n',
** 'residual' points to an empty string.
*/

int				ft_get_next_line(int fd, char **line)
{
	static char	*residual;
	char		buffer[BUFFER_SIZE + 1];
	int			n;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (residual ? (ft_strlen(residual) - ft_strlen_delim(residual, '\n')) : 0)
		if ((*line = ft_parsebuffer(ft_strdup(residual), &residual)))
			return (1);
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = 0;
		if ((*line =
		ft_parsebuffer(ft_strjoin(residual, (char *)buffer), &residual)))
			return (1);
	}
	if (n < 0)
		return (-1);
	*line = ft_strdup(residual ? residual : "");
	if (residual)
		free(residual);
	residual = NULL;
	return (0);
}
