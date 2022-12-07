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
	int n, m;
	cin >> n >> m;
	v1d xs(n + m);
	v1d ys(n + m);
	rep(i, n + m)
	{
		cin >> xs[i] >> ys[i];
	}

	auto dist = [](double x1, double y1, double x2, double y2)
	{
		return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	};

	vector<vector<double>> dp(1 << (n + m), vector<double>((n + m), INFINITY));
	// 原点からの距離で初期化
	rep(i, n + m)
	{
		dp[1 << i][i] = dist(0, 0, xs[i], ys[i]);
	}

	debug(1 << (n + m), n+m);
	// bitDP
	rep(i, 1 << (n + m))
	{
		double coef = pow(0.5, __builtin_popcount(i >> n));
		rep(j, n + m)
		{
			// jが訪問済みの場所に含まれなかったらスキップ
			if (!(i & (1 << j)))
				continue;
			// jから次に訪れる場所を埋めていく
			rep(k, n + m)
			{
				// kがすでに訪問済みならスキップ
				if (i & (1 << k))
					continue;
				debug(i ^ (1 << k), k, i, j);
				dp[i ^ (1 << k)][k] = min(dp[i ^ (1 << k)][k], dp[i][j] + dist(xs[j], ys[j], xs[k], ys[k]) * coef);
			}
		}
	}
	double ans = 1.0e10;
	for (int s = (1 << n) - 1; s <= 1 << (n + m); s += (1 << n))
	{
		double coef = pow(0.5, __builtin_popcount(s >> n));
		rep(j, n + m)
		{
			ans = min(ans, dp[s][j] + dist(xs[j], ys[j], 0, 0) * coef);
		}
	}
	// cout << ans << endl;
	printf("%.20lf\n", ans);
}
