/*
ID: rkrupes1
TASK: piggyback
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
	ofstream fout ("piggyback.out");
	ifstream fin ("piggyback.in");
	in(b); in(e); in(p); in(n); in(m);
	int distA[n + 1];
	int distB[n + 1];
	int distN[n + 1];
	for (int i = 0; i <= n; i++) {
		distA[i] = inf;
		distB[i] = inf;
		distN[i] = inf;
	}
	vector<int> adjlist[n + 1];
	for (int i = 0; i < m; i++)
	{
		in(a); in(b);
		adjlist[a].pb(b);
		adjlist[b].pb(a);
	}
	distA[1] = 0;
	distB[2] = 0;
	distN[n] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, 1});
	while (!pq.empty())
	{
		pll node = pq.top();
		pq.pop();
		for (auto it : adjlist[node.S])
		{
			if (distA[it] > distA[node.S] + 1)
			{
				distA[it] = distA[node.S] + 1;
				pq.push({distA[it], it});
			}
		}
	}
	pq.push({0, 2});
	while (!pq.empty())
	{
		pll node = pq.top();
		pq.pop();
		for (auto it : adjlist[node.S])
		{
			if (distB[it] > distB[node.S] + 1)
			{
				distB[it] = distB[node.S] + 1;
				pq.push({distB[it], it});
			}
		}
	}
	pq.push({0, n});
	while (!pq.empty())
	{
		pll node = pq.top();
		pq.pop();
		for (auto it : adjlist[node.S])
		{
			if (distN[it] > distN[node.S] + 1) {
				distN[it] = distN[node.S] + 1;
				pq.push({distN[it], it});
			}
		}
	}
	int ans = distA[n] * b + distB[n] * e;
	for (int i = 1; i <= n; i++)
	{
		int pos = distA[i] * b + distB[i] * e + (distN[i]) * p;
		ans = min(ans, pos);
	}
	cout << ans << endl;
	return 0;
}
