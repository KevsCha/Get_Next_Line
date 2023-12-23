/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:57 by kquispe           #+#    #+#             */
/*   Updated: 2023/12/23 15:18:32 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_buff_change(char *buff)
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
	aux = malloc(j + 1 * sizeof(char));
	if (!aux)
		return (free(buff), buff = NULL, NULL);
	while (k < j || k < 0)
	{
		aux[k] = buff[i + 1 + k];
		k++;
	}
	aux[k] = '\0';
	return (free(buff), buff = NULL, aux);
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
	if (buff[i] == '\n')
		i++;
	temp = ft_calloc((size_t)i + 1, sizeof(char));
	if (!temp)
		return (free(buff), buff = NULL, NULL);
	while (buff[j] && buff[j] != '\n')
	{
		temp[j] = buff[j];
		j++;
	}
	if (buff[j] == '\n')
		temp[j] = '\n';
	return (temp);
}

static char	*ft_line_found(char *buff, int fd)
{
	int		txt;
	char	*temp;

	txt = 1;
	temp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!temp)
		return (free(buff), buff = NULL, NULL);
	while (!ft_strchr(buff, '\n') && txt != 0)
	{
		txt = read(fd, temp, BUFFER_SIZE);
		if (txt == 0)
			return (free(temp), temp = NULL, buff);
		temp[txt] = '\0';
		if (txt == -1)
			return (free(temp), temp = NULL, NULL);
		buff = ft_strjoin(buff, temp);
		if (!buff)
			return (free(temp), temp = NULL, NULL);
	}
	return (free(temp), temp = NULL, buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*temp;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (free(buff), buff = NULL, NULL);
	buff = ft_line_found(buff, fd);
	if (!buff)
		return (free(buff), buff = NULL, NULL);
	while (buff[i])
		i++;
	if (i == 0)
		return (free(buff), buff = NULL, NULL);
	temp = ft_return_line(buff);
	if (!temp)
		return (free(buff), buff = NULL, NULL);
	buff = ft_buff_change(buff);
	if (!buff)
		return (free(temp), temp = NULL, NULL);
	return (temp);
}
