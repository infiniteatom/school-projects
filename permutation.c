#include <stdio.h>
#include <string.h>

void	swap(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}

void	permute(char *a, int l, int r)
{
	if (l == r)
		printf("%s\n", a);
	else
		for (int i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permute(a, l + 1, r);
			swap((a + l), (a + i));
		}
}

int		main(void)
{
	char str[] = "ABC";
	int n = strlen(str) - 1;

	permute(str, 0, n);
	return (0);
}
