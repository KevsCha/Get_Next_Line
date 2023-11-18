#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//!si lo defino con un buffer el compilador me lo esta creando, pero si no lo commpilo con un buffer ya lo tengo por predeterminado suerte campeon 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void    *ft_calloc(size_t num, size_t bit);


#endif
