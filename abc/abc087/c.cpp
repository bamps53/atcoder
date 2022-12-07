#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
using v1d = vector<int>;
using v2d = vector<vector<int>>;

#ifdef LOCAL
#include "../../debug_print.hpp"
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template <typename T>
void chmin(T &a, T b)
{
    a = min(a, b);
}
template <typename T>
void chmax(T &a, T b)
{
    a = max(a, b);
}
template <typename T>
void cin_v(vector<T> &v)
{
    rep(i, v.size()) cin >> v[i];
}
template <typename T>
void cout_v(vector<T> &v)
{
    rep(i, v.size())
    {
        if (i > 0)
            cout << " ";
        cout << v[i];
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    v1d a1(n);
    v1d a2(n);
    rep(i, n)
    {
        if (i > 0)
        {
            int x;
            cin >> x;
            a1[i] = a1[i - 1] + x;
        }
        else
        {
            cin >> a1[i];
        }
    }
    rep(i, n)
    {
        if (i > 0)
        {
            int x;
            cin >> x;
            a2[i] = a2[i - 1] + x;
        }
        else
        {
            cin >> a2[i];
        }
    }
    int ans = 0;
    debug(a1);
    debug(a2);
    rep(i, n)
    {
        if (i == 0)
            ans = max(ans, a1[i] + a2[n-1]);
        else
            ans = max(ans, a1[i] + a2[n-1] - a2[i-1]);
    }

    cout << ans << '\n';
    // printf("%.20lf\n", ans);
}
