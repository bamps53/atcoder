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
    int n, q;
    cin >> n >> q;
    unordered_map<int, unordered_map<int, int>> mp;
    rep(i, q)
    {
        int t, a, b;
        cin >> t >> a >> b;
        // debug(t, a, b);
        if (t == 1)
        {
            mp[a][b] = 1;
        }
        if (t == 2)
        {
            mp[a][b] = 0;
        }
        if (t == 3)
        
        {
            if (mp[a][b] > 0 && mp[b][a] > 0)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}
