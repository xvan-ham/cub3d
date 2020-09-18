/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:56:10 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/18 20:42:53 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_str_list	*ft_str_list_new_element(const char *s)
{
	t_str_list	*element;
	char		*str;
	char		*str_s;

	if (!(element = (t_str_list *)malloc(sizeof(t_str_list))))
		return (0);
	element->next = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	str_s = str;
	while (*s)
		*(str++) = *(s++);
	*str = 0;
	element->str = str_s;
	return (element);
}

void		ft_str_list_delete(t_str_list *element)
{
	t_str_list	*next;

	while ((next = element->next))
	{
		if (element->str)
		{
			free(element->str);
			element->str = 0;
		}
		free(element);
		element = next;
	}
	if (element->str)
	{
		free(element->str);
		element->str = 0;
	}
}

t_str_list	*ft_str_list_get_element(t_str_list *element, int i)
{
	if (i < 0 || !element)
		return (0);
	while (element->next && i)
	{
		element = element->next;
		i--;
	}
	if (i)
		return (0);
	return (element);
}
