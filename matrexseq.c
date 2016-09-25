/*
Rami AlaaEldin AbdelHamid
*/

#include<stdio.h>

int main()
{
    int m=600,n=600,i,j;
    double a[m][n],b[n],c[m];
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        a[i][j]=1;
    for(i=0;i<n;i++)
      b[i]=1;
    for(i=0;i<m;i++)
     {
        c[i]=0;
        for(j=0;j<n;j++)
          c[i]+=a[i][j]*b[j];
     }
    /*for(i=0;i<m;i++)
      printf(" %f",c[i]);*/
}
