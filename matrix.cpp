/*
Rami AlaaEldin AbdelHamid
*/

#include<fstream>
#include<iostream>
#include <stdlib.h>

using namespace std;

void multiply(int **a,int **b,int n,int m,int j,int **c){
    for(int l=0;l<j;l++)
      for(int i=0;i<n;i++){
        c[i][l]=0;
        for(int k=0;k<m;k++)
          c[i][l]+=a[i][k]*b[k][l];
      }

}

int main()
{
    ifstream in("1");
	ofstream out("2");
    int n,k,m,j;
    in>>n;
    in>>m;
    in>>k;
    in>>j;
    if(m!=k){
        out<<"error in size";
        return 0;
    }
    int **a;
    a=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
       a[i]=(int *)malloc(m*sizeof(int));
    int **b;
    b=(int**)malloc(k*sizeof(int*));
    for(int i=0;i<k;i++)
       b[i]=(int*)malloc(j*sizeof(int));
    int **c;
    c=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
       c[i]=(int*)malloc(j*sizeof(int));
    for(int i=0;i<n;i++)
      for(int l=0;l<m;l++)
        in>>a[i][l];
    for(int i=0;i<k;i++)
      for(int l=0;l<j;l++)
        in>>b[i][l];
    multiply(a,b,n,m,j,c);
    if(n==1&&j==1)
      out<<"dot-product result is\n";
    else if(n==1||j==1)
      out<<"mat-vector mul result is\n";
    else out<<"mat-mat mul results is\n";
    for(int i=0;i<n;i++)
      {
          for(int l=0;l<j;l++){
              out<<c[i][l]<<" ";
      }
         out<<"\n";
      }
}
