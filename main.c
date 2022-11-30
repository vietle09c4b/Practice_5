#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef unsigned short u2;
#define TC 1
u2 fs_day_number(u2 n, u2 m, u2 arr[][50]);
int main()
{
    u2 n, m;
    u2 arr[50][50];
    memset(arr, 0, sizeof(arr));
#if TC == 1
    n = 2, m = 2, arr[1][1] = 1;
#elif TC == 2
    n = 1, m = 1, arr[1][1] = 1;
    #elif TC == 3
    n = 5, m = 5, arr[1][1] = 1, arr[2][2] = 1,arr[3][3] = 1, arr[4][4] = 1, arr[5][5] = 1;
    #elif TC == 4
    n = 1, m = 7, arr[1][3] = 1;
    #elif TC == 5
    n = 3, m = 7, arr[2][4] = 1;
#endif
    printf("Minimum days: %d\n", fs_day_number(n, m, arr) - 1);
    return 0;
}
u2 fs_day_number (u2 n, u2 m, u2 arr[][50])
{
    u2 day = 1;
    while (1)
    {
        bool rotten_apple = true;
        for (u2 i = 1; i <= n; i++)
        {
            for (u2 j = 1; j <= m; j++)
            {
                if (arr[i][j] == day) // check position of Rotten Apples
                {
                    if (i - 1 > 0)
                    {
                        if (arr[i - 1][j] == 0)
                        {
                            rotten_apple = false;
                            arr[i - 1][j] = day + 1;
                        }
                    }
                    if (j - 1 > 0)
                    {
                        if (arr[i][j - 1] == 0)
                        {
                            rotten_apple = false;
                            arr[i][j - 1] = day + 1;
                        }
                    }
                    if (j + 1 <= m)
                    {
                        if (arr[i][j + 1] == 0)
                        {
                            rotten_apple = false;
                            arr[i][j + 1] = day + 1;
                        }
                    }
                    if (i + 1 <= n)
                    {
                        if (arr[i + 1][j] == 0)
                        {
                            rotten_apple = false;
                            arr[i + 1][j] = day + 1;
                        }
                    }
                }
            }
        }
        if (rotten_apple) // check condition: all apples are rotten in order to exit loop
        {
            break;
        }
        day++;
    }
    return day;
}