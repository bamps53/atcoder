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
    int count = 0;
    rep(i, n)
    {
        cin >> v[i];
    }

    rep(i, n)
    {
        int min_idx = i;
        int min_value = v[i];
        rep2(j, i, n)
        {
            if( v[j] < min_value)
            {
                min_idx = j;
                min_value = v[j];
            }
        }
        if (i != min_idx)
        {
            swap(v[i], v[min_idx]);
            count++;
        }
    }
    print_vec(v);
    cout << count << endl;
}

