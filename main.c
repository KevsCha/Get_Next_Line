#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;
	char *str;
	char *print;
	int	i;

	str = "test.txt";
	fd = open(str, O_RDONLY);
	i = 0;
	while (i <  3)
	{
		print = get_next_line(fd);
		i++;
	}
	//printf("%s", print);
	free(print);
	//get_next_line(fd);
	close(fd);
    return (0);
}
//?Utilizar funciones para abrir files open, close, read:
/*
!las variables "static" retienen el valor sin importar cuantas veces 
    !se llame a la misma funcion, es decir, si se declara una variable en 0
    !y su valor aumenta a medida que el programa avance y se sigue llamando
    !a la misma funcion el valor se encuentra en el estado anterior y se sigue aumentado
    !si de da el caso.
?Archivos de cabecera ".h"
*/