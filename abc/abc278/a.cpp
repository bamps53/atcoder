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
    int n, k;
    cin >> n >> k;
    k = min(n, k);
    v1d v;
    rep(i, n)
    {
        int x;
        cin >> x;
        if (i >= k)
        {
            v.push_back(x);
            // if (i > k)
            //     cout << " ";
            // cout << x;
        }
    }
    rep(i, k)
    {
        v.push_back(0);
        // cout << " ";
        // cout << 0;
    }
    print_vec(v);
}
