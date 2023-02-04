/*
    Write a function to return the first perfect square that is greater than its integer
    argument. A perfect square is an integer that is equal to some integer squared.
*/

#include <stdio.h>
int nextPerfectSquare(int);

int main()
{
    int n;
    while (1)
    {
        printf("\nEnter a number: ");
        scanf("%d", &n);

        printf("Next perfect square is: %d.\n", nextPerfectSquare(n));
    }
    return 0;
}

int nextPerfectSquare(int n)
{
    // find largest perfect square smaller or equal to n
    // get next perfect square
    int i;
    int nextSquare;
    for (i = 0; i * i <= n; i++)
    {
        nextSquare = (i + 1) * (i + 1);
        if (nextSquare > n)
        {
            return nextSquare;
        }
    }
    return 0;
}