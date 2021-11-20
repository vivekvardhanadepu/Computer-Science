#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    string n1, m1;
    if (!n && !m)
    {
        cout << "0" << endl
             << "0" << endl;
        return 0;
    }
    while (n && m)
    {
        int rem_n = n % 10;
        int rem_m = m % 10;
        if (rem_n >= rem_m)
            n1.insert(0, 1, '0' + rem_n);
        if (rem_m >= rem_n)
            m1.insert(0, 1, '0' + rem_m);
        n /= 10;
        m /= 10;
    }
    n1 = to_string(stoi(n1));
    m1 = to_string(stoi(m1));
    if (n)
    {
        n1 = to_string(n) + n1;
    }
    if (m)
        m1 = to_string(m) + m1;
    if (n1.empty())
        cout << "YODA" << endl;
    else
        cout << n1 << endl;
    if (m1.empty())
        cout << "YODA" << endl;
    else
        cout << m1 << endl;
    return 0;
}