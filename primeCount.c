/*
The function primeCount(int, int) returns the number of primes between start and end inclusive.
Recall that a prime is a positive integer greater than 1 whose only integer factors  are 1 and itself.
*/
#include <stdio.h>

int primeCount(int, int);
int isPrime(int);

int main()
{
    int start, end;
    while (1)
    {
        printf("\nEnter start and end: ");
        scanf("%d%d", &start, &end);
        printf("\n The prime-count is: %d\n", primeCount(start, end));
    }

    return 0;
}

int primeCount(int start, int end)
{
    int primeCount = 0;

    // prime count logic here

    int i;
    for (i = start; i <= end; i++)
    {
        if (isPrime(i))
        {
            primeCount++;
        }
    }

    return primeCount;
}

int isPrime(int n)
{
    int i;
    int flag = 1;

    if (n < 2)
        return 0;

    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }

    return (flag == 1);
}