#include<iostream>

#define MAX 50
using namespace std;

int M, N;
char MAP[MAX][MAX];

int Min(int A, int B) { if (A < B) return A; return B; }

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }
    }
}

int Estimate_Num(int a)
{
    if (a % 2 == 0) return 0;
    else return 1;
}

int Make_White_First(int x, int y)
{
    //x가 0일수도 잇고 1일수도 잇어
    //y도 0일수도 잇고 1일수도 잇어
    int Cnt = 0;

    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if (i == x || i == x + 2 || i == x + 4 || i == x + 6)
            {
                if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
                {
                    if (MAP[i][j] != 'W') Cnt++;
                }
                else
                {
                    if (MAP[i][j] != 'B') Cnt++;
                }
            }
            else
            {
                if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
                {
                    if (MAP[i][j] != 'B') Cnt++;
                }
                else
                {
                    if (MAP[i][j] != 'W') Cnt++;
                }
            }
        }
    }
    return Cnt;
}

int Make_Black_First(int x, int y)
{
    int Cnt = 0;

    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if (i == x || i == x + 2 || i == x + 4 || i == x + 6)
            {
                if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
                {
                    if (MAP[i][j] != 'B') Cnt++;
                }
                else
                {
                    if (MAP[i][j] != 'W') Cnt++;
                }
            }
            else
            {
                if (j == y || j == y + 2 || j == y + 4 || j == y + 6)
                {
                    if (MAP[i][j] != 'W') Cnt++;
                }
                else
                {
                    if (MAP[i][j] != 'B') Cnt++;
                }
            }
        }
    }
    return Cnt;
}

void Make_Chess()
{
    int White_First_Min;
    int Black_First_Min;
    int Total_Min = 9999;

    for (int i = 0; i < N; i++)
    {
        if (i + 8 > N) break;
        for (int j = 0; j < M; j++)
        {
            if (j + 8 > M) break;

            White_First_Min = Make_White_First(i, j);
            Black_First_Min = Make_Black_First(i, j);
            Total_Min = Min(Total_Min, Min(White_First_Min, Black_First_Min));
        }
    }
    cout << Total_Min << endl;
}

void Solution()
{
    Make_Chess();
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}
