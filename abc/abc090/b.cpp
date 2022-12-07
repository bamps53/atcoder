#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    rep2(i, a, b+1)
    {
        auto s = to_string(i);
        int length = static_cast<int>(s.size());
        int half_length = length / 2;
        bool is_loop = true;
        rep(i, half_length)
        {
            if (s[i] != s[length - i - 1])
            {
                is_loop = false;
            }
        }
        if (is_loop)
        {
            ans += 1;
        }
        // bool is_loop = true;
        // if (s[0] != s[4])
        // {is_loop = false;}
        // if (s[1] != s[3])
        // {is_loop = false;}
        // if (is_loop)
        // {
        //     ans += 1;
        // }
    }
    cout << ans << endl;
}
