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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w, n;
	cin >> h >> w >> n;
	v2d v(h+2, v1d(w+2, 0));
	rep(i, n)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[a][b]++;
		v[c+1][d+1]++;
		v[a][d+1]--;
		v[c+1][b]--;
	}

	debug(v);
	rep2(i, 1, h+1)
	{
		rep2(j, 1, w+1)
		{
			v[i][j] += v[i][j-1];
		}
	}
	debug(v);
	rep2(i, 1, h+1)
	{
		rep2(j, 1, w+1)
		{
			v[i][j] += v[i-1][j];
		}
	}
	debug(v);
	rep(i, h)
	{
		rep(j, w)
		{
			if (j > 0)
				cout << " ";
			cout << v[i+1][j+1];
		}
		cout << endl;
	}
	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
    // cout << fixed;
    // cout << setprecision(3) << c << endl;
}
