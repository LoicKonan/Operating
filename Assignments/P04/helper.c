// /*
// 	Name/s: Loic Konan & Byron Dowling
// 	Class: 5133 Advanced Computer Architecture
// 	Date: 11/3/2021
// 	Assignment: Homework #5 Pthreads Programming

// 	Details:
// 		- Perform the Addition of A + B
//         - Perform the Difference of A - B
//         - Perform the Product of A * B
//         - Perform the Quotient of A / B

// */

// #include <stdio.h>
// #include <pthread.h>

// #define NUM_THREADS 4
// #define ARR_SIZE 2

// void *DoStuff(void *);
// pthread_mutex_t mutex1;

// int Arr_A[ARR_SIZE];
// int Arr_B[ARR_SIZE];

// int Arr_Sum[ARR_SIZE];
// int Arr_Sub[ARR_SIZE];
// int Arr_Mul[ARR_SIZE];
// double Arr_Div[ARR_SIZE];

// double Add_Sum = 0;
// double Sub_Sum = 0;
// double Mul_Sum = 0;
// double Div_Sum = 0;

// void *DoStuff(void *t)
// {
//     long t_id;
//     t_id = ((long)t + 1);

//     for (int i = ((t_id - 1) * ARR_SIZE); i < (t_id * ARR_SIZE - 1); i++)
//     {
//         Add_Sum += Arr_A[i] + Arr_B[i];
//         Sub_Sum += Arr_A[i] - Arr_B[i];
//         Mul_Sum += Arr_A[i] * Arr_B[i];
//         Div_Sum += (double)Arr_A[i] / (double)Arr_B[i];
//     }
// }

// main()
// {
//     pthread_t thread_ids[NUM_THREADS];

//     pthread_attr_t attr;
//     int rc;
//     long t;
//     void *status;

//     /* Initialize and set thread detached attribute */
//     pthread_attr_init(&attr);
//     pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

//     // Initialize Array Data for both A and B
//     for (int i = 0; i < ARR_SIZE; i++)
//     {
//         Arr_A[i] = 1;
//         Arr_B[i] = 2;
//     }

//     for (int i = 0; i < NUM_THREADS; i++)
//     {
//         pthread_create(&thread_ids[i], NULL, DoStuff, NULL);
//     }

//     for (int i = 0; i < NUM_THREADS; i++)
//     {
//         pthread_join(thread_ids[i], NULL);
//     }

//     // print ARRAY
//     for (int i = 0; i < ARR_SIZE; i++)
//     {
//         printf("%d\t", Arr_A[i]);
//         printf("%d\t", Arr_B[i]);
//         printf("\n");
//     }
//     printf("Sum summation is: %f\n", Add_Sum);
//     printf("Sub summation is: %f\n", Sub_Sum);
//     printf("Mul summation is: %f\n", Mul_Sum);
//     printf("Div summation is: %f\n", Div_Sum);

//     pthread_exit(NULL);
// }

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Value depend on System core
#define CORE 4

// Maximum matrix size
#define MAX 4

// Maximum threads is equal to total core of system
pthread_t thread[CORE];
int mat_A[MAX], mat_B[MAX];
int sub = 0;
int sum = 0;

// Addition of a Matrix
void *addition(void *arg)
{

    int i, j;
    int core = (int)arg;

    for (i = MAX; i < MAX; i++)
    {
        // Compute Sum 
        sum = mat_A[i] + mat_B[i];
    }
}

// Subtraction of a Matrix
void *subtraction(void *arg)
{

    int i, j;
    int core = (int)arg;

    for (i = MAX; i < MAX; i++)
    {
        // Compute Subtract 
        sub = mat_A[i] - mat_B[i];
    }
}

// Driver Code
int main()
{
    int i, j, step = 0;
    // values in mat_A and mat_B
    for (i = 0; i < MAX; i++)
    {
        mat_A[i] = 1;
        mat_B[i] = 2;
    }

    // Displaying mat_A
    printf("\nMatrix A and matrix B:\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", mat_A[i]);
        printf("%d ", mat_B[i]);

        printf("\n");
    }

    // Creating threads equal
    // to core size and compute matrix row
    for (i = 0; i < CORE; i++)
    {
        pthread_create(&thread[i], NULL, &addition, (void *)step);
        pthread_create(&thread[i + CORE], NULL, &subtraction, (void *)step);
        step++;
    }

    // Waiting for join threads after compute
    for (i = 0; i < CORE; i++)
    {
        pthread_join(thread[i], NULL);
    }

    // Display Addition of mat_A and mat_B
    printf("\n Sum of Matrix A and B:\n");
    printf("%d ", sum);
    printf("\n");

    // Display Subtraction of mat_A and mat_B
    printf("\n Subtraction of Matrix A and B:\n");
    printf("%d ", sub);
    printf("\n");

    return 0;
}
