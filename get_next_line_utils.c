/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquispe <kquispe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:23:29 by kquispe           #+#    #+#             */
/*   Updated: 2023/12/02 03:02:58 by kquispe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t num, size_t bit)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = (char *)malloc(num * bit);
	if (!arr)
		return (NULL);
	while (i < num)
		arr[i++] = '\0';
	return (arr);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (!s)
		return (0);
	temp = (char *)s;
	while (temp[i])
	{
		if (temp[i] == (char)c)
			return (temp + i);
		i++;
	}
	if (temp[i] == (char)c)
		return (temp + i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*strtot;

	i = -1;
	if (!s1)
	{
		s1 = ft_calloc(1, 1);
		if (!s1)
			return (NULL);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strtot = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (strtot == NULL)
		return (NULL);
	while (++i < len1 + len2)
	{
		if (i < len1)
			strtot[i] = *s1++;
		if (i < len2)
			strtot[i + len1] = *s2++;
	}
	return (strtot);
}
/*
	int		len1;
	int		len2;
	int		i;
	int		j;
	char	*strtot;

	i = -1;
	j = -1;
	if (!s1)
		s1 = ft_calloc(1, 1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strtot = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (strtot == NULL)
		return (NULL);
	while (++i < len1)
		strtot[i] = s1[i];
	while (++j < len2)
		strtot[i + j] = s2[j];
	free (s1);
	return (strtot);
*/
