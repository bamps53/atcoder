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

void insert_sort(vector<int>& v, int g, int& count)
{
    rep2(i, g, v.size())
    {
        int j = i - g;
        while (j >= 0 )
        {
            if (v[j] > v[j+g])
            {
                swap(v[j], v[j+g]);
                count++;
            }
            j-=g;
        }
    }
}

void shell_sort(vector<int> v, vector<int> vec_g)
{
    int count = 0;
    for(const auto& g: vec_g)
    {
        insert_sort(v, g, count);
    }
    cout << count << endl;
    for (const auto& x: v)
    {
        cout << x << endl;
    }


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

    vector<int> vec_g = {1};
    cout << vec_g.size() << endl;
    print_vec(vec_g);
    shell_sort(v, vec_g);
}

