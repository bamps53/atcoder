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
    unordered_map<int, int> mp;
    rep(i, H)
    {
        rep(j, W)
        {
            int x;
            cin >> x;
            a[i][j] = x;
            mp[x]++;
        }
    }
    // debug(a);
    int map_size = mp.size();

    // 削除カウントを初期化
    // unordered_map<int, int> del_mp;
    unordered_map<int, int> del_map[H-h+1][W-w+1];
    rep(k, h)
    {
        rep(l, w)
        {
            del_map[0][0][a[k][l]]++;
        }
    }

    rep(i, H - h + 1)
    {
        rep(j, W - w + 1)
        {
            if (j == 0 && i > 0)
            {
                
                del_map[i][j] = del_map[i - 1][j];
                rep(l, w)
                {
                    // debug(j+l, W);
                    del_map[i][j][a[i - 1][j + l]]--;
                    del_map[i][j][a[i + h - 1][j + l]]++;
                }
            }
            else if (j > 0)
            {
                del_map[i][j] = del_map[i][j - 1];
                rep(k, h)
                {
                    // debug(i+k, H);
                    del_map[i][j][a[i + k][j - 1]]--;
                    del_map[i][j][a[i + k][j + w - 1]]++;
                }
            }

            int ans = map_size;
            // debug(ans);
            for (auto [k, v] : del_map[i][j])
            {
                // debug(k, v, mp[k]);
                if (mp[k] == v)
                    ans--;
            }
            if (j > 0)
                cout << " ";
            cout << ans;
        }
        cout << endl;
    }
}
