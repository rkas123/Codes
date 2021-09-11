/*
ID: rkrupes1
TASK: barnpainting
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

vector<int> adjlist[100005];
int dp[100005][3];
int color[100005];

void dfs(int src, int par)
{
	vector<int> ways(3, 1);
	for (auto it : adjlist[src])
	{
		if (it != par)
		{
			dfs(it, src);
			for (int i = 0; i < 3; i++)
			{
				ways[i] *= (dp[it][(i + 1) % 3] + dp[it][(i + 2) % 3]) % mod;
				ways[i] %= mod;
			}
		}
	}
	if (color[src] != -1)
	{
		dp[src][color[src]] = ways[color[src]];
	}
	else
	{
		for (int i = 0; i < 3; i++)
			dp[src][i] = ways[i];
	}
}
int32_t main()
{
	ofstream fout ("barnpainting.out");
	ifstream fin ("barnpainting.in");
	in(n); in(k);
	for (int i = 1; i < n; i++)
	{
		in(u); in(v);
		adjlist[u].pb(v);
		adjlist[v].pb(u);
	}
	memset(color, -1, sizeof(color));
	for (int i = 0; i < k; i++)
	{
		in(a); in(b);
		b--;
		color[a] = b;
	}
	memset(dp, 0, sizeof(dp));
	dfs(1, -1);

	cout << (dp[1][0] + dp[1][1] + dp[1][2]) % mod << endl;


	return 0;
}
