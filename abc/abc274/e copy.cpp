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

int main()
{
    int n, m;
    cin >> n >> m;
    v1d xs(n);
    v1d ys(n);
    v1d ps(m);
    v1d qs(m);
    rep(i, n)
    {
        cin >> xs[i] >> ys[i];
    }
    rep(i, m)
    {
        cin >> ps[i] >> qs[i];
    }

    v2d dp(1<<(n+m), v1d((n+m), INFINITY));
    dp[0][0] = 0;
    
    rep(i, 1<<(n+m))
    

}
