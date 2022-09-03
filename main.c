#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

int main()
{
    int arr[MAX_SIZE];
    int i, n , X, sum=0;
    int a[1000], n, i, psum=0, nsum=0;
    int a[MAX SIZE_1000];

    // Input size of the array
    printf ("Enter size of the array: ");
    scanf( "%d", &n);

    //Input elements in array
    printf( "Enter %d elements in the array: ", n);


    //Input only sums that are bigger than X
    printf( " Sums that bigger than X: " );
    scanf( "%d", &X);

    for( i=0; i<n ; i++)
    {
        scanf( "%d", &arr[i]);
    }

    /*
        Add each array element to sum that is bigger than X
    */

    for(i=0; i<n ; i++)
    {
        sum= sum + arr[i];
        sum> X;
    }

    printf ( "Sum of all elements of array = %d", sum);
    system( "pause> null ");

    return 0;

}
