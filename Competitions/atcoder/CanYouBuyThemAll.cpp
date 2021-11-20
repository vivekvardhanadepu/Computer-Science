#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    cin >> x;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sum = sum + temp;
    }
    sum = sum - (n / 2);
    if (x < sum)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}