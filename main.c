/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:04:03 by kquispe           #+#    #+#             */
/*   Updated: 2023/11/29 18:04:40 by kquispe          ###   ########.fr       */
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
	while (i < 12)
	{
		
		print = get_next_line(fd);
		printf("[LINEA %d]%s\n", i, print);
		
		if (print == NULL)
			break;
		i++;
	}
	system("leaks get_next_line");
	//free(print);
	//get_next_line(fd);
	close(fd);
    return (0);
}
*/
