/* Rami Alaa Eldin 
*/

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i,numprocs, rank, nlocal=2;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    double b, *fb,j=0.0;

    fb=(double *)malloc(nlocal*sizeof(double));
    for(i=0;i<nlocal;i++) fb[i]=i+1;
    
    for(i=0;i<nlocal;i++) j+=fb[i];

    MPI_Reduce(&j, &b, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank==0) printf("%f ",b);

    MPI_Finalize();
}
