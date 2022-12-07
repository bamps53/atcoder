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
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W, n, h, w;
    cin >> H >> W >> n >> h >> w;
    v2d a(H, vector<int>(W));

    v1d min_x(n+1, 1000);
    v1d min_y(n+1, 1000);
    v1d max_x(n+1, 0);
    v1d max_y(n+1, 0);

    unordered_map<int, int> mp;

    rep(i, H)
    {
        rep(j, W)
        {
            int val;
            cin >> val;
            a[i][j] = val;
            min_x[val] = min(min_x[val], i);
            min_y[val] = min(min_y[val], j);
            max_x[val] = max(max_x[val], i);
            max_y[val] = max(max_y[val], j);
            mp[val]++;
        }
    }

    
    rep(i, H-h+1)
    {
        rep(j, W-w+1)
        {
            int num_vals = mp.size();
            rep2(val, 1, n+1)
            {
                
                if (
                    i<=min_y[val] &&
                    i+h>=max_y[val] &&
                    j<=min_x[val] &&
                    j+w>=max_x[val]
                )
                {
                    debug(val, i, i+h, min_y[val], max_y[val]);
                    num_vals--;
                }
            }
            if (j>0)
                cout << " ";
            cout << num_vals;
        }
        cout << endl;
    }

}
