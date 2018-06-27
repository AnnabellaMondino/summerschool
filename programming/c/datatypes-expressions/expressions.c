#include <stdio.h>

int main(int argc, char *argv[])
{
    // declare integers, floats, and doubles
	int a;
	float b = 2.43;
	double c;

	a = 10;

    // evaluate expressions, e.g. c = a + 2.5 * b
    // and print out results. Try to combine integers, floats
    // and doubles and investigate what happens in type conversions
	c = a + 2.5 * b;
	printf("%e\n", c);

    return 0;
}
