#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
using v1d = vector<int>;
using v2d = vector<vector<int>>;

// #ifdef LOCAL
// #include "../../debug_print.hpp"
// #define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
// #else
// #define debug(...) (static_cast<void>(0))
// #endif

int main()
{
    int n;
    cin >> n;

    v1d xs(n);
    v1d ys(n);
    v1d hs(n);
    int valid_idx = 0;
    rep(i, n)
    {
        cin >> xs[i] >> ys[i] >> hs[i];
        if (hs[i] > 0)
        {
            valid_idx = i;
        }
    }

    rep(i, 101)
    {
        rep(j, 101)
        {
            int temp_h = hs[valid_idx] + abs(i - xs[valid_idx]) + abs(j - ys[valid_idx]);
            bool is_valid = true;
            rep(k, n)
            {
                if (max(temp_h - abs(i - xs[k]) - abs(j - ys[k]), 0) != hs[k])
                {    
                    is_valid = false;
                    break;
                }
            }
            if(is_valid)
            {
                cout << i << " " << j << " " << temp_h << endl;
                return 0;
            }
        }
    }
}
