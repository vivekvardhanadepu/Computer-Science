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
        vector<int> digits;
        while (n != 0)
        {
            digits.push_back(n % 10);
            n = n / 10;
        }
        int count = 9 * (digits.size() - 1);
        bool flag = true;
        for (int i = digits.size() - 2; i >= 0; i--)
        {
            if (digits[i] > digits.back())
                break;
            if (digits[i] < digits.back())
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            count = count + digits.back();
        }
        else
        {
            count = count + digits.back() - 1;
        }
        cout << count << endl;
    }
    return 0;
}