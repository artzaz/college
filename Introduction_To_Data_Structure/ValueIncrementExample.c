#include <stdio.h>

void incrementByValue(int y) {
    ++y;
    printf("Inside incrementByValue: %d\n", y);
}

void incrementByReference(int *py) {
    ++(*py);
    printf("Inside incrementByReference: %d\n", *py);
}

int main() {
    int x = 5;
    
    printf("Original value of x: %d\n", x);
    
    incrementByValue(x);
    printf("After incrementByValue, x: %d\n", x);
    
    incrementByReference(&x);
    printf("After incrementByReference, x: %d\n", x);
    
    return 0;
}
