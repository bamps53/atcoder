#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)


int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    rep(i, n)
    {cin >> v[i];}

    int g = 0;
    for (const auto& x: v)
    {
        g = gcd(g, x);
    }

    int ans = 0;
    for (auto& x :v)
    {
        x /= g;
        while(x%2 == 0)
        {
            x /= 2;
            ans++;
        }
        while (x%3 == 0)
        {
            x /= 3;
            ans++;
        }
        if (x != 1)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}

