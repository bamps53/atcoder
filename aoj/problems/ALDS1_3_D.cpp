#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
constexpr int n = 1000;

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
    stack<int> st_pos;
    stack<pair<int, int>> st_ans;
    int right = 0;
    int ans = 0;
    int recorded = 0;
    char x;
    for (int i=0; cin >> x; i++)
    {
        if (x == '/')
        {
            if (st_pos.size() > 0)
            {
                int left = st_pos.top();
                st_pos.pop();
                int new_area = right - left;
                ans += new_area;

                
                while(st_ans.size()>0 && st_ans.top().first > left)
                {
                    new_area += st_ans.top().second;
                    st_ans.pop();
                }
                st_ans.push(make_pair(left, new_area));
            }
        }
        else if (x == '\\')
        {
            st_pos.push(right);
        }
        right++;
    }
    cout << ans << endl;

    vector<int> ans_vec;
    
    cout << st_ans.size() << " ";
    
    while(st_ans.size() > 0)
    {
        ans_vec.push_back(st_ans.top().second);
        st_ans.pop();
    }
    reverse(ans_vec.begin(), ans_vec.end());
    print_vec(ans_vec);
}
