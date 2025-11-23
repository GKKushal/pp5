/*5. Write a MPI Program to demonstration of MPI_Send and MPI_Recv. */

#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int number;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        if (rank == 0)
            printf("Please run with at least 2 processes.\n");
        MPI_Finalize();
        return 0;
    }

    if (rank == 0) {
        number = 100;
        printf("Process %d sending number %d to process 1\n", rank, number);
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received number %d from process 0\n", rank, number);
    }

    MPI_Finalize();
    return 0;
}

/*Step 1: Install MPI :       
sudo apt update 
sudo apt install openmpi-bin openmpi-common libopenmpi-dev 
Step 2: Check MPI installation: 
mpirun –version 
Step 3: Save the  MPI Program : mpi_send_recv.c 
Step 4: Compile the MPI Program:  mpicc mpi_send_recv.c -o mpi_send_recv 
Step 5: Run the MPI Program: mpirun -np 2 ./mpi_send_recv*/

/**/