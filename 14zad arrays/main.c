#include<stdio.h>

int main()
{

    int n = 2, m =3 ;
    int mat[][MAX] = { { 2, 1, 7 },
                       { 3, 7, 2 },
                       { 5, 4, 9 } };

    cout << "Minimum element of each row is ";
    smallestInRow(mat, n, m);

    cout << "\nMinimum element of each column is ";
    smallestInCol(mat, n, m);


   //Displaying array elements
   printf("Two Dimensional array elements:\n");
   for(n=0; n<10; n++) {
      for(m=0;m<10;m++) {
         printf("%d ", array[n][m]);
         if(m==10){
            printf("\n");
         }
      }
   }
   return 0;
}
