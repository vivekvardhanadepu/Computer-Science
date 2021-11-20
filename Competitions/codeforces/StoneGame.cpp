#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (n <= 2)
        {
            cout << n << endl;
            continue;
        }
        int min_index = 0, max_index = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[min_index])
            {
                min_index = i;
            }
            else if (arr[i] > arr[max_index])
                max_index = i;
        }
        int min_moves;

        min_moves = min(max(min_index, max_index) + 1, max(n - min_index, n - max_index));
        min_moves = min(min_moves, min(min_index + 1 + n - max_index, -min_index + 1 + n + max_index));
        cout << min_moves << endl;
    }
    return 0;
}