#include <stdio.h>

int main()
{
    int num1 = 0, num2 = 0, sum = 0; // 3 ints, init mit 0
    int *pNum1 = NULL, *pNum2 = NULL; // 3 int ptr, init mit NULL

    pNum1 = &num1; // pNum1 enthält die Adresse von num1
    pNum2 = &num2; // pNum2 enthält die Adresse von num2

    printf("Enter two integers: ");
    scanf("%d%d", pNum1, pNum2);

    sum = *pNum1 + *pNum2;

    printf("Sum = %d", sum);

    return 0;
}
