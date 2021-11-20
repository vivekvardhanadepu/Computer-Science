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
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        if (sum % n != 0)
        {
            cout << -1 << endl;
            continue;
        }
        int avg = sum / n;
        int count = 0;
        for (int i = 0; i < n; i++)
            if (arr[i] > avg)
                count++;
        cout << count << endl;
    }
    return 0;
}