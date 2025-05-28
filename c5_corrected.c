#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to check prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    pid_t childQ = fork();

    if (childQ == 0) {
        // This is childQ
        printf("ChildQ -> PID: %d \t PPID: %d\n", getpid(), getppid());

        pid_t childS = fork();

        if (childS == 0) {
            // This is childS: computes factorial
            printf("ChildS -> PID: %d \t PPID: %d\n", getpid(), getppid());

            int fact = 1;
            for (int i = 1; i <= n; i++) {
                fact *= i;
            }
            printf("Factorial of %d is %d\n", n, fact);
        } else {
            wait(NULL); // Wait for childS
        }

    } else {
        pid_t childR = fork();

        if (childR == 0) {
            // This is childR
            printf("ChildR -> PID: %d \t PPID: %d\n", getpid(), getppid());

            pid_t childT = fork();
            if (childT == 0) {
                // This is childT: Fibonacci
                printf("ChildT -> PID: %d \t PPID: %d\n", getpid(), getppid());

                int a = 0, b = 1, fib = 0;
                for (int i = 1; i < n; i++) {
                    fib = a + b;
                    a = b;
                    b = fib;
                }
                printf("Fibonacci term at position %d is %d\n", n, (n == 0) ? 0 : (n == 1) ? 1 : fib);
            } else {
                pid_t childU = fork();
                if (childU == 0) {
                    // This is childU: Prime check
                    printf("ChildU -> PID: %d \t PPID: %d\n", getpid(), getppid());

                    if (isPrime(n)) {
                        printf("%d is a Prime number\n", n);
                    } else {
                        printf("%d is Not a Prime number\n", n);
                    }

                } else {
                    wait(NULL); // Wait for childU
                    wait(NULL); // Wait for childT
                }
            }

        } else {
            // Parent waits for childQ and childR
            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}
