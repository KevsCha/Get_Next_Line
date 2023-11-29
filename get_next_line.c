/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:57 by kquispe           #+#    #+#             */
/*   Updated: 2023/11/29 18:09:01 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char *buff)
{
	free(buff);
	return (NULL);
}

static char	*ft_return_line(char *buff)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	temp = ft_calloc((size_t)i + 1, sizeof(char));
	if (!temp)
		return (ft_free(buff));
	while (buff[j] && buff[j] != '\n')
	{
		temp[j] = buff[j];
		j++;
	}
	return (temp);
}

static char	*ft_line_found(char *buff, int fd)
{
	int		txt;
	char	*temp;

	txt = 1;
	temp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
	{
		free(buff);
		return (NULL);
	}
	while (txt > 0 && !ft_strchr(buff, '\n'))
	{
		txt = read(fd, temp, BUFFER_SIZE);
		if (txt == 0)
		{
			free(temp);
			return (buff);
		}
		if (txt == -1)
			return (free(temp), free(buff), NULL);
		buff = ft_strjoin(buff, temp);
	}
	free(temp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*temp;

	if (fd < 0)
		return (free(buff), NULL);
	buff = ft_line_found(buff, fd);
	if (!buff)
		return (NULL);
	temp = ft_return_line(buff);
	while (*buff)
	{
		if (*buff == '\n' || *(buff + 1) == '\0')
		{
			buff++;
			break ;
		}
		buff++;
	}
	return (temp);
}
