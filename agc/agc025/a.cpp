#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)

void print_vec(vector<int> v)
{
    rep(i, v.size())
    {
        if (i > 0)
        {cout << " ";}
        cout << v[i];
    }
    cout << endl;
}

ll SumOfDigits(ll x)
{
    string s = to_string(x);
    ll sum = 0;
    for (auto ch: s)
    {
        sum += ch - '0';
    }
    return sum;
}
int main()
{
    ll n, a, b;
    cin >> n;
    ll min_sum = 10e9;
    rep2(i, 1, n)
    {
        a = i;
        b = n - a;
        min_sum = min(min_sum, SumOfDigits(a)+SumOfDigits(b));
    }
    cout << min_sum << endl;
}

