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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	double a, b;
	cin >> a >> b;
	double t = pow((a / (2*b)), 2.0/3.0) - 1;
	ll t2 = t;
	ll start = t2 - 10e7;
	start = max(start, 0ll);
	ll end = start + 10e7 * 2;
	double min_t = 10e18;
	debug(start, end);
	while(start != end)
	{
		double this_t = a / sqrt((double)start+1) + b * (double)start;
		if (this_t < min_t)
		{
			min_t = this_t;
		} 
		start++;
	}



	// cout << min_t << '\n';
	printf("%.20lf\n", min_t);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
