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
	int n, k;
	cin >> n >> k;
	v1d a(n);
	cin_v(a);

	auto count = [&](ll mid)
	{
		ll num = 0;
		rep(i, n)
		{
			num += mid / a[i];
		}
		return num;
	};

	ll left = 0;
	ll right = 10e9;
	ll mid;
	while(abs(right - left) > 1)
	{
		ll mid = (right + left) / 2;
		ll num = count(mid);
		// debug(left, right, mid, num);

		if (num == k)
		{
			while(count(mid-1)==k)
			{
				mid--;
			}
			cout << mid << endl; 
			return 0;
		}
		else if (num > k)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	cout << right << endl; 
	// debug("end");

	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
    // cout << fixed;
    // cout << setprecision(3) << c << endl;
}
