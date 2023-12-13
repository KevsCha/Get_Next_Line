/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:57 by kquispe           #+#    #+#             */
/*   Updated: 2023/12/05 18:55:15 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char *buff)
{
	free(buff);
	return (NULL);
}

char	*ft_buff_change(char *buff)
{
	int		i;
	int		j;
	int		k;
	char	*aux;

	i = 0;
	j = 0;
	k = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		while (buff[i + j + 1])
			j++;
	aux = ft_calloc(j + 1, sizeof(char));
	if (!aux)
		return (free(buff), NULL);
	while (k < j || k < 0)
	{
		aux[k] = buff[i + 1 + k];
		k++;
	}
	free(buff);
	return (aux);
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
			return (free(temp), buff);
		if (txt == -1)
			return (free(temp), NULL);
		buff = ft_strjoin(buff, temp);
		if (!buff)
			return (free(temp), NULL);
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
		return (free(buff), NULL);
	temp = ft_return_line(buff);
	buff = ft_buff_change(buff);
	system("leaks a.out");
	return (temp);
}
