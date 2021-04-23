/*
ID: rkrupes1
TASK: closing
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
int parent[200001];
int comps = 0;
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
	if (para == parb)
		return;
	comps--;
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
	ofstream fout ("closing.out");
	ifstream fin ("closing.in");
	in(n);
	in(m);
	vector<int> adjlist[n + 1];
	bool pres[n + 1];
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		pres[i] = false;
	}
	for (int i = 0; i < m; i++)
	{
		in(a); in(b);
		adjlist[a].pb(b);
		adjlist[b].pb(a);
	}
	vector<int> order(n);
	for (int i = 0; i < n; i++)
		cin >> order[i];
	reverse(order.begin(), order.end());
	comps = 0;
	vector<int> ans;
	for (auto it : order)
	{
		comps++;
		pres[it] = true;
		for (auto i : adjlist[it])
		{
			if (pres[i])
			{
				join(it, i);
			}
		}
		ans.pb(comps);
	}
	reverse(ans.begin(), ans.end());
	for (auto it : ans)
	{
		if (it == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
