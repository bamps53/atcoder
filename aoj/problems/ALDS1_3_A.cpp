#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)

int main()
{
    stack<int> st;
    char s[100];
    while (scanf("%s", s) != EOF)
    {
        if (s[0] == '+')
        {
            int y = st.top(); st.pop();
            int x = st.top(); st.pop();
            st.push(x + y);
        }
        else if (s[0] == '-')
        {
            int y = st.top(); st.pop();
            int x = st.top(); st.pop();
            st.push(x - y);
        }
        else if (s[0] == '*')
        {
            int y = st.top(); st.pop();
            int x = st.top(); st.pop();
            st.push(x * y);
        }
        else
        {
            st.push(atoi(s));
        }
    }
    cout << st.top() << endl;
}
