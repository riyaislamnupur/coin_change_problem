#include<stdio.h>

int count( int S[], int m, int c )
{
    int i, j, x, y;

    int table[c+1][m];

    for (i=0; i<m; i++) // when n = 0, all entries will be 0
        table[0][i] = 1;

    for (i = 1; i < c+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0; // Count of solutions including S[j]

            y = (j >= 1)? table[i][j-1]: 0;  // Count of solutions excluding S[j]

            table[i][j] = x + y;
        }
    }
    return table[c][m-1];
}
int main()
{
    int arr[] = { 1, 3, 4, 7};
    int m = sizeof(arr)/sizeof(arr[0]);
    int c = 10;
    printf("%d ", count(arr, m, c));
    return 0;
}
