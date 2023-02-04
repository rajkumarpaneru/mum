/*
    An array is definned to be iertial if the following conditrions hold:
    - it contains at least one odd value
    - the maximum value in the array is even
    - every odd value is greater than every even value
    that is not the maximum value.

    So {11, 4, 20, 9, 2, 8} is inertial because
        a. it contains at least one odd value
        b. the maximum value in the array is 20 which is even
        c. the two odd values (11 and 9) are greater than all the
    even values that are not equal to 20 (the maximum), i.e., (4, 2, 8}.

    However, {12, 11, 4, 9, 2, 3, 10} is not inertial because it fails condition (c),
    i.e., 10 (which is even) is greater 9 (which is odd) but 10 is not the maximum value in the array.

    Write a function called isIntertial that accepts an integer array and returns 1
    if the array is inertial; otherwise it returns 0.

*/

#include <stdio.h>

int isInertial(int[], int);

int main()
{
    // int arr[6] = {11, 4, 20, 9, 2, 8};
    int arr[7] = {12, 11, 4, 9, 2, 3, 10};
    int len = 7;
    int n;
    int inertial = isInertial(arr, len);
    if (inertial)
    {
        printf("\nGiven array is an inertial array");
    }
    else
    {
        printf("\nGiven array is NOT an inertial array");
    }

    return 0;
}

int isInertial(int arr[], int len)
{
    int i;
    int max = arr[0];
    int oddCount = 0;
    int evenCount = 0;
    int oddMin;
    int evenMax;
    int evenSecondMax;

    for (i = 0; i < len; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenCount++;

            if (evenCount == 1)
            {
                evenMax = arr[i];
            }
            else
            {
                if (arr[i] > evenMax)
                {
                    evenSecondMax = evenMax;
                    evenMax = arr[i];
                }
            }
        }
        else
        {
            oddCount++;
            if (oddCount == 1 || oddMin > arr[i])
            {
                oddMin = arr[i];
            }
        }

        if (arr[i] > max)
            max = arr[i];
    }

    if (oddCount > 0 && evenCount > 1)
    {
        if (max % 2 == 0 && oddMin > evenSecondMax && oddMin < max)
            return 1;
    }

    if (oddCount > 0 && evenCount == 1)
    {
        if (max % 2 == 0 && oddMin < max)
            return 1;
    }

    return 0;
}