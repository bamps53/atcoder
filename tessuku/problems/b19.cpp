#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, W;
	cin >> n >> W;

	v1dll ws(n);
	v1dll vs(n);
	rep(i, n)
	{
		cin >> ws[i] >> vs[i];
	}

	constexpr ll v_max = 100001;
	v2dll dp(n+1, v1dll(v_max, 10e10));

	dp[0][0] = 0;
	rep(i, n)
	{
		rep(j, v_max)
		{
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			if (j+vs[i] < v_max)
				dp[i+1][j+vs[i]] = min(dp[i+1][j+vs[i]], dp[i][j] + ws[i]);
		}
	}
	// debug(dp);
	int ans = 0;
	rep(j, v_max)
	{
		if (0 <= dp[n][j] && dp[n][j] <= W)
		{
			ans = max(ans, j);
		}
	}
	cout << ans << endl;




	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
