/*
ID: rkrupes1
TASK: dirtraverse
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
set<int> file, folder;
vector<int> adjlist[100005];
int cost[100005];
int dp[100005];
int dp2[100005];
int subtree[100005];


void dfs(int src, int par)
{
	if (file.find(src) != file.end())
	{
		subtree[src] = 1;
		dp[src] = 0;
		return;
	}
	int contri = 0;
	int sub = 0;
	for (auto it : adjlist[src])
	{
		if (it != par)
		{
			dfs(it, src);
			sub += subtree[it];
			if (file.find(it) != file.end())
			{
				contri += cost[it];
			}
			else
			{
				contri += (subtree[it] * (cost[it] + 1) + dp[it]);
			}
		}
	}
	subtree[src] = sub;
	dp[src] = contri;
}

void dfs1(int src, int par)
{

	if (file.find(src) != file.end())
	{
		dp2[src] = inf;
		return;
	}
	int rem = file.size() - subtree[src];

	int currcontri = (subtree[src] * (cost[src] + 1) + dp[src]);
	int parcontri = dp2[par] - currcontri;

	dp2[src] = dp[src] + (rem * 3  + parcontri);
	for (auto it : adjlist[src])
	{
		if (it != par)
			dfs1(it, src);
	}
}
int32_t main()
{
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ofstream fout ("dirtraverse.out");
	ifstream fin ("dirtraverse.in");
	in(n);
	memset(subtree, 0 , sizeof subtree);
	int src;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		if (s == "bessie")
		{
			src = i;
		}
		cost[i] = s.length();
		in(count);
		if (count == 0)
		{
			file.insert(i);
		}
		else
		{
			folder.insert(i);
			for (int j = 0; j < count; j++)
			{
				in(u);
				adjlist[u].pb(i);
				adjlist[i].pb(u);
			}
		}
	}

	dfs(src, -1);


	dp2[src] = dp[src];
	for (auto it : adjlist[src])
		dfs1(it, src);
	int ans = inf;
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, dp2[i]);
	}
	cout << ans << endl;
	return 0;
}
