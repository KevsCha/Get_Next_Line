/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:04:03 by kquispe           #+#    #+#             */
/*   Updated: 2023/12/02 03:31:13 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

/*
int main(void)
{
	int	fd;
	char *str;
	char *print;
	int	i;

	str = "test.txt";
	fd = open(str, O_RDONLY);
	i = 0;
	while (i < 10)
	{
		
		print = get_next_line(fd);
		printf("[LINEA %d]%s\n", i, print);
		free(print);
		if (print == NULL)
			break;
		i++;
	}
	
	close(fd);
    return (0);
}
*/
