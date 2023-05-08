#include <stdio.h>
#include <string.h>
int main()
{
    FILE *file, *output;
    char name[32];
    printf("Enter the name of your test file (sample at 'task8sample.txt'): ");
    scanf("%s", name);
    file = fopen(name, "r");
    if (file == NULL)
    {
        printf("File can't be opened\n");
        return 1;
    }
    output = fopen("task8calculated.output.txt", "w");
    char *line = NULL, outsum[256], outavg[256];
    size_t len = 0, read;
    int sum[128] = {0}, counts[128] = {0}, maxlen = 0;
    while ((read = getline(&line, &len, file)) != -1)
    {
        int n = 0;
        char *tmp = strtok(line, " ");
        while (tmp != NULL)
        {
            int num;
            sscanf(tmp, "%d", &num);
            sum[n] += num;
            counts[n] += 1;
            tmp = strtok(NULL, " ");
            n += 1;
        }
        if (maxlen < n)
        {
            maxlen = n;
        }
    }
    strcpy(outsum, "");
    sprintf(outsum, "%s", "Suma: ");
    strcpy(outavg, "");
    sprintf(outavg, "%s", "Srednia: ");
    for (int n = 0; n < maxlen; n++)
    {
        sprintf(outsum + strlen(outsum), "%d ", sum[n]);
        sprintf(outavg + strlen(outavg), "%.1f ", (float)sum[n] / counts[n]);
    }
    printf("%s\n", outsum);
    printf("%s\n", outavg);
    fprintf(output, "%s\n", outsum);
    fprintf(output, "%s\n", outavg);
    fclose(output);
    fclose(file);
    return 0;
}