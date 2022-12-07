#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)


int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n)
    {
        cin >> v[i];
    }

    // 後ろから見て行って単調減少ではなくなる箇所
    int i = n - 2;
    while (v[i] < v[i+1])
    {
        i--;
    }

    // 後ろから見て行って、最初にv[i]より大きくなる箇所
    int j = n - 1;
    while (v[i] < v[j])
    {
        j--;
    }
    // i番目とi番目以降で次に大きいものを入れ替える
    swap(v[i], v[j]);

    reverse(begin(v)+i+1, v.end());

    rep(i, v.size()-1)
    {
        cout << v[i] << " ";

    }
    cout << v[v.size()-1] << endl;
}

