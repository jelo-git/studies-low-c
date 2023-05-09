#include <stdio.h>
#include <string.h>
#define NUMBER_OF_PARAMETERS 4
double calculateAverage(double params[NUMBER_OF_PARAMETERS])
{
    double sum = 0.0;
    for (int n = 0; n < NUMBER_OF_PARAMETERS; n++)
    {
        sum += params[n];
    }
    return (sum / NUMBER_OF_PARAMETERS);
}
double findMax(double params[NUMBER_OF_PARAMETERS])
{
    double max = params[0];
    for (int n = 1; n < NUMBER_OF_PARAMETERS; n++)
    {
        if (params[n] > max)
            max = params[n];
    }
    return max;
}
double findMin(double params[NUMBER_OF_PARAMETERS])
{
    double min = params[0];
    for (int n = 1; n < NUMBER_OF_PARAMETERS; n++)
    {
        if (params[n] < min)
            min = params[n];
    }
    return min;
}
int main()
{
    FILE *file;
    file = fopen("Pomiary.txt", "r");
    if (file == NULL)
    {
        printf("File can't be opened\n");
        return 1;
    }
    char *line = NULL;
    size_t len = 0, read;
    double (*func[])(double arr[NUMBER_OF_PARAMETERS]) = {calculateAverage,
                                                          findMax,
                                                          findMin};
    FILE *out;
    out = fopen("Wyniki.txt", "w");
    if (!out)
    {
        printf("File can't be opened\n");
        return 1;
    }
    while ((read = getline(&line, &len, file)) != -1)
    {
        int n = 0, serieno;
        char *tmp = strtok(line, ";");
        double params[NUMBER_OF_PARAMETERS];
        while (tmp != NULL)
        {
            if (n > 0)
            {
                if (n == NUMBER_OF_PARAMETERS + 1)
                {
                    int oper;
                    sscanf(tmp, "%i", &oper);
                    if (oper < 0 || oper > 2)
                    {
                        printf("Wrong operation number.\n");
                        return 1;
                    }
                    double output = func[oper](params);
                    fprintf(out, "%i;%.4lf;%i\n", serieno, output, oper);
                    n += 1;
                    break;
                }
                sscanf(tmp, "%lf", &params[n - 1]);
            }
            else
            {
                sscanf(tmp, "%i", &serieno);
            }
            tmp = strtok(NULL, ";");
            n += 1;
        }
        if (n <= NUMBER_OF_PARAMETERS + 1)
        {
            printf("Bad input data.\n");
            return 1;
        }
    }
    fclose(file);
    fclose(out);
    return 0;
}