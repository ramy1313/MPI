/* Rami Alaa Eldin 
*/

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i,j,n=4,numprocs, rank, nlocal;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    double *fa,*x,*fb,*a,*fx,*b;

    nlocal=n/numprocs;

    fb = (double *)malloc(nlocal*sizeof(double)); 
    x = (double *)malloc(n*sizeof(double));
    fa = (double *)malloc(n*sizeof(double));

    if(rank==0)
    {
         a = (double *)malloc(n*n*sizeof(double));
         b = (double *)malloc(n*sizeof(double));
         for(i=0;i<n;i++) b[i]=1;
         for(i=0;i<n*n;i++) a[i]=i+1; 
         fx = (double *)malloc(n*sizeof(double));
    }
    //for simplicty in scattring the matrix is transposed
    
    MPI_Scatter(b, nlocal, MPI_DOUBLE, fb, nlocal, MPI_DOUBLE, 0,  MPI_COMM_WORLD);
    MPI_Scatter(a, n, MPI_DOUBLE, fa, n, MPI_DOUBLE, 0,  MPI_COMM_WORLD);
    
    for (i=0; i<n; i++) { 
         x[i] = 0.0; 
         for (j=0; j<nlocal; j++) 
           x[i] += fa[i*nlocal+j]*fb[j]; 
       }    
    
    MPI_Reduce(x, fx, n, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank==0){
       printf("%d\n",rank);
       for(i=0;i<n;i++) printf("%f ",fx[i]);
    }
    //free(a);free(fa);free(fb);free(x);free(fx);
    MPI_Finalize();

}
