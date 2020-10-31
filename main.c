#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 4

void* dotMultiply(void *vargp);

typedef struct Args {
    int i;
    int j;
} Args;

int A[N][N];
int B[N][N];
int C[N][N];


int main()
{
    // Init A and B matrices
    printf("A:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = i  * N + j;
            printf("%d %s", A[i][j], j == N-1 ? "\n" : "");
        }
    }
    printf("\nB:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            B[i][j] = i  * N + j;
            printf("%d %s", B[i][j], j == N-1 ? "\n" : "");
        }
    }

    pthread_t thread_id[N][N];

    // Init arguments passed to dotMultiply procedure
    Args      arguments[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            arguments[i][j].i = i;
            arguments[i][j].j = j;
        }
    }


    // Create thread to compute each value in C
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            pthread_create(&thread_id[i][j],
                           NULL, dotMultiply,
                           &arguments[i][j]);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            pthread_join(thread_id[i][j], NULL);
        }
    }

    // Print the result
    printf("\nC:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d %s", C[i][j], j == N-1 ? "\n" : "");
        }
    }

    exit(0);
}

void* dotMultiply(void *varg)
{
    Args *arguments = (Args*)varg;
    int i = arguments->i;
    int j = arguments->j;

    for (int k = 0; k < N; ++k) {
        C[i][j] += A[i][k] * B[k][j];
    }

    return NULL;
}
