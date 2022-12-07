#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
#define endl '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
using v1d = vector<int>;
using v2d = vector<vector<int>>;
using v1dll = vector<ll>;
using v2dll = vector<vector<ll>>;

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

template <typename T>
void sort_all(T& v) { sort(v.begin(), v.end()); }

template <typename T>
void reverse_all(T& v) { reverse(v.begin(), v.end()); }

vector<vector<int>> make_v2d(int d1, int d2, int value)
{
	v2d x(d1, v1d(d2, value));
	return x; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	/**
	 * dp[m][1<<n]のテーブルを埋めていく。
	 * 値はビットが立っている商品が無料で買える最小枚数
	 * 初期値はINF
	 * dp[0][0]は0
	 * dp[m][1<<n]が答え
	 * 選ぶか選ばないかを繰り返して埋めていく
	 */
	int n, m;
	cin >> n >> m;
	v1d a(m, 0);
	rep(i, m)
	{
		rep(j, n)
		{
			int x;
			cin >> x;
			a[i] += (1 << j) * x;
		}
	}
	debug(a);

	v2d dp = make_v2d(m+1, 1<<n, inf);
	dp[0][0] = 0;
	rep(i, m)
	{
		auto bit = a[i];
		rep(j, 1<<n)
		{
			if (dp[i][j] < inf)
			{
				dp[i+1][j | bit] = min(dp[i+1][j | bit], dp[i][j] + 1);
				dp[i+1][j] = min(dp[i+1][j | bit], dp[i][j]);
			}
		}
	}
	debug(dp);

	if (dp[m][(1<<n)-1] < inf)
		cout << dp[m][(1<<n)-1] << '\n';
	else
		cout << -1 << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
