#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
	int n;
	cin >> n;
	v1d ts(n+1);
	v1d xs(n+1);
	v1d ys(n+1);
	ts[0] = 0;
	xs[0] = 0;
	ys[0] = 0;

	rep2(i, 1, n+1)
	{
		cin >> ts[i] >> xs[i] >> ys[i];
	}
	rep(i, n)
	{
		int dt = ts[i+1] - ts[i];
		int dx = abs(xs[i+1] - xs[i]);
		int dy = abs(ys[i+1] - ys[i]);
		if ((dt < dx + dy) | (dt%2 != (dx + dy)%2))
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;

	// cout << ans << endl;
	// printf("%.20lf\n", ans);
}
