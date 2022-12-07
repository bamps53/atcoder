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

    ll n, q;
    cin >> n;
    vector<ll> v(n);

    unordered_map<ll, ll> mp = {};
    ll assigned_value = 0;
    bool assigned = false;

    rep(i, n)
    {
        cin >> v[i];
    }
    cin >> q;
    rep(i, q)
    {
        ll idx;
        cin >> idx;
        if (idx == 1)
        {
            ll a;
            cin >> a;
            assigned = true;
            mp = {};
            assigned_value = a;
            // v.assign(n, a);
        }
        if (idx == 2)
        {
            ll a, b;
            cin >> a >> b; 
            if (!assigned)
                v[a-1] += b;
            else
            {
                mp[a-1] += b;
            }
        }
        if (idx == 3)
        {
            ll a;
            cin >> a;
            if (!assigned)
                cout << v[a-1] << endl;
            else
            {
                cout << assigned_value + mp[a-1] << endl;
            }
        }
        // debug(v);
    }


}
