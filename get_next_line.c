/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:57 by kquispe           #+#    #+#             */
/*   Updated: 2023/11/20 18:26:42 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char	*ft_line_found(char **buff, int fd)
{
	char	*temp;
	int		txt;
	
	temp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	txt = 1;
	while (txt > 0 && ft_strchr(*buff, '\n'))
	{
		txt = read(fd, temp, BUFFER_SIZE);
		if (txt == -1)
			return (free(temp), NULL);
		temp[txt] = '\0';
		ft_strjoin(&buff, temp);
		
	}
	/*
	while (txt > 0)
	{
		txt = read(fd, *temp, BUFFER_SIZE);
		while ((*temp)[i] && (*temp)[i] != '\n' && i < BUFFER_SIZE)
		{
			i++;
		}
		if ((*temp)[i] == '\0' || (*temp)[i] == '\n')
		{
			
		}
		else
		{
			//j = ft_strlen(*temp);
			*buff = (char *)ft_calloc(j, sizeof(char));
		}
		j++;
	}
	*/
	return (*temp);
}

char *get_next_line(int fd)
{
	static char *buff;
	char *temp;
	
	if (fd < 0)
		return (NULL);
	temp = ft_line_found(&buff, fd);
	printf("%s", temp);
	free(temp);
	return (0);
}
// TODO: averiguar que son lo FD y para q sirven,