#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int G[3][3];
        int result = 0;
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                if (j != 1 || k != 1)
                    cin >> G[j][k];

        if (G[0][1] - G[0][0] == G[0][2] - G[0][1])
            result++;
        if (G[1][0] - G[0][0] == G[2][0] - G[1][0])
            result++;
        if (G[2][1] - G[2][0] == G[2][2] - G[2][1])
            result++;
        if (G[1][2] - G[0][2] == G[2][2] - G[1][2])
            result++;
        int diff00 = -G[0][0] + G[2][2];
        int diff01 = -G[0][1] + G[2][1];
        int diff02 = -G[0][2] + G[2][0];
        int diff10 = -G[1][0] + G[1][2];

        if (G[0][0] + diff00 / 2 == G[0][1] + diff01 / 2 && !(diff00 % 2) && !(diff01 % 2))
        {
            result++;
            if (G[0][2] + diff02 / 2 == G[0][1] + diff01 / 2 && !(diff02 % 2))
                result++;
            if (G[1][0] + diff10 / 2 == G[0][1] + diff01 / 2 && !(diff10 % 2))
                result++;
        }
        else if (G[0][1] + diff01 / 2 == G[0][2] + diff02 / 2 && !(diff01 % 2) && !(diff02 % 2))
        {
            result++;
            if (G[1][0] + diff10 / 2 == G[0][1] + diff01 / 2 && !(diff10 % 2))
                result++;
        }
        else if (G[0][2] + diff02 / 2 == G[1][0] + diff10 / 2 && !(diff02 % 2) && !(diff10 % 2))
        {
            result++;
            if (G[0][0] + diff00 / 2 == G[0][2] + diff02 / 2 && !(diff00 % 2))
                result++;
        }
        else if (G[1][0] + diff10 / 2 == G[0][0] + diff00 / 2 && !(diff00 % 2) && !(diff10 % 2))
            result++;
        else if (G[0][0] + diff00 / 2 == G[0][2] + diff02 / 2 && !(diff00 % 2) && !(diff02 % 2))
            result++;
        else if (G[0][1] + diff01 / 2 == G[1][0] + diff10 / 2 && !(diff01 % 2) && !(diff10 % 2))
            result++;

        cout << "Case #" << i << ": " << result << endl;
    }
    return 0;
}