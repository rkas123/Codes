/*
ID: rkrupes1
TASK: maxflow
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

int ans;
int walk(int src, int k, vector<vector<int>>&up)
{
	int curr = src;
	int i = 0;
	while (k > 0)
	{
		if (k & 1)
			curr = up[curr][i];
		k >>= 1;
		i++;
		if (curr == -1)
			break;
	}
	return curr;
}

void dfs(int src, int Par, vector<vector<int>>&adjlist, vector<int>&par, vector<int>&height)
{
	if (src == 1)
		height[src] = 0;
	else
		height[src] = height[Par] + 1;

	par[src] = Par;
	for (auto it : adjlist[src])
	{
		if (it == Par)
			continue;

		dfs(it, src, adjlist, par, height);
	}
}

int lca(int a, int b, vector<int>&height, vector<vector<int>>&up) {
	int ha = height[a];
	int hb = height[b];
	int diff = abs(ha - hb);

	if (ha > hb)
		a = walk(a, diff, up);
	else
		b = walk(b, diff, up);

	if (a == b)
		return a;

	for (int i = 20; i >= 0; i--)
	{
		int pa = walk(a, (1 << i), up);
		int pb = walk(b, (1 << i), up);

		if (pa != pb)
		{
			a = pa;
			b = pb;
		}
	}
	return up[a][0];
}

int dfs1(int src, int par, vector<vector<int>>&adjlist, vector<int>&val)
{
	int curr = val[src];

	for (auto it : adjlist[src])
	{
		if (it != par)
			curr += dfs1(it, src, adjlist, val);
	}
	ans = max(ans, curr);
	return curr;
}
int32_t main()
{
	ofstream fout ("maxflow.out");
	ifstream fin ("maxflow.in");

	in(n); in(k);
	vector<vector<int>> adjlist(n + 1);
	vector<vector<int>> up(n + 1, vector<int>(21, -1));
	for (int i = 1; i < n; i++)
	{
		in(a); in(b);
		adjlist[a].pb(b);
		adjlist[b].pb(a);
	}

	vector<int> par(n + 1, -1), height(n + 1);

	dfs(1, -1, adjlist, par, height);

	for (int i = 1; i <= n; i++)
	{
		up[i][0] = par[i];
	}

	for (int l = 1; l < 21; l++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (up[i][l - 1] != -1)
				up[i][l] = up[up[i][l - 1]][l - 1];
		}
	}

	vector<int> val(n + 1, 0);

	while (k--)
	{
		in(a); in(b);
		int LCA = lca(a, b, height, up);
		val[a]++;
		val[b]++;
		if (LCA != 1)
		{
			val[par[LCA]] --;
		}
		val[LCA]--;
	}

	ans = 0;
	dfs1(1, -1, adjlist, val);
	cout << ans << endl;

	return 0;
}
