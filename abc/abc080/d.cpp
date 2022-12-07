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

constexpr int t_max = 1e5;
int imos[t_max][30];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	/**
	 * [s-1, t)の半開区間で時間は考える
	 * 
	 */
	int n, n_c;
	cin >> n >> n_c;
	
	// v2d imos = make_v2d(t_max+1, n_c, 0);
 
	rep(i, n)
	{
		int s, t, c;
		cin >> s >> t >> c;
		c--;
		s--;
		imos[s][c]++;
		imos[t][c]--;
	}
	rep(j, n_c)
	{
		rep(i, t_max)
		{
			imos[i+1][j] += imos[i][j];
		}
	}
	rep(j, n_c){
		rep(i, t_max+1){
			if (imos[i][j] > 1){
				imos[i][j] = 1;
			}
		}
	}
	int ans = 0;
	rep(i, t_max)
	{
		int temp = 0;
		rep(j, n_c)
		{
			temp+=imos[i][j];
		}
		chmax(ans, temp);
	}
	cout << ans << endl;
 
 
 
	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}