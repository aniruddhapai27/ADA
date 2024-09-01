#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int count = 0;

int strMat(char *text, char *pattern, int n, int m)
{
    int i, j;
    for (i = 0; i <= n - m; i++)
    {
        j = 0;
        while (j < m)
        {
            count++;
            if (pattern[j] != text[i + j])
            {
                break;
            }
            j++;
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}
void tester()
{
    int m, n;
    char text[100], pattern[100];

    printf("Enter text length: ");
    scanf("%d", &n);

    printf("Enter text: \n");
    getchar();
    fgets(text, sizeof(text), stdin);

    printf("Enter pattern length: ");
    scanf("%d", &m);

    printf("Enter pattern: \n");
    getchar();
    fgets(pattern, sizeof(pattern), stdin);

    int idx = strMat(text, pattern, n, m);
    if (idx == -1)
    {
        printf("Pattern not found\n");
    }
    else
    {
        printf("Pattern is found at index: %d\n", idx);
    }
}

void plotter()
{
    FILE *f1, *f2, *f3;
    f1 = fopen("best.txt", "w");
    f2 = fopen("avg.txt", "w");
    f3 = fopen("worst.txt", "w");
    srand(time(NULL));
    char *text = (char *)malloc(1000 * sizeof(char));
    char *pattern;
    for (int i = 0; i < 1000; i++)
    {
        *(text + i) = 'a';
    }
    int m, n;
    n = 1000;
    m = 10;

    while (m <= 1000)
    {
        pattern = (char *)malloc(m * sizeof(char));

        // best case
        for (int i = 0; i < m; i++)
        {
            pattern[i] = 'a';
        }
        count = 0;
        strMat(text, pattern, n, m);
        fprintf(f1, "%d\t%d\n", m, count);

        // Average case
        for (int i = 0; i < m; i++)
        {
            pattern[i] = 97 + rand() % 3;
        }
        count = 0;
        strMat(text, pattern, n, m);
        fprintf(f2, "%d\t%d\n", m, count);

        // best case
        for (int i = 0; i < m; i++)
        {
            pattern[i] = 'a';
        }
        pattern[m - 1] = 'b';
        count = 0;
        strMat(text, pattern, n, m);
        fprintf(f3, "%d\t%d\n", m, count);

        if (m < 100)
        {
            m += 10;
        }
        else
        {
            m += 100;
        }
        free(pattern);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1- Tester\n2- Plotter\n0- Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            tester();
            break;
        case 2:
            plotter();
            break;
        default:
            return 0;
        }
    }
}