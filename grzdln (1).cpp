#include <stdio.h>

#define MAX_N 1000

struct coordinate
{
    int x;
    int y;
};

int map[MAX_N][MAX_N];
bool odw[MAX_N][MAX_N];
coordinate stack[MAX_N*MAX_N];
int n, stackSize, grzbiet, dolina;

void Szukaj(coordinate xy)
{
    int x, y;
    odw[xy.x][xy.y] = 1;
    stackSize = 1;
    stack[0] = xy;
    while(stackSize)
    {
        stackSize--;
        x = stack[stackSize].x;
        y = stack[stackSize].y;
        for(int i = x - 1; i <= x + 1; i++)
            for(int j = y - 1; j <= y + 1; j++)
            {
                if(i >= 0 && i < n && j >= 0 && j < n)
                {
                    if(map[i][j] == map[x][y] && !odw[i][j])
                    {
                        odw[i][j] = 1;
                        xy.x = i;
                        xy.y = j;
                        stack[stackSize] = xy;
                        stackSize++;
                    }
                    else if(map[i][j] < map[x][y]) dolina = 0;
                    else if(map[i][j] > map[x][y]) grzbiet = 0;
                }
            }
    }
}

int main()
{
    int grzbiety = 0, doliny = 0;
    coordinate xy;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            odw[i][j] = 0;
            scanf("%d", &map[i][j]);
        }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(!odw[i][j])
            {
               grzbiet = 1;
               dolina = 1;
               xy.x = i;
               xy.y = j;
               Szukaj(xy);
               grzbiety += grzbiet;
               doliny += dolina;

            }
        }
    printf("%d %d\n", grzbiety, doliny);
    return 0;
}
