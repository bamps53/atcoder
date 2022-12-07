#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)

struct Card
{
    char suit;
    int value;
};

void print_vec(vector<Card> v)
{
    rep(i, v.size())
    {
        cout << v[i].suit << v[i].value;
        if (i != v.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

void bubble_sort(vector<Card>& v)
{
    size_t n = v.size();
    bool flag = true;
    while (flag)
    {
        flag = false;
        rep(i, n-1)
        {
            if (v[i].value > v[i+1].value)
            {
                swap(v[i], v[i+1]);
                flag = true;
            }
        }
    }
}

void selection_sort(vector<Card>& v)
{
    size_t n = v.size();
    rep(i, n)
    {
        int min_idx = i;
        int min_value = v[i].value;
        rep2(j, i, n)
        {
            if( v[j].value < min_value)
            {
                min_idx = j;
                min_value = v[j].value;
            }
        }
        if (i != min_idx)
        {
            swap(v[i], v[min_idx]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Card> v(n);
    rep(i, n)
    {
        string s;
        cin >> s;
        v[i].suit = s[0];
        v[i].value = s[1] - '0';
    }

    vector<Card> temp = v;
    selection_sort(temp);
    vector<Card> after_selection = temp;

    temp = v;
    bubble_sort(temp);
    vector<Card> after_bubble = temp;

    bool same = true;
    rep(i, n)
    {
        if (after_selection[i].suit != after_bubble[i].suit | after_selection[i].value != after_bubble[i].value)
        {
            same = false;
            break;
        }
    }

    print_vec(after_bubble);
    cout << "Stable" << endl;

    print_vec(after_selection);
    if (same)
    {
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }
}

