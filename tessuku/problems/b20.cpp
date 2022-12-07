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
	string s, t;
	cin >> s >> t;

	auto s_size = s.size();
	auto t_size = t.size();
	v2d dp(s_size+1, v1d(t_size+1, 10e8));
	rep(i, s_size+1)
	{
		dp[i][0] = i;
	}
	rep(j, t_size+1)
	{
		dp[0][j] = j;
	}
	rep(i, s_size)
	{
		rep(j, t_size)
		{
			if (s[i] == t[j])
			{
				dp[i+1][j+1] = min(min(dp[i][j], dp[i+1][j]+1), dp[i][j+1]+1);
			}
			else
			{
				dp[i+1][j+1] = min(min(dp[i][j]+1, dp[i+1][j]+1), dp[i][j+1]+1);
			}
		}
	}
	debug(dp);
	cout << dp[s_size][t_size] << endl;
	

	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
