#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
using v1d = vector<int>;
using v2d = vector<vector<int>>;

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
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 10e8;
    ll na, nb, nc;
    rep(i, 200000+5)
    {
        nc = i;
        na = max(0ll, x - nc/2);
        nb = max(0ll, y - nc/2);
        if (na < 0 || nb < 0 || nc < 0)
            continue;
        ans = min(a*na+b*nb+c*nc, ans);
    }
    cout << ans << endl;
}

