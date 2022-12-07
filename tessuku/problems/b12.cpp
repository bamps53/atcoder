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
	int n;
	cin >> n;

	double l = 0;
	double r = cbrt(n);
	double m = (l+r) / 2;
	while(abs(pow(m, 3)+m-n) > 0.000001)
	{
		if (pow(m, 3)+m-n > 0.000001)
		{
			r = m;
			m = (l+r) / 2;
		}
		else if (pow(m, 3)+m-n < 0.000001)
		{
			l = m;
			m = (l+r) / 2;
		}
		debug(m);
	}

	// cout << ans << '\n';
	printf("%.20lf\n", m);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
