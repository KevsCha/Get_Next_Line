/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:23:29 by kquispe           #+#    #+#             */
/*   Updated: 2023/11/18 03:15:13 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void    *ft_calloc(size_t num, size_t bit)
{
        char    *arr;
		size_t	i;

        arr = (char *)malloc(num * bit);
        if (!arr)
                return (NULL);
		i = 0;
        while (i < num)
			arr[i++] = '\0';
        return (arr);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*strtot;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strtot = (char *)malloc(len1 + len2 + 1);
	if (strtot == NULL)
		return (NULL);
	while (i < len1 + len2)
	{
		if (i < len1)
			strtot[i] = *s1;
		if (i < len2)
			strtot[i + len1] = *s2;
		s1++;
		s2++;
		i++;
	}
	strtot[i] = '\0';
	return (strtot);
}