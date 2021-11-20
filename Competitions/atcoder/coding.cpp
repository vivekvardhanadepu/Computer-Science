#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A;
    cin >> B;
    if (B - A < 0)
        cout << "0";
    else
        cout << B - A + 1;
    return 0;
}