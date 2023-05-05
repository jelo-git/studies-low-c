#include <stdio.h>
#include <string.h>
int main()
{
    FILE *file, *output;
    char name[32];
    printf("Enter the name of your test file (sample at 'task7sample.txt'): ");
    scanf("%s", name);
    file = fopen(name, "r");
    if (file == NULL)
    {
        printf("File can't be opened\n");
        return 1;
    }
    output = fopen("task7converted.output.txt", "w");
    char *line = NULL, opt;
    size_t len = 0, read;
    printf("Enter list format (n for numeric, a for alphanumeric): ");
    scanf("%s", &opt);
    int nums[5] = {0};
    while ((read = getline(&line, &len, file)) != -1)
    {
        char outputline[len + 16];
        int count_asterisks = 0;
        while (line[count_asterisks] == '*')
        {
            count_asterisks++;
        }
        if (count_asterisks > 0)
        {
            nums[count_asterisks - 1]++;
            for (int n = count_asterisks; n < 5; n++)
            {
                nums[n] = 0;
            }
        }
        strcpy(outputline, "");
        for (int i = 1; i < count_asterisks; i++)
        {
            sprintf(outputline + strlen(outputline), "  ");
        }
        switch (opt)
        {
        case 'n':
            // 1.1.1.1.1.
            for (int i = 0; i < 5; i++)
            {
                if (nums[i] == 0)
                {
                    break;
                }
                sprintf(outputline + strlen(outputline), "%d.", nums[i]);
            }
            break;
        case 'a':
            // A.1.a.(1)(a)
            switch (count_asterisks)
            {
            case 1:
                sprintf(outputline + strlen(outputline), "%c.", nums[0] + 64);
                break;
            case 2:
                sprintf(outputline + strlen(outputline), "%i.", nums[1]);
                break;
            case 3:
                sprintf(outputline + strlen(outputline), "%c.", nums[2] + 96);
                break;
            case 4:
                sprintf(outputline + strlen(outputline), "(%i)", nums[3]);
                break;
            case 5:
                sprintf(outputline + strlen(outputline), "(%c)", nums[4] + 96);
                break;
            }
            break;
        }
        sprintf(outputline + strlen(outputline), "%s", line + count_asterisks);
        printf("%s", outputline);
        fprintf(output, "%s", outputline);
    }
    printf("\n");
    fclose(file);
    return 0;
}