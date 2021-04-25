/*
ID: rkrupes1
TASK: moocast
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
int parent[1001];
int Rank[1001];
int Dist(pll a, pll b)
{
	return (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);
}
int getParent(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = getParent(parent[x]);
}
void join(int a, int b)
{
	int para = getParent(a);
	int parb = getParent(b);
	if (Rank[para] == Rank[parb])
	{
		parent[parb] = para;
		Rank[para]++;
		return;
	}
	if (Rank[para] > Rank[parb])
	{
		parent[parb] = para;
		return;
	}
	parent[para] = parb;
}
int32_t main()
{
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ofstream fout ("moocast.out");
	ifstream fin ("moocast.in");
	in(n);
	pll indexes[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> indexes[i].F;
		cin >> indexes[i].S;
		parent[i] = i;
		Rank[i] = 0;
	}
	vector<pll> edges;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (i == j)
				continue;
			edges.pb({i, j});
		}
	}
	vector<pll> edgeweights;
	for (int i = 0; i < edges.size(); i++)
	{
		edgeweights.pb({Dist(indexes[edges[i].F], indexes[edges[i].S]), i});
	}
	sort(edgeweights.begin(), edgeweights.end());
	int ans = 0;
	int count = 0;
	for (auto it : edgeweights)
	{
		pll node = edges[it.S];
		int para = getParent(node.F);
		int parb = getParent(node.S);
		if (para == parb)
			continue;
		ans = it.F;
		join(node.F, node.S);
	}
	cout << ans << endl;
	return 0;
}
