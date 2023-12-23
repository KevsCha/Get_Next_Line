/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:04:03 by kquispe           #+#    #+#             */
/*   Updated: 2023/12/23 15:17:14 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;
	char *str;
	char *str1;
	char *str2;
	char *str3;
	char *str4;
	char *str5;
	char *str6;
	char *str7;
	char *str8;
	char *print;
	int	i;

	str = "test.txt";
	str1 = "1char.txt";
	str2 = "one_line_no_nl.txt";
	str3 = "only_nl.txt";
	str4 = "multiple_nl.txt";
	str5 = "variable_nls.txt";
	str6 = "lines_around_10.txt";
	str7 = "read_error.txt";
	fd = open(str7, O_RDONLY);
	i = 0;
	while (i < 4)
	{
		
		print = get_next_line(fd);
		printf("[LINEA %d]%s", i, print);
		free(print);
		if (print == NULL)
			break;
		i++;
	}
	system("leaks a.out");
	close(fd);
    return (0);
}
