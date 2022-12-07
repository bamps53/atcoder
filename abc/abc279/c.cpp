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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	// map<string, int> s;
	// map<string, int> t;
	v2d s(w, v1d(h));
	v2d t(w, v1d(h));

	rep(i, h)
	{
		rep(j, w)
		{
			char x;
			cin >> x;
			if (x == '.')
			{
				s[j][i] = 1;
			}
			else
			{
				s[j][i] = 0;
			}
		}
	}

	rep(i, h)
	{
		rep(j, w)
		{
			char x;
			cin >> x;
			if (x == '.')
			{
				t[j][i] = 1;
			}
			else
			{
				t[j][i] = 0;
			}
		}
	}


	sort_all(s);
	sort_all(t);
	// debug(s);
	// debug(t);

	rep(i, h)
	{
		rep(j, w)
		{
			if (s[j][i] != t[j][i])
			{
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
