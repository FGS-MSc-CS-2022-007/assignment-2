#include <stdio.h>
#include <omp.h>

int parallelFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    int fib_n_minus_1, fib_n_minus_2;
    #pragma omp parallel sections
    {
        #pragma omp section
        fib_n_minus_1 = parallelFibonacci(n - 1);
        #pragma omp section
        fib_n_minus_2 = parallelFibonacci(n - 2);
    }
    return fib_n_minus_1 + fib_n_minus_2;
}

int main() {
    int n = 10;
    int result = parallelFibonacci(n);
    printf("Fibonacci(%d) = %d\n", n, result);
    return 0;
}
