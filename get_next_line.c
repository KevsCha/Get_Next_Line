/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:57 by kquispe           #+#    #+#             */
/*   Updated: 2023/11/06 19:14:25 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	char	*buff;
	int		txt;
    int		i;

    i = 0;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	txt = read(fd, buff, BUFFER_SIZE);
	if (txt == -1)
		printf("error");
	printf("%s", buff);
	return (0);
}
//TODO: averiguar que son lo FD y para q sirven, 