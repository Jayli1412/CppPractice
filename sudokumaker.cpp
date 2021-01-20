#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <windows.h>

#define Max_Size 9
int Map[Max_Size][Max_Size];
int Mapsize;
int x_size;
int y_size;
int t1;
int t2;

void gotoxy(int x,int y);
void MakeMap();
void PrintMap();
void SetblockSize();
int GetUniqueNumber(int x, int y);

int Menu();
int main()
{
    int ch, End = 1;
    srand((unsigned)time(NULL));
    End = Menu();
    while(End)
    {
        system("cls");
        MakeMap();
        PrintMap();
        ch = getch();
        if(ch == 27) End = Menu();
    }
}

void MakeMap()
{
    int i, j, num, cnt = 0, n = 0, progress = -1;
    int Cell[Max_Size];
    memset(Map, 0, sizeof(Map));
    t1 = clock();
    for(i = 0, j = 0; i < Mapsize; )
    {
        if(progress != i)
        {
            gotoxy(0, 0);
            printf("i = ");
            for(n = 0; n < Mapsize; n++)i>=n? printf("%2d", n + 1) : printf(" ");
            puts("");
            progress = i;
        }
        if (num = GetUniqueNumber(j, i)) {
            Map[i][j] = num;
            ++j == Mapsize ? i++, j= 0, cnt=0 :0;
        }
        else if (++cnt < i * 50) 
        {
            memset(Map[i], 0, sizeof(Map[i]));
            j = 0;
        }
        else 
        {
            while(i % y_size)
            {
                memset(Map[i--], 0, sizeof(Map[i]));    
            }
            memset(Map[i], 0, sizeof(Map[i]));
            j = cnt = 0;
        }
    }
    //getch();
    t2 = clock();
}


int getUniqueNumber(int x, int y)
{
    int i, j, col, row, idx = 0;
    int Cell[Max_Size], Temp[Max_Size + 1] = {0,};

    col = (x / x_size) * x_size;
    row = (y / y_size) * y_size;
    for(i = row; i < y_size + row; i++)
    {
        for(j = col; j < x_size + col; j++)
        {
            Temp[Map[i][j]] = 1;
        }
    }
    for (i = 0; i < MapSize; i++) 
    {
        Temp[Map[y][i]] = 1;
        Temp[Map[i][x]] = 1;
    }
    for(i = 1; i <= MapSize; i++)
    {
        if(!temp[i]) Cell[idx++] = i;
    }
    if(idx == 0) return idx;
    else return Cell[rand() % idx];
}
