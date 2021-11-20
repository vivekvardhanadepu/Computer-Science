#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n, l, r;
        cin >> n;
        cin >> l;
        cin >> r;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        int i;
        for (i = 0; i < n; i++)
            if (arr[i] >= l)
                break;
        arr.erase(arr.begin(), arr.begin() + i);
        n = arr.size();
        i = n;
        while (arr[i--] >= r)
            ;
        arr.erase(arr.begin() + i, arr.end());
        n = arr.size();
        int count = 0;
        int left = 0, right = n - 1;
        while (left < right)
        {
            if
        }
    }
    return 0;
}