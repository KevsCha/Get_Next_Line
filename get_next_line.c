/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:57 by kquispe           #+#    #+#             */
/*   Updated: 2023/11/22 18:00:25 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_return_line(char *buff, int line)
{
	//printf("%zu\n", ft_strlen(buff));
	char	*temp;
	int 	line_num;
	int		i;

	i = 0;
	line_num = 1;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			line_num++;
		if (line_num == line)
		{
			//Calcular el leng de mi string hasta encontrar el salto de linea y asignarlo con malloc
			//	al temp que quiero devolverlo
		}
		i++;
	}
	return (0);
}

static char	*ft_line_found(char *buff, int fd)
{
	char	*temp;
	int		txt;

	temp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	txt = 1;
	while (txt > 0)
	{
		txt = read(fd, temp, BUFFER_SIZE);
		if (txt == -1)
			return (free(temp), NULL);
		buff = ft_strjoin(buff, temp);
		if (ft_strchr(temp, '\n'))
			break;
	}
	//printf("%s",temp);
	return (buff);
}

char *get_next_line(int fd)
{
	static char *buff;
	char *temp;
	int	i;
	int num_line;
	
	if (fd < 0)
		return (NULL);
	i = 0;
	num_line = 0;
	buff = ft_line_found(buff, fd);
	while (buff[i])
	{
		if (buff[i] == '\n' || buff[num_line + 1] == '\0')
			num_line++;
		i++;
	}
	printf ("%d\n", num_line);
	//printf("%s\n",buff);
	temp = ft_return_line(buff, num_line);
	//printf("%s", temp);
	//free(buff);
	return (0);
}
// TODO: averiguar que son lo FD y para q sirven,