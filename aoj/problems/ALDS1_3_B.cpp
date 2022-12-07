#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
constexpr int n = 1000;

int main()
{
    int n, unit;
    cin >> n >> unit;
    queue<pair<string, int>> q;
    rep(i, n)
    {
        string s;
        int t;
        cin >> s >> t;
        q.push(make_pair(s, t));
    }

    int total = 0;
    while (q.size() > 0)
    {
        auto task = q.front(); q.pop();
        if (task.second > unit)
        {
            task.second -= unit;
            total += unit;
            q.push(task);
        }
        else
        {
            total += task.second;
            cout << task.first << " " << total << endl;
        }
    }
}
