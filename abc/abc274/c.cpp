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
    int n;
    cin >> n;
    v1d ans(2*n + 2);
    ans[0] = 0;
    rep(i, n)
    {
        int x;
        cin >> x;
        ans[2*i+1] = ans[x-1] + 1;
        ans[2*i+2] = ans[x-1] + 1;
        // debug(ans);
    }
    rep(i, 2*n+1)
    {
        cout << ans[i] << endl;
    }

}
