/*
    The n-upcount of an array is the number of times the partial sum goes from less
    than or equal to n to greater than n during the calculation of the sum of the
    elements of the array.

    For example, if n = 5, teh 5-upcount of the array {2, 3, 1, -6, 8, -3, -1, 2} is 3.
*/

#include <stdio.h>

int nUpCount(int[], int, int);

int main()
{
    int arr[8] = {2, 3, 1, -6, 8, -3, -1, 2};
    // int arr[3] = {6, -3, 1};
    int len = 8;
    int n;
    while (1)
    {
        printf("\nEnter n for n-upcount: ");
        scanf("%d", &n);
        printf("\n The up-count is: %d\n", nUpCount(arr, len, n));
    }

    return 0;
}

int nUpCount(int arr[], int len, int n)
{
    int previousPartialSum = 0;
    int partialSum = 0;
    int upCount = 0;
    int i;
    for (i = 0; i < len; i++)
    {
        previousPartialSum = partialSum;
        partialSum += arr[i];
        if (previousPartialSum <= n && partialSum > n)
        {
            ++upCount;
        }
        // printf("\n%d %d", previousPartialSum, partialSum);
    }
    return upCount;
}