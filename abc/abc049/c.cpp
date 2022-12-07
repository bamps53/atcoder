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

template <typename T>
void chmin(T &a, T b)
{
    a = min(a, b);
}
template <typename T>
void chmax(T &a, T b)
{
    a = max(a, b);
}
template <typename T>
void cin_v(vector<T> &v)
{
    rep(i, v.size()) cin >> v[i];
}
template <typename T>
void cout_v(vector<T> &v)
{
    rep(i, v.size())
    {
        if (i > 0)
            cout << " ";
        cout << v[i];
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;

    while (s.size() > 0)
    {
        if (s.size() >=5 && s.substr(s.size() - 5) == "dream")
        {
            s = s.substr(0, s.size() - 5);
        }
        else if (s.size() >=7 && s.substr(s.size() - 7) == "dreamer")
        {
            s = s.substr(0, s.size() - 7);
        }
        else if (s.size() >=5 && s.substr(s.size() - 5) == "erase")
        {
            s = s.substr(0, s.size() - 5);
        }
        else if (s.size() >=6 && s.substr(s.size() - 6) == "eraser")
        {
            s = s.substr(0, s.size() - 6);
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
