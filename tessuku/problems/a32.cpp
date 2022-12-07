#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool dp[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	/**
	 * 
	 * 
	 */
	int n, a, b;
	cin >> n >> a >> b;
	rep(i, n+1){
		if (i < a){
			dp[i] = 0;
		}
		else if (i < b){
			dp[i] = 1;
		}
		else{
			dp[i] = dp[i-a] == 0 || dp[i-b] == 0;
		}
	}
	if (dp[n]){
		cout << "First" << endl;
	}
	else{
		cout << "Second" << endl;
	}
}
