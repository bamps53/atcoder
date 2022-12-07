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

template <typename T>
void reverse_all(T& v) { reverse(v.begin(), v.end()); }


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	v1d h(n);
	cin_v(h);

	v1d dp(n);
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);
	rep(i, n-2)
	{
		dp[i+2] = min(dp[i]+abs(h[i+2]-h[i]), dp[i+1]+abs(h[i+2]-h[i+1]));
	}
	debug(dp);
	// cout << dp[n-1] << endl;

	v1d ans;
	int pos = n-1;
	while(pos > 0)
	{
		ans.push_back(pos+1);
		if (dp[pos]-dp[pos-1] == abs(h[pos]-h[pos-1]))
		{
			pos--;
		}
		else if (dp[pos]-dp[pos-2] == abs(h[pos]-h[pos-2]))
		{
			pos-=2;
		}
		else
		{
			debug(pos);
			assert(false);
		}
	}
	ans.push_back(1);
	reverse_all(ans);

	cout << ans.size() << endl;
	cout_v(ans);


	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
