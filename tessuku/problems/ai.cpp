#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n';
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
	int n, q;
	cin >> n >> q;
	v1d v(n+1);
	v[0] = 0;
	rep(i, n)
	{
		int x;
		cin >> x;
		v[i+1] = v[i] + x;
	}

	// debug(v);
	rep(i, q)
	{
		int l, r;
		cin >> l >> r;
		cout << v[r] - v[l-1] << '\n';
	}


	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
    // cout << fixed;
    // cout << setprecision(3) << c << endl;
}
