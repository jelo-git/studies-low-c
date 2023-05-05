#include <stdio.h>
int main()
{
    FILE *file;
    char name[32];
    printf("Enter the name of your test file (sample at 'task1sample.txt'): ");
    scanf("%s", name);
    file = fopen(name, "r");
    if (file == NULL)
    {
        printf("File can't be opened\n");
        return 1;
    }
    printf("Specify the character to be counted: ");
    char tmp, ch;
    scanf("%s", &ch);
    int count = 0;
    do
    {
        tmp = fgetc(file);
        if (ch == tmp)
            count += 1;
    } while (tmp != EOF);
    fclose(file);
    printf("Number of occurrences: %i\n", count);
    return 0;
}