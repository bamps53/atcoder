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
	int n, s;
	cin >> n >> s;
	
	v1d a(n);
	cin_v(a);
	
	v2d dp(n, v1d(s+1));
	dp[0][0] = 1;
	dp[0][a[0]] = 1;
	rep(i, n-1)
	{
		rep(j, s+1)
		{
			if (dp[i][j] == 1)
			{
				dp[i+1][j] = 1;
				if (j+a[i+1] < s+1)
					dp[i+1][j+a[i+1]] = 1;
			}
		}
	}
	debug(dp);
	rep(i, n)
	{
		if (dp[i][s] == 1)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

	




	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
