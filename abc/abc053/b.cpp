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

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int start = 0;
    int end = n;

    rep(i, n)
    {
        if (s[i] == 'A')
        {
            start = i;
            break;
        }
    }
    rep(i, n)
    {

        if (s[n-i-1] == 'Z')
        {
            end = n-i;
            break;
        }
    }
    cout << end - start << endl;
}

