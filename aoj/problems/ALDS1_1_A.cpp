#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)

void print_vec(vector<int> v)
{
    rep(i, v.size())
    {
        cout << v[i];
        if (i != v.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n)
    {
        cin >> v[i];
    }

    rep(i, n)
    {
        int j = i - 1;
        while (j >= 0 )
        {
            if (v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
            }
            j--;
        }
        print_vec(v);
    }
}

