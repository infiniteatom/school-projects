#include <stdio.h>

int		main(void)
{
	for (char v = 'A'; v <= 'D'; v ++)
		for (char x = 'A'; x <= 'D'; x ++)
			for (char y = 'A'; y <= 'D'; y ++)
				for (char z = 'A'; z <= 'D'; z ++)
					if (v != x && v != y && v != z && x != y && x != z && y != z)
						printf("%c %c %c %c\n", v, x, y, z);
	return (0);
}
