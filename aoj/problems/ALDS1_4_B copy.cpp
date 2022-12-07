#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)

void print_vec(vector<int> v)
{
    rep(i, v.size())
    {
        if (i > 0)
        {cout << " ";}
        cout << v[i];
    }
    cout << endl;
}

bool binary_search(vector<int>& v, int& key)
{
    int left = -1;
    int right = v.size() + 1;
    while (right - left > 1)
    {
        int mid = left + (right - left) / 2;
        if (key == v[mid])
        {
            return true;
        }
        else if (key < v[mid])
        {
            right = mid;
        }
        else if (key > v[mid])
        {
            left = mid;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> S(n);
    rep(i, n)
    {
        cin >> S[i];
    }
    int q;
    cin >> q;
    vector<int> T(q);
    rep(i, q)
    {
        cin >> T[i];
    }
    int ans = 0;
    for (auto x: T)
    {
        
        if (binary_search(S, x))
        {
            ans++;
        }
    }
    cout << ans << endl;
}

