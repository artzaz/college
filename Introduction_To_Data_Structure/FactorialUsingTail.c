#include <stdio.h>

int factorialTail(int n)
{
    if (n == 1 || n == 0) {
        return 1;
    }
    else {
        return n * factorialTail(n - 1);
    }
}

int main()
{
    
    int n = 5;
    
    int fact1 = factorialTail(n);
    printf("Resursive Factorial of %d: %d \n", n, fact1);
    
    return 0;
}
