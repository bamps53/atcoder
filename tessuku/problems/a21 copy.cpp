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

template <typename T>
void reverse_all(T& v) { reverse(v.begin(), v.end()); }


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	v1d p(n);
	v1d a(n);
	rep(i, n)
	{
		cin >> p[i] >> a[i];
	}

	int left = 0;
	int right = n;

	v2d dp(n+1, v1d(n+1, -1));
	dp[0][0] = 0;

	rep(l, n)
	{
		if (p[l] - 1 < l)
		{
			dp[l+1][0] = dp[l][0];
		}
		else
		{
			dp[l+1][0] = dp[l][0] + a[l];
		}
	}

	rep(temp, n)
	{
		int r = n - temp;
		debug(p[r-1], r);
		if (p[r-1] > r)
		{
			dp[0][temp+1] = dp[0][temp];
		}
		else
		{
			dp[0][temp+1] = dp[0][temp] + a[r-1];
		}
	}

	debug(dp);

	rep(l, n)
	{
		rep(temp, n)
		{
			int r = n - temp;

			if (p[r-1] > r && p[l] - 1 < l)
				dp[l+1][temp+1] = max(dp[l+1][temp+1], dp[l+1][temp]);
			else
				dp[l+1][temp+1] = max(dp[l+1][temp+1], dp[l+1][temp] + a[r-1]);
		}
	}


	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
