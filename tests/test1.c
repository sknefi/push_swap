#include <stdio.h>
#include "../src/libraries.h"

/**
 * init stack `a`, `b`
 * 
 * `printer`
 * 
 * `pb`
 * 
 * `printer`
 * 
 * `pb`
 * 
 * `printer`
 * 
 * `pa`
 * 
 * `printer`
*/
void	test1(int argc, char *argv[])
{
	t_dll	*dll_a;
	t_dll	*dll_b;

	(void) argc;
	dll_a = dll_create(argv);
	dll_b = dll_init();

	dll_printer(dll_a);
	dll_printer(dll_b);
	push(dll_b, dll_a);

	ft_printf("###################\n");

	dll_printer(dll_a);
	dll_printer(dll_b);

	push(dll_b, dll_a);

	ft_printf("###################\n");

	dll_printer(dll_a);
	dll_printer(dll_b);

	push(dll_a, dll_b);

	ft_printf("###################\n");

	dll_printer(dll_a);
	dll_printer(dll_b);
}

/**
 * `pb` `pa` `pa`
*/
void	test2(int argc, char *argv[])
{
	t_dll	*dll_a;
	t_dll	*dll_b;

	(void) argc;
	dll_a = dll_create(argv);
	dll_b = dll_init();

	dll_printer(dll_a);
	dll_printer(dll_b);

	ft_printf("##################\n");

	push(dll_b, dll_a);
	push(dll_a, dll_b);
	push(dll_a, dll_b);

	dll_printer(dll_a);
	dll_printer(dll_b);
}

/**
 * `pb` `pb` `sa` `sa` `ss`
*/
void	test3(int argc, char *argv[])
{
	t_dll	*dll_a;
	t_dll	*dll_b;

	(void) argc;
	dll_a = dll_create(argv);
	dll_b = dll_init();

	dll_printer(dll_a);
	dll_printer(dll_b);

	ft_printf("##################\n");

	push(dll_b, dll_a);
	push(dll_b, dll_a);
	swap(dll_a);
	swap(dll_b);
	swap_both(dll_a, dll_b);

	dll_printer(dll_a);
	dll_printer(dll_b);
}

/**
 * ra
*/
void	test4(int argc, char *argv[])
{
	t_dll	*dll_a;
	t_dll	*dll_b;

	(void) argc;
	dll_a = dll_create(argv);
	dll_b = dll_init();

	dll_printer(dll_a);
	dll_printer(dll_b);

	ft_printf("##################\n");

	rotate(dll_a, 5);

	dll_printer(dll_a);
	dll_printer(dll_b);
}

/**
 * pb rr
*/
void	test5(int argc, char *argv[])
{
	t_dll	*dll_a;
	t_dll	*dll_b;

	(void) argc;
	dll_a = dll_create(argv);
	dll_b = dll_init();

	push(dll_b, dll_a);
	push(dll_b, dll_a);
	push(dll_b, dll_a);

	dll_printer(dll_a);
	dll_printer(dll_b);

	ft_printf("##################\n");


	rotate_both(dll_a, dll_b, 2);

	dll_printer(dll_a);
	dll_printer(dll_b);
}