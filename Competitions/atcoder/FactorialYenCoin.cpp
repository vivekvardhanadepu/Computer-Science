#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int P;
    cin >> P;
    vector<int> factorials(10);
    for (int i = 1; i < 11; i++)
        factorials[i - 1] = factorial(i);
    int count = 0;
    for (auto i = factorials.rbegin(); i != factorials.rend(); i++)
    {
        int no = (int)(P / (*i));
        no = min(no, 100);
        P -= no * (*i);
        count += no;
    }
    cout << count;
    return 0;
}