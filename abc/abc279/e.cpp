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
	int n, m;
	cin >> n >> m;
	v1d a(m);
	cin_v(a);

	v1d b(n+1);
	iota(b.begin(), b.end(), 0);
	debug(b);
	for(auto i: a)
	{
		swap(b[i], b[i+1]);
	}
	debug(b);

	v1d pos(n+1);
	rep(i, n+1)
	{
		pos[b[i]] = i;
	}
	debug(pos);

	iota(b.begin(), b.end(), 0);
	for(auto i: a)
	{
		if (b[i]==1)
		{
			cout << pos[b[i+1]] << endl;
		}
		else if (b[i+1] == 1)
		{
			cout << pos[b[i]] << endl;
		}
		else
		{
			cout << pos[1] << endl;
		}
		swap(b[i], b[i+1]);
	}
}
