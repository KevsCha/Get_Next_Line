/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:57 by kquispe           #+#    #+#             */
/*   Updated: 2023/11/28 16:36:17 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_leng_calloc(char *str)
{
	char	*temp;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	temp = ft_calloc(i + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (str[j] && str[j] != '\n')
	{
		temp[j] = str[j];
		j++;
	}
	//printf ("[line]%s\n", temp);
	return (temp);
}

static char *ft_return_line(char *buff, int line)
{
	int		i;
	int		line_num;
	int		key;
	char	*temp;
	
	i = 0;
	key = 1;
	line_num = 1;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			line_num++;
			i++;
		}
		if (line == line_num && key == 1)
		{
			temp = ft_leng_calloc(buff + i);
			key = 0;
		}
		i++;
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
		return (free(buff),NULL);
	while (txt > 0)
	{
		txt = read(fd, temp, BUFFER_SIZE);
		buff = ft_strjoin(buff, temp);
		if (ft_strchr(temp, '\n'))
			break;
	}
	return (buff);
}

char *get_next_line(int fd)
{
	static char *buff;
	char *temp;
	int	i;
	int num_line;
	
	if (fd < 0)
		return (free(buff), NULL);
	i = 0;
	num_line = 0;
	buff = ft_line_found(buff, fd);
	while (buff[i])
	{
		if (buff[i] == '\n' || buff[num_line + 1] == '\0')
			num_line++;
		i++;
	}
	//printf("%d\n",num_line);
	temp = ft_return_line(buff, num_line);
	//printf("%s\n", temp);
	//free(temp);
	return (temp);
}
// TODO: averiguar que son lo FD y para q sirven,