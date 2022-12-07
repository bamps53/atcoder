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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), b(n), c(n), d(n);
	cin_v(a);
	cin_v(b);
	cin_v(c);
	cin_v(d);

	vector<ll> ab;
	vector<ll> cd;
	rep(i, n)
	{
		rep(j, n)
		{
			ab.emplace_back(a[i]+b[j]);
		}
	}
	rep(i, n)
	{
		rep(j, n)
		{
			cd.emplace_back(c[i]+d[j]);
		}
	}
	sort_all(cd);

	// debug(a);
	// debug(b);
	// debug(c);
	// debug(d);
	// debug(ab);
	debug(cd);
	debug(ab.size());
	debug(cd.size());

	rep(i, ab.size())
	{
		if (k-ab[i] > 0 && binary_search(cd.begin(), cd.end(), k-ab[i]))
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	// for(auto& x: ab)
	// {
	// 	if (k-x > 0)
	// 		debug(k-x);
	// 	if (k-x > 0 && binary_search(cd.begin(), cd.end(), k-x))
	// 	{
	// 		cout << "Yes" << endl;
	// 		return 0;
	// 	}
	// }
	cout << "No" << endl;


	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
