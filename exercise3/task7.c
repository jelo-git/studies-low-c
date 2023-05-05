#include <stdio.h>
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
    char *line = NULL, opt;
    size_t len = 0, read;
    printf("Enter list format (n for numeric, a for alphanumeric): ");
    scanf("%s", &opt);
    int nums[5] = {0};
    while ((read = getline(&line, &len, file)) != -1)
    {
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
        for (int i = 1; i < count_asterisks; i++)
        {
            printf("  ");
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
                printf("%d.", nums[i]);
            }
            break;
        case 'a':
            // A.1.a.(1)(a)
            switch (count_asterisks)
            {
            case 1:
                printf("%c.", nums[0] + 64);
                break;
            case 2:
                printf("%i.", nums[1]);
                break;
            case 3:
                printf("%c.", nums[2] + 96);
                break;
            case 4:
                printf("(%i)", nums[3]);
                break;
            case 5:
                printf("(%c)", nums[4] + 96);
                break;
            }
            break;
        }
        printf("%s", line + count_asterisks);
    }
    printf("\n");
    fclose(file);
    return 0;
}