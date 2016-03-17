#include <bits/stdc++.h>

using namespace std;

int field[8][8];

int main()
{
    for (int i = 7; i >= 0; --i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 8; ++j)
            if (s[j] == 'W')
                field[j][i] = 1;
            else if (s[j] == 'B')
                field[j][i] = 2;
    }
    int ansa = 1e9, ansb = 1e9;
    for (int i = 0; i < 8; ++i)
    {
        int lasta = -1e9, isb = 0;
        for (int j = 0; j < 8; ++j)
            if (field[i][j] == 1)
            {
                lasta = j;
                isb = 0;
            }
            else if (field[i][j] == 2)
                isb = 1;
        if (!isb)
            ansa = min(ansa, 7 - lasta);
    }
    for (int i = 0; i < 8; ++i)
    {
        int lastb = 1e9, isa = 0;
        for (int j = 7; j >= 0; --j)
            if (field[i][j] == 2)
            {
                lastb = j;
                isa = 0;
            }
            else if (field[i][j] == 1)
                isa = 1;
        if (!isa)
            ansb = min(ansb, lastb);
    }
    if (ansa <= ansb)
        printf("A");
    else
        printf("B");
    return 0;
}


/*
..B.....
........
........
..W.....
..WBW...
..W.W...
..W.W...
..W.W...
*/
