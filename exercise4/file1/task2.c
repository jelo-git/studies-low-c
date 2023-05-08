#include <stdio.h>
#include <string.h>
#include <math.h>
// compile with '-lm' parameter
double calculateB(double num)
{
    if (num <= -1)
    {
        return 3.31;
    }
    return (pow(sin(num), 2) - 3) / (sqrt(num + 1));
}
int main()
{
    FILE *file;
    char name[32];
    printf("Enter the name of your test file (sample at 'task2sample.txt'): ");
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
    double A[50][50], B[50][50];
    while ((read = getline(&line, &len, file)) != -1)
    {
        int n = 0;
        char *tmp = strtok(line, " ");
        while (tmp != NULL)
        {
            double num;
            sscanf(tmp, "%lf", &num);
            A[msize][n] = num;
            B[msize][n] = calculateB(num);
            tmp = strtok(NULL, " ");
            n += 1;
        }
        if (n >= 50 || msize >= 50)
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
    printf("A Matix:\n");
    for (int n = 0; n < msize; n++)
    {
        for (int m = 0; m < nsize; m++)
        {
            printf("%.2f ", A[n][m]);
        }
        printf("\n");
    }
    printf("B Matix:\n");
    for (int n = 0; n < msize; n++)
    {
        for (int m = 0; m < nsize; m++)
        {
            printf("%.2f ", B[n][m]);
        }
        printf("\n");
    }

    return 0;
}