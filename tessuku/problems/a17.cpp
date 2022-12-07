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
void sort_all(T &v) { sort(v.begin(), v.end()); }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	v1d a(n, 0);
	rep2(i, 1, n)
	{
		cin >> a[i];
	}
	v1d b(n, 0);
	rep2(i, 2, n)
	{
		cin >> b[i];
	}

	debug(a);
	debug(b);

	v1d dp(n);
	dp[0] = 0;
	dp[1] = dp[0] + a[1];

	
	rep(i, n - 2)
	{
		dp[i + 2] = min(dp[i + 1] + a[i + 2], dp[i] + b[i + 2]);
	}

	debug(dp);

	v1d ans;
	int pos = n - 1;
	while(pos >= 1)
	{
		ans.push_back(pos+1);
		debug(dp[pos], a[pos], pos);
		if (dp[pos] - dp[pos-1] == a[pos])
		{
			pos--;
		}
		else
		{
			pos-= 2;
		}
	}
	ans.push_back(1);

	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	cout_v(ans);

	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
