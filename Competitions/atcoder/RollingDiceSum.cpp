#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A;
    cin >> B;
    if (B > A * 6 || B < A)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}