/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:57 by kquispe           #+#    #+#             */
/*   Updated: 2023/11/18 08:29:22 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int i;
	int txt;
	static char *buff;
	
	char *temp;
	char *buff_tot;
	int j;
	
	if (fd < 0)
		return (NULL);
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	
	i = 0;
	txt = 1;
	while (txt > 0)
	{
		
		while ((buff[i] != '\n' || !buff[i]) && i < BUFFER_SIZE)
		{	
			printf("%d\n",i);
			i++;
		}
		if (buff[i] == '\n' || !buff[i] || i == BUFFER_SIZE)
		{
			
			ft_next();
			break ;
		}
	}
	buff_tot = (char *)ft_calloc(i + 1, sizeof(char));
	if (!buff_tot)
		return (NULL);
	j = 0;
	while (j < i)
	{
		buff_tot[j] = buff[j];
		j++;
	}
	printf("%s", buff_tot);
	free(buff);
	return (0);
}
// TODO: averiguar que son lo FD y para q sirven,