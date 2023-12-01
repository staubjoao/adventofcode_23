#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char input;
    char output[3];
    int times;
    int sum = 0;
    int aux;

    FILE *in_file = fopen("input.txt", "r");

    times = 0;
    do
    {
        input = fgetc(in_file);
        if (input == '\n' || input == EOF)
        {
            if (times == 1)
            {
                output[1] = output[0], times = 0;
            }
            sum += atoi(output);
            times = 0;
        }
        else
        {
            aux = (int)input - 48;
            if (aux >= 0 && aux <= 9)
            {
                if (times == 2)
                    output[times - 1] = input;
                else
                    output[times++] = input;
            }
        }
    } while (input != EOF);

    printf("sum: %d\n", sum);
    return 0;
}