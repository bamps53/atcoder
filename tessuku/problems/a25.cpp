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
	 * 
	 * 
	 */
	ll h, w;
	cin >> h >> w;

	vector<vector<int>> mp(h, vector<int>(w, 0));
	rep(i, h){
		rep(j, w){
			char c;
			cin >> c;
			if (c == '.'){
				mp[i][j] = 1;
			}
		}
	}
	debug(mp);

	vector<vector<ll>> dp(h, vector<ll>(w, 0));
	dp[0][0] = 1;
	rep2(i, 1, h){
		if (mp[i][0] == 1){
			dp[i][0] = dp[i-1][0];
		}
	}
	rep2(i, 1, w){
		if (mp[0][i] == 1){
			dp[0][i] = dp[0][i-1];
		}
	}	

	rep2(i, 1, h){
		rep2(j, 1, w){
			if (mp[i-1][j] == 1){
				dp[i][j] += dp[i-1][j];
			}
			if (mp[i][j-1] == 1){
				dp[i][j] += dp[i][j-1];
			}
		}
	}
	debug(dp);



	cout << dp[h-1][w-1] << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
