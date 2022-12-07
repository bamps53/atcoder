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
	 * 
	 * 
	 */
	string s, t;
	cin >> s >> t;

	auto t_size = t.size();
	auto s_size = s.size();
	v1d forward(t_size, 0);
	// v1d backward(t_size, 0);

	rep(i, s_size)
	{
		//　前から
		if (s[i] != t[i])
		{
			forward[i] = 1;
		}
		else{
			forward[i] = 0;
		}

		// //　後ろから
		// if (s[s_size-1-i] != t[t_size-1-i])
		// {
		// 	backward[t_size-1-i] = 1;
		// }
		// else{
		// 	backward[t_size-1-i] = 0;
		// }
	}
	debug(forward);
	rep(i, t_size)
	{
		// if (forward[i] == 1 && backward[i] == 1)
		if (forward[i] == 1)
		{
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << t_size << endl;
	return 0;

	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
