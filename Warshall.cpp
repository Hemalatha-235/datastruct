
#include <stdio.h>

#define MAX 20
#define INF 10000000

int n, d[MAX][MAX];

void floyd()
{
    int i, j, k;

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (d[i][k] < INF && d[k][j] < INF &&
                    d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    printf("Enter cost matrix (use %d for INF):\n", INF);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }

    floyd();

    printf("All-pairs shortest distance matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (d[i][j] >= INF)
                printf("%6s", "INF");
            else
                printf("%6d", d[i][j]);
        }
        printf("\n");
    }

    return 0;
}
