#include <stdio.h>
#include "operations/operations.h"

void my_func(void)
{
	int i;
	int j;
	int smallest;
	int current_closest_bigger;

	int a[4] = {5, 7, 10, 42};
	int b[5] = {-38, 99, 25, 0, 6};

	const int a_size = sizeof(a) / sizeof(a[0]);


	smallest = a[0];
	current_closest_bigger = 2147483647; // why here cant be a[0]????
	
	j = 4;
	i = 0;
	while (i < a_size)
	{
		if (a[i] < smallest)
			smallest = a[i];
		if (a[i] > b[j] && a[i] < current_closest_bigger)
		{
			current_closest_bigger = a[i];
		}
		
		i++;
	}
	printf("For b[%d] = %d, smallest in a: %d, closest bigger in a: %d\n", j, b[j], smallest, current_closest_bigger);
}

int	main(int argc, char *argv[])
{
	t_dll	*dll;

	(void) argc;
	dll = dll_create(argv);
	dll_printer(dll);
	return 0;
}