#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
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
	int n;
	cin >> n;
	v1d a(n);
	rep(i, n)
	{
		cin >> a[i];
	}
	v1d l_max(n+1, 0);
	v1d r_max(n+1, 0);
	rep(i, n)
	{
		l_max[i+1] = max(a[i], l_max[i]);
		r_max[n-1-i] = max(a[n-1-i], r_max[n-i]);
	}
	// debug(1);
	// debug(2);
	int d;
	cin >> d;
	int l, r, ans;
	rep(i, d)
	{
		cin >> l >> r;
		ans = max(l_max[l-1], r_max[r]);
		cout << ans << endl;
	}
	debug(a);
	debug(l_max);
	debug(r_max);
	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
    // cout << fixed;
    // cout << setprecision(3) << c << endl;
}
