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
        {
            cout << " ";
        }
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    int h, m;
    cin >> h >> m;
    rep(i, 24)
    {
        rep(j, 60)
        {
            int temp_h = h + i;
            int temp_m = m + j;
            if (temp_m >= 60)
            {
                temp_h++;
                temp_m = temp_m % 60;
            }
            if (temp_h >= 24)
            {
                temp_h = temp_h % 24;
            }

            char a, b, c, d;
            if (temp_h < 10)
            {
                a = '0';
                b = to_string(temp_h)[0];
            }
            else
            {
                string temp_hs = to_string(temp_h);
                a = temp_hs[0];
                b = temp_hs[1];
            }
            if (temp_m < 10)
            {
                c = '0';
                d = to_string(temp_m)[0];
            }
            else
            {
                string temp_ms = to_string(temp_m);
                c = temp_ms[0];
                d = temp_ms[1];
            }

            string new_hs = "00";
            new_hs[0] = a;
            new_hs[1] = c;
            string new_ms = "00";
            new_ms[0] = b;
            new_ms[1] = d;

            // cout << a << b << " " << c << d << endl;
            // debug(a, b, c, d);

            // debug(new_hs);
            // debug(new_ms);
            int new_h = stoi(new_hs);
            int new_m = stoi(new_ms);
            if (new_h < 24 && new_m < 60)
            {
                cout << a << b << " " << c << d << endl;
                return 0;
            }
        }
    }
}
