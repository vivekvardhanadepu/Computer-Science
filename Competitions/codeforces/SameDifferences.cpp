#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        long long int n;
        cin >> n;
        vector<long long int> v;
        long long int x;
        for (long long int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x - i);
        }
        sort(v.begin(), v.end());
        long long int ans = 0;
        vector<long long int> a;
        for (long long int i = 1; i < n; i++)
        {
            if (v[i] == v[i - 1])
                ans++;
            else
            {
                if (ans > 0)
                {
                    ans++;
                    a.push_back(ans);
                    ans = 0;
                }
            }
        }
        if (ans > 0)
        {
            ans++;
            a.push_back(ans);
            ans = 0;
        }
        long long int p = 0;
        for (long int i = 0; i < a.size(); i++)
        {
            p += a[i] * (a[i] - 1) / 2;
        }

        cout << p << endl;
    }

    return 0;
}