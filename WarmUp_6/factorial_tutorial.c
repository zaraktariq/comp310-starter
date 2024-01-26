#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    int number;
    printf("Enter a number to find the factorial of: ");
    scanf("%d", &number);
    printf("the factorial of %d is: %d\n", number, factorial(number));
}

int factorial(int n) {
    if (n <=0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}