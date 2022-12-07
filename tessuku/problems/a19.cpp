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

template <typename T>
void sort_all(T& v) { sort(v.begin(), v.end()); }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, W;
	cin >> n >> W;
	vector<ll> vs(n); 
	vector<ll> ws(n); 
	rep(i, n)
	{
		cin >> ws[i] >> vs[i];
	}

	vector<vector<ll>> dp(n+1, vector<ll>(W+1, -1));
	dp[0][0] = 0;

	rep(i, n)
	{
		rep(j, W+1)
		{
			if (dp[i][j]>=0)
			{
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				if (j+ws[i] <= W)
					dp[i+1][j+ws[i]] = max(dp[i+1][j+ws[i]], dp[i][j]+vs[i]);
			}
		}
	}
	ll ans = 0;
	rep(j, W+1)
	{
		ans = max(ans, dp[n][j]);
	}
	cout << ans << endl;




	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
