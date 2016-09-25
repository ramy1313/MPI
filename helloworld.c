/* Rami Alaa Eldin 
*/

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
  int numprocs, rank, b, i, id;
  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  id=rank;
  
  if(rank==0)
    {
       for(i=1;i<numprocs;i++)
          {
            MPI_Recv(&b, 2, MPI_INT, i, 2, MPI_COMM_WORLD,&status); 
            printf("Process %d out of %d from %d \n", rank, numprocs,b);
          }
        
    }
  else 
       MPI_Send(&id, 2, MPI_INT, 0, 2, MPI_COMM_WORLD);
  MPI_Finalize();
}
