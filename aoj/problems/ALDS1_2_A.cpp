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

    bool flag = true;
    while (flag)
    {
        flag = false;
        rep(i, n-1)
        {
            if (v[i] > v[i+1])
            {
                swap(v[i], v[i+1]);
                count++;
                flag = true;
            }
        }
    }
    print_vec(v);
    cout << count << endl;

}

