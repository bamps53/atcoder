#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)


int main()
{
    int n;
    cin >> n;
    long long min_value = 10e9;
    long long max_profit = -10e9;
    rep(i, n)
    {
        long long x;
        cin >> x;
        long long profit = x - min_value;
        max_profit = max(max_profit, profit);
        min_value = min(min_value, x);
    }
    cout << max_profit << endl;
}

