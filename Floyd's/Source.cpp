//
//  main.c
//  Floyd's Algorithm
//
//  Created by Dale Rico and Thomas Arnold on 3/26/17.
//  Copyright � 2017 Dale Rico & Thomas Arnold. All rights reserved.
//
// Input files must follow this format:
// number_of_vertices=n
// vert0_edge_0 vert0_edge_1 ... vert0_edge_n
// ...
// vert_n_edge_0 vert_n_edge_1 ... vert_n_edge_n
//
// example input text file:
// 5
// 0 1 2 3 4
// 1 0 3 4 5
// 2 3 0 5 0
// 3 4 5 0 1
// 4 5 0 1 0
// 
// Any file that does not follow this format will cause
// unexpected errors during execution
//
// Arguments must be entered in this format: <mode> <number of processes/threads> \
//		<optional::number of vertices to generate> <optional::name of file to read in>
//	<mode> refers to the the function you wish to run. 
//	

#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <time.h>
//#include <omp.h>

// Globals
const int G_INFINITY = (INT_MAX / 2);
const char G_INF_CHAR = '*';
int nthreads = 4;
int omp_get_num_threads();

// Function declarations
void loop();
void example_mode();
void serial_rand_mode();
void serial_input_mode();
void initialize_matrix(int **in_matrix, int rows, int cols);
void populate_matrix(int **in_matrix, int rows, int cols);
void print_matrix(int **in_matrix, int rows, int cols, char* in_text);
void print_shortest_paths(int **in_matrix, int rows, int cols);
void serial_floyds(int **in_matrix, int rows, int cols);
int min(int a, int b);
void floyds_omparallel(int **in_matrix, int rows, int cols);


int main(int argc, const char ** argv)
{
    
    clock_t begin = clock();
    serial_input_mode();
    clock_t end = clock();
    double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
    
    printf("Estimated time = %f seconds\n", time_spent);
    
    
    
    
    
  /* double start, stop;
    
    start = omp_get_wtime();
    serial_input_mode();
    stop = omp_get_wtime();
    
    printf("Number of threads = %d\n", omp_get_num_threads());
    
    printf("Estimated time =  %f\n", stop - start);
  */
    
	// Verify we have correct number of options
/*	if (argc < 2 || argc > 4)
	{
		fprintf(stderr, "Incorrect number of arguments\n");
		fprintf(stderr, "\"Input should be <mode> <number of processes/threads>");
		fprintf(stderr, " <optional::number of vertices to generate>");
		fprintf(stderr, " <optional::name of file to read in>\"\n");
		fprintf(stderr, "=======================================================================");
		fprintf(stderr, "<mode> can be one of the following\n");
		fprintf(stderr, "1)Run serial Floyd's algorithm on the example from project description\n");
		fprintf(stderr, "2)Run serial Floyd's algorithm on input from a file\n");
		fprintf(stderr, "3)Run serial Floyd's algorithm on randomized input\n");
		fprintf(stderr, "4)Run OpenMPI Floyd's algorithm on randomized input\n");
		fprintf(stderr, "5)Run OpenMPI Floyd's algorithm on input from a file\n");
		fprintf(stderr, "=======================================================================");
		fprintf(stderr, "<optional::number of vertices to generate> = 0 if read input from file\n");
		fprintf(stderr, "<optional::name of file to read in> = 0 if not read input from file\n");
	}
	// 
	else
	{

	}
*/
	return 0;
}

void loop()
{
	bool flag = true;
	int choice = 0;

	do
	{

		printf("Enter a number from one of the following\n");
		printf("1)Run serial Floyd's algorithm on the example from project description\n");
		printf("2)Run serial Floyd's algorithm on input from a file\n");
		printf("3)Run serial Floyd's algorithm on randomized input\n");
		printf("4)Run OpenMPI Floyd's algorithm on randomized input\n");
		printf("5)Run OpenMPI Floyd's algorithm on input from a file\n");
		printf("99)Exit program\n");
		scanf("%i", &choice);
		printf("\n\n");

		switch(choice)
		{
			case 1:
				example_mode();
				break;
			case 2:
				serial_input_mode();
				break;
			case 3:
				serial_rand_mode();
				break;
			case 4:
				break;
			case 5:
				break;
			case 99:
				flag = false;
				break;
			default:
				printf("Invalid choice...\n\n");
				break;
		}
	} while(flag);
}

void example_mode()
{
	// Example matrix contains 6 vertices
	int row = 6, col = 6;
	int ** adj_matrix = (int**)malloc(sizeof(int*)*row);
	for (int i = 0; i < col; i++)
		*(adj_matrix + i) = (int*)malloc(sizeof(int)*row);

	// Initialize the matrix and populate the edges
	initialize_matrix(adj_matrix, row, col);
	{
		adj_matrix[0][1] = 2;
		adj_matrix[0][2] = 5;
		adj_matrix[1][2] = 7;
		adj_matrix[1][3] = 1;
		adj_matrix[1][5] = 8;
		adj_matrix[2][3] = 4;
		adj_matrix[3][4] = 3;
		adj_matrix[4][2] = 2;
		adj_matrix[4][5] = 3;
		adj_matrix[5][1] = 5;
		adj_matrix[5][3] = 2;
		adj_matrix[5][4] = 4;
	}

	// Print of initial matrix
	print_matrix(adj_matrix, row, col, "Matrix of input data:\n");

	// Perfrom Floyds algorithm
	serial_floyds(adj_matrix, row, col);

	// Print output of the new matrix
	print_matrix(adj_matrix, row, col, "Transitive closure:\n");

	// Print shortest paths for each node
	print_shortest_paths(adj_matrix, row, col);
}

void serial_rand_mode()
{
	int row=0, col=0;

	// Find out the size of the the array
	printf("Please enter the number of vertices: ");
	scanf("%d", &col);
	printf("\n\n");
	row=col;

	int ** adj_matrix;
	adj_matrix = (int**)malloc(sizeof(int*)*row);
	for (int i = 0; i < col; i++)
		*(adj_matrix + i) = (int*)malloc(sizeof(int)*row);

	// Initial matrix setup and population
	initialize_matrix(adj_matrix, row, col);
	populate_matrix(adj_matrix, row, col);

	// Print of initial matrix
	print_matrix(adj_matrix, row, col, "Matrix of input data:\n");

	// Perfrom Floyds algorithm
	serial_floyds(adj_matrix, row, col);

	// Print output of the new matrix
	print_matrix(adj_matrix, row, col, "Transitive closure:\n");

	// Print shortest paths for each node
	print_shortest_paths(adj_matrix, row, col);
}

void serial_input_mode()
{
	int row = 0, col = 0, tmp;
	int ** adj_matrix;
	char buff[255];
	int num_vert;
	FILE *fp;

	// Read-in the name of the txt file
	do
	{
		printf("\nInput the file to read the adjacency matrix: ");
		scanf("%s", buff);
		fp = fopen(buff, "r");
	} while (!fp);

	// Read-in the first line, it contains the number of vertices
	fscanf(fp, "%s", buff);
	num_vert = atoi(buff);
	row = col = num_vert;
	
	// Allocate memory for the 2d array
	adj_matrix = (int**)malloc(sizeof(int*)*row);
	for (int i = 0; i < col; i++)
		*(adj_matrix + i) = (int*)malloc(sizeof(int)*row);

	// Read-in rest of the data
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			fscanf(fp, "%s", buff);
			tmp = atoi(buff);
			adj_matrix[i][j] = tmp;
		}
	}

	// Close the file
	fclose(fp);

	// Print initial matrix
	print_matrix(adj_matrix, row, col, "Matrix of input data:\n");

	// Perfrom Floyds algorithm
	serial_floyds(adj_matrix, row, col);
    
    // Perform Floyds OMP
  // floyds_omparallel(adj_matrix,row, col);         // ADDED HERE **NEW**

	// Print output of the new matrix
	print_matrix(adj_matrix, row, col, "Transitive closure:\n");

	// Print shortest paths for each node
	print_shortest_paths(adj_matrix, row, col);
}

void initialize_matrix(int **in_matrix, int rows, int cols)
{
	int i, j;
	for(i = 0; i < rows; ++i)
	{
		for(j = 0; j < cols; ++j)
		{
			// If same node, then cost is 0
			if(i == j)
			{
				in_matrix[i][j] = 0;
			}
			// Else, we simulate 'infinity'
			else
			{
				in_matrix[i][j] = G_INFINITY;
			}
		}
	}
}

void populate_matrix(int **in_matrix, int rows, int cols)
{
	int i, u, v, weight;
	for(i = 0; i < rows * cols; ++i)
	{
		u = rand() % rows;
		v = rand() % cols;
		// Same as initialize_matrix, if same node: cost is 0
		if(u == v)
		{
			continue;
		}
		weight = rand() % 49;
		in_matrix[u][v] = weight;
	}
}

void print_matrix(int **in_matrix, int rows, int cols, char* in_text)
{
	int i, j;
	// Printf is used to center the title
	for(i = 0; i < cols; ++i)
	{
		if(i == cols / 2)
		{
			printf("%s", in_text);
			break;
		}
		else
			printf("\t");
	}

	// Printf is used to help format col-based output:
	for(i = 0; i < cols; ++i)
		printf("\t(%i)", i);
	printf("\n");

	for(i = 0; i < rows; ++i)
	{
		// Printf is used to help format row-based output:
			printf("(%i)\t", i);
		for(j = 0; j < cols; ++j)
		{
			// Accounting for infinity, do not print this value
			// It would destroy our print
			// Print '-' in areas with no route
			if(in_matrix[i][j] == G_INFINITY)
			{
				printf("%c \t", G_INF_CHAR);
			}
			// Print the cost for areas that aren't 'infinity'
			else
				printf("%d \t", in_matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print_shortest_paths(int **in_matrix, int rows, int cols)
{
	int i, j;

	printf("\nThe shortest paths are:\n");
	for(i = 0; i < rows; ++i)
	{
		for(j = 0; j < cols; ++j)
		{
			// Accounting for infinity, do not print this value
			// It would destroy our print
			// Print '-' in areas with no route
			if(in_matrix[i][j] == G_INFINITY)
			{
				printf("<%d to %d> = %c\t", i, j, G_INF_CHAR);
			}
			// Print the cost for areas with route
			else
			{
				printf("<%d to %d> = %d\t", i, j, in_matrix[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

void serial_floyds(int **in_matrix, int rows, int cols)
{
	int i, j, k;

	for(k = 0; k < rows; ++k)
		for(i = 0; i < rows; ++i)
			for(j = 0; j < rows; ++j)
			{
				if(i == j)
				{
					in_matrix[i][j] = 0;
				}
				else
				{
					in_matrix[i][j] = min(in_matrix[i][j], in_matrix[i][k] + in_matrix[k][j]);
				}
			}
}

int min(int a, int b)
{
	return ((a < b) ? a : b);
}

void floyds_omparallel(int **in_matrix, int rows, int cols)     //ADDED HERE **NEW**
{
    int i, j, k;
    
    for(k = 0; k < rows; ++k)
#pragma omp parallel for num_threads(nthreads)
        for(i = 0; i < rows; ++i)
            for(j = 0; j < rows; ++j)
            {
                if(i == j)
                {
                    in_matrix[i][j] = 0;
                }
                else
                {
                    in_matrix[i][j] = min(in_matrix[i][j], in_matrix[i][k] + in_matrix[k][j]);
                }
            }
}

