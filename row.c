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
    
    double *fa,*x,*fb,*a,*fx;

    nlocal=n/numprocs;

    fb = (double *)malloc(n*sizeof(double)); 
    x = (double *)malloc(nlocal*sizeof(double));
    fa = (double *)malloc(n*sizeof(double));

    if(rank==0)
    {
         a = (double *)malloc(n*n*sizeof(double));
         for(i=0;i<n;i++) fb[i]=1;
         for(i=0;i<n*n;i++) a[i]=i+1; 
         fx = (double *)malloc(n*sizeof(double));
    }
    
    MPI_Bcast(fb, n, MPI_DOUBLE,0 , MPI_COMM_WORLD);
    MPI_Scatter(a, n, MPI_DOUBLE, fa, n, MPI_DOUBLE, 0,  MPI_COMM_WORLD);
    
    for (i=0; i<nlocal; i++) { 
         x[i] = 0.0; 
         for (j=0; j<n; j++) 
           x[i] += fa[i*n+j]*fb[j]; 
       }    
    
    MPI_Gather(x, nlocal, MPI_DOUBLE, fx, nlocal, MPI_DOUBLE, 0,MPI_COMM_WORLD);

    if(rank==0){
       printf("%d\n",rank);
       for(i=0;i<n;i++) printf("%f ",fx[i]);
    }
    //free(a);free(fa);free(fb);free(x);free(fx);
    MPI_Finalize();

}
