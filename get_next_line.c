/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:57 by kquispe           #+#    #+#             */
/*   Updated: 2023/11/16 17:13:40 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int txt;
	int i;
	static char *buff;
	char *temp;

	i = 0;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	txt = read(fd, buff, BUFFER_SIZE);
	if (txt == -1)
		printf("error");

	while (buff[i] || buff[i] == '\n')
	{
		// printf("%d\n", i);
		i++;
	}
	int j = 0;
	temp = (char *)malloc((i + 1) * sizeof(char));
	temp[i] = '\0';
	printf("%c", temp[j]);
	while (j < i)
	{
		temp[j] = buff[j];
		j++;
	}
	printf("%s", temp);
	free(temp);
	free(buff);
	return (0);
}
// TODO: averiguar que son lo FD y para q sirven,