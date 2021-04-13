/*
ID: rkrupes1
TASK:guard
LANG: C++
*/
#include<bits/stdc++.h>

#define int long long
#define pll pair<long long,long long>

#define in(x) long long x;cin>>x
#define pb push_back
#define F first
#define S second
#define endl "\n"

#define test() int t;cin>>t;while(t--)
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
#define deb(x) cout<<#x<<" "<<x<<endl;

const long long mod = 1e9 + 7;
const int MAX = INT_MAX;
const long long inf = 1e18 + 5;
const double pi = 3.14159265358979323846;

int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};

#define cin fin
#define cout fout

using namespace std;
int32_t main()
{
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ofstream fout ("guard.out");
	ifstream fin ("guard.in");
	in(n); in(h);
	vector<int> dp((1 << n), -1);
	dp[0] = inf;
	int height[n], weight[n], strength[n];
	for (int i = 0; i < n; i++)
		cin >> height[i] >> weight[i] >> strength[i];
	int res = -1;
	for (int i = 0; i < (1 << n); i++)
	{
		if (dp[i] == -1)
			continue;
		int hs = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
				hs += height[j];
		}
		if (hs >= h)
			res = max(res, dp[i]);
		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)) == 0)
			{
				dp[i | (1 << j)] = max(dp[i | (1 << j)], min(strength[j], dp[i] - weight[j]));
			}
		}
	}
	if (res == -1)
	{
		cout << "Mark is too tall" << endl;
	}
	else
		cout << res << endl;
	return 0;
}
