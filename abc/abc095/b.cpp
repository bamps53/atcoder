#include <bits/stdc++.h>
using namespace std;
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

int main()
{
    int n, x;
    cin >> n >> x;
    int m;
    int sum = 0;
    int min_m = 10e5;
    int ans = 0;
    rep(i, n)
    {
        cin >> m;
        min_m = min(min_m, m);
        sum += m;
        ans++;
    }
    ans += (x - sum) / min_m;

    cout << ans << endl;
}

