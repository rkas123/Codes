/*
ID: rkrupes1
TASK: lasers
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
	ofstream fout ("lasers.out");
	ifstream fin ("lasers.in");

	in(n); in(xl); in(yl); in(xb); in(yb);
	map<int, vector<int>> X;
	map<int, vector<int>> Y;
	map<int, int> distX;
	map<int, int> distY;
	for (int i = 0; i < n; i++)
	{
		in(x); in(y);
		X[x].pb(y);
		Y[y].pb(x);
		distY[y] = inf;
		distX[x] = inf;
	}

	queue<pair<char, int>> q;
	distX[xb] = inf;
	distY[yb] = inf;
	distX[xl] = 0;
	distY[yl] = 0;

	q.push({'x', xl});
	q.push({'y', yl});
	while (!q.empty())
	{
		pair<char, int> node = q.front();
		// cout << node.F << " " << node.S << endl;
		q.pop();
		if (node.F == 'x')
		{
			for (auto it : X[node.S])
			{
				if (distY[it] > distX[node.S] + 1)
				{
					distY[it] = distX[node.S] + 1;
					q.push({'y', it});
				}
			}
		}
		else
		{
			for (auto it : Y[node.S])
			{
				if (distX[it] > distY[node.S] + 1)
				{
					distX[it] = distY[node.S] + 1;
					q.push({'x', it});
				}
			}
		}
	}
	int ans = min(distX[xb], distY[yb]);
	if (ans == inf)
		cout << "-1" << endl;
	else
		cout << ans << endl;
	return 0;
}
