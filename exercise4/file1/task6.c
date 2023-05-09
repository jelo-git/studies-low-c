#include <stdio.h>
#include <string.h>
#define MATRIX_SIZE 15
int loadMatrix(char sampleName[], int output[MATRIX_SIZE][MATRIX_SIZE], int *x, int *y)
{
    FILE *file;
    char name[32];
    printf("Enter the name of your test file (sample at '%s'): ", sampleName);
    scanf("%s", name);
    file = fopen(name, "r");
    if (file == NULL)
    {
        printf("File can't be opened\n");
        return 1;
    }
    char *line = NULL;
    size_t len = 0, read;
    int nsize = 0, msize = 0;
    while ((read = getline(&line, &len, file)) != -1)
    {
        int n = 0;
        char *tmp = strtok(line, " ");
        while (tmp != NULL)
        {
            double num;
            sscanf(tmp, "%lf", &num);
            output[msize][n] = num;
            tmp = strtok(NULL, " ");
            n += 1;
        }
        if (n >= MATRIX_SIZE || msize >= MATRIX_SIZE)
        {
            printf("Matrix to big\n");
            return 1;
        }
        if (nsize < n)
        {
            if (nsize != 0)
            {
                printf("Bad size of the input matrix\n");
                return 1;
            }
            nsize = n;
        }
        msize += 1;
    }
    fclose(file);
    *(x) = nsize;
    *(y) = msize;
    return 0;
}
void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], int x, int y)
{
    for (int n = 0; n < y; n++)
    {
        for (int m = 0; m < x; m++)
        {
            printf("%i ", matrix[n][m]);
        }
        printf("\n");
    }
}
void calculateRMatirx(int Amatrix[MATRIX_SIZE][MATRIX_SIZE], int Bmatrix[MATRIX_SIZE][MATRIX_SIZE], int x, int y, int output[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int n = 0; n < y; n++)
    {
        for (int m = 0; m < x; m++)
        {
            output[n][m] = (Amatrix[n][m] == Bmatrix[n][m]);
        }
    }
}
void calculatePMatirx(int Amatrix[MATRIX_SIZE][MATRIX_SIZE], int Bmatrix[MATRIX_SIZE][MATRIX_SIZE], int x, int y, int output[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int n = 0; n < y; n++)
    {
        for (int m = 0; m < x; m++)
        {
            output[n][m] = (Amatrix[n][m] > Bmatrix[n][m]);
        }
    }
}
int main()
{
    int A[MATRIX_SIZE][MATRIX_SIZE], ax, ay;
    if (loadMatrix("task6sampleA.txt", A, &ax, &ay))
        return 1;
    int B[MATRIX_SIZE][MATRIX_SIZE], bx, by;
    if (loadMatrix("task6sampleB.txt", B, &bx, &by))
        return 1;
    if (ax != bx || ay != by)
        return 1;
    printf("Matrix A:\n");
    printMatrix(A, ax, ay);
    printf("Matrix B:\n");
    printMatrix(B, bx, by);
    printf("Matrix R:\n");
    int R[MATRIX_SIZE][MATRIX_SIZE];
    calculateRMatirx(A, B, ax, ay, R);
    printMatrix(R, ax, ay);
    printf("Matrix P:\n");
    int P[MATRIX_SIZE][MATRIX_SIZE];
    calculatePMatirx(A, B, ax, ay, P);
    printMatrix(P, ax, ay);
    return 0;
}