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

bool isOK(vector<int>& v, int& index, int& key)
{
    if (v[index] >= key)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int binary_search(vector<int>& v, int& key)
{
    int ng = -1;
    int ok = v.size();

    while (abs(ng - ok) > 1)
    {
        int mid = (ng + ok) / 2;
        if (isOK(v, mid, key))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    return ok;
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
        
        int index = binary_search(S, x);
        if (S[index] == x)
        {
            ans++;
        }
    }
    cout << ans << endl;
}

