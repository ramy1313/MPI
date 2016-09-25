/*
Rami AlaaEldin AbdelHamid
*/

#include<omp.h>
#include<stdio.h>
#define T 4

int main()
{
    int m=600,n=600,i,j;
    double a[m][n],b[n],c[m];
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        a[i][j]=1;
    for(i=0;i<n;i++)
      b[i]=1;
    #pragma omp parallel num_threads(T)
    {
       int tid = omp_get_thread_num();
       #pragma omp for
       for(i=0;i<m;i++)
         {
             printf("the tread num %d takes row %d",tid,i);
             c[i]=0;
             for(j=0;j<n;j++)
               c[i]+=a[i][j]*b[j];
         }
    }
    /*for(i=0;i<m;i++)
      printf(" %f",c[i]);*/
}
