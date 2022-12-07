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
	v1d v(n);

	int prev;
	cin >> prev;
	int count = 1;
	int status = 0;
	rep(i, n - 1)
	{
		int next;
		cin >> next;
		debug(prev, next, count, status);
		if (status == 0) // new
		{
			if (prev < next)
				status = 1; // up
			else if (prev > next)
				status = 2; // down
		}
		else if (status == 1) // up
		{
			if (prev > next)
			{
				status = 0; // new
				count++;
			}
		}
		else if (status == 2) // down
		{
			if (prev < next)
			{
				status = 0; // new
				count++;
			}
		}
		prev = next;
	}

	// int next = prev;
	// while(next == prev)
	// {
	// 	cin >> next;
	// 	count++;
	// }

	// bool is_up;
	// if (prev < next)
	// 	is_up = true;
	// else
	// 	is_up = false;
	// prev = next;

	// int ans = 1;
	// rep(i, n-count)
	// {
	// 	cin >> next;
	// 	debug(ans, is_up, prev, next);
	// 	if (is_up && prev <= next)
	// 	{
	// 		prev = next;
	// 	}
	// 	else if (is_up && prev > next)
	// 	{
	// 		prev = next;
	// 		is_up = false;
	// 		ans++;
	// 	}
	// 	else if (!is_up && prev >= next)
	// 	{
	// 		prev = next;
	// 	}
	// 	else if (!is_up && prev < next)
	// 	{
	// 		prev = next;
	// 		is_up = true;
	// 		ans++;
	// 	}
	// }
	cout << count << endl;
	// printf("%.20lf\n", ans);
}
