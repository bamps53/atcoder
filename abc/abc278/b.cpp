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

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cin_v(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void cout_v(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}

bool is_misunderstood(int h, int m)
{
    int a = h / 10;
    int b = h % 10;
    int c = m / 10;
    int d = m % 10;

    int new_h = a * 10 + c;
    int new_m = b * 10 + d;

    if (new_h < 24 && new_m < 60)
        return true;
    else
        return false;
}

int main()
{
    int h, m;
    cin >> h >> m;
    while(!is_misunderstood(h, m))
    {
        m++;
        if (m >= 60)
        {
            h++;
            m = m % 60;
        }
        if (h >= 24)
        {
            h = h % 24;
        }
    }
    cout << h << " " << m << endl;
    return 0;
}
