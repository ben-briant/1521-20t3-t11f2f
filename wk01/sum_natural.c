// Sums all the natural numbers up to and including the specified number.

#include <stdio.h>
#include <stdlib.h>

int sum_natural_iterative(int num);
int sum_natural_recursive(int num);

int main (void) {

    int num;
    printf("Enter number to be summed: ");
    scanf("%d", &num);
    
    int iterative_sum = sum_natural_iterative(num);
    int recursive_sum = sum_natural_recursive(num);

    printf("iterative sum: %d\n", iterative_sum);
    printf("recursive sum: %d\n", recursive_sum);

    return 0;
}

// Sums the numbers using an iterative approach
int sum_natural_iterative(int num) {
    int sum = 0;
    
    int i = 1;
    while (i <= num) {
        sum += i;
        i++;
    }

    return sum;
}

// Sums the numbers using a recursive approach
int sum_natural_recursive(int num) {
    if (num <= 1) {
        return num;
    }
    
    int sum = sum_natural_recursive(num - 1) + num;

    return sum;
}