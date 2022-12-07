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
	int h, w;
	cin >> h >> w;
	// int v[h+1][w+1];
	vector<vector<ll>> v(h+1, vector<ll>(w+1));

	v[0][0] = 0;
	rep(i, h)
	{
		v[i+1][0] = 0;
	}
	rep(j, w)
	{
		v[0][j+1] = 0;
	}

	rep(i, h)
	{
		rep(j, w)
		{
			ll x;
			cin >> x;
			v[i+1][j+1] = v[i][j+1] + v[i+1][j] + x - v[i][j];
		}
	}
	int q;
	cin >> q;
	rep(i, q)
	{
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		// debug(v[d][c], v[b-1][c], v[d][a-1], v[b-1][a-1]);
		cout << v[c][d] - v[a-1][d] - v[c][b-1] + v[a-1][b-1] << endl;
	}
	debug(v);

	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
    // cout << fixed;
    // cout << setprecision(3) << c << endl;
}
