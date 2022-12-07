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
    int n, x, y;
    cin >> n >> x >> y;
    set<int> xs, ys, temp_xs, temp_ys;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (i == 0)
        {
            xs.insert(a);
            ys.insert(0);
        }
        else if (i%2==0)
        {
            for(auto temp: xs)
            {
                temp_xs.insert(temp+a);
                temp_xs.insert(temp-a);
            }
            xs = temp_xs;
            temp_xs.clear();
        } 
        else
        {
            for(auto temp: ys)
            {
                temp_ys.insert(temp+a);
                temp_ys.insert(temp-a);
            }
            ys = temp_ys;
            temp_ys.clear();
        } 
    }

    bool x_found = false;
    bool y_found = false;

    for(auto temp: xs)
    {
        if (temp == x)
            x_found = true;
    }
    for(auto temp: ys)
    {
        if (temp == y)
            y_found = true;
    }

    if (x_found && y_found)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
