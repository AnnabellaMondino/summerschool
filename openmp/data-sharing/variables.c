#include <stdio.h>

int main(void)
{
    int var1 = 1, var2 = 2;

    /* TODO:
     *   Test the effect of different data sharing clauses here
     */
        printf("Before entering to a parallelization with private(var1)\n var1=%d\tvar2=%d\n",var1,var2);
#pragma omp parallel //private(var1)
    {
        var1 = 20;
        printf("Region 1: var1=%i, var2=%i\n", var1, var2);
        var1++;
        var2++;
    }
    printf("After region 1: var1=%i, var2=%i\n\n", var1, var2);

    return 0;
}
