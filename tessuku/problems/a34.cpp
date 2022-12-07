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
void sort_all(T &v) { sort(v.begin(), v.end()); }

template <typename T>
void reverse_all(T &v) { reverse(v.begin(), v.end()); }

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
	int n, x, y;
	cin >> n >> x >> y;

	int num = 1e5 + 9;
	v1d g(num+1);
	rep(i, num+1)
	{
		if (i < x)
		{
			g[i] = 0;
		}
		else if (i < y)
		{
			if (g[i - x] == 0)
			{
				g[i] = 1;
			}
		}
		else
		{
			g[i] = 0;
			while ((g[i] == g[i - x]) || (g[i] == g[i - y]))
			{
				g[i]++;
			}
		}
	}
	debug(g);

	v1d a(n);
	cin_v(a);

	int ans;
	rep(i, n){
		if (i == 0){
			ans = g[a[i]];
		}
		else{
			ans = ans ^ g[a[i]];
		}
		debug(ans);
	}
	if (ans == 0){
		cout << "Second" << endl;
	}
	else{
		cout << "First" << endl;
	}




	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
