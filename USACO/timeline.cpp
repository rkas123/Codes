/*
ID: rkrupes1
TASK: timeline
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
	ofstream fout ("timeline.out");
	ifstream fin ("timeline.in");

	in(n); in(m); in(c);
	vector<pll> adjlist[n];
	vector<pll> reverse[n];
	int S[n];
	int indegree[n];
	int ans[n];
	for (int i = 0; i < n; i++) {
		cin >> S[i];
		indegree[i] = 0;
	}
	for (int i = 0; i < c; i++)
	{
		in(a); in(b); in(x);
		a--;
		b--;
		adjlist[a].pb({b, x});
		reverse[b].pb({a, x});
		indegree[b]++;
	}
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		int time = S[node];
		for (auto it : reverse[node])
		{
			time = max(time, ans[it.F] + it.S);
		}
		ans[node] = time;
		for (auto it : adjlist[node])
		{
			indegree[it.F] --;
			if (indegree[it.F] == 0)
				q.push(it.F);
		}
	}


	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;

	return 0;
}
