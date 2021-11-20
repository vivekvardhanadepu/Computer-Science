#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n;
        string order;
        cin >> n;
        cin >> order;
        bool isSolved[26] = {false};
        int i;
        assert(n == order.length());

        for (i = 0; i < n; i++)
        {
            if (isSolved[order[i] - 'A'] && order[i] != order[max(0, i - 1)])
            {
                cout << "NO" << endl;
                break;
            }
            isSolved[order[i] - 'A'] = true;
        }
        if (i == order.length())
            cout << "YES" << endl;
    }
    return 0;
}