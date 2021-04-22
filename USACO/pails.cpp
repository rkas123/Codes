/*
ID: rkrupes1
TASK: pails
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
	ofstream fout ("pails.out");
	ifstream fin ("pails.in");
	in(x); in(y); in(k); in(m);
	set<pll> curr;
	set<pll> next;
	curr.insert({0, 0});
	int count = 0;
	while (count < k)
	{
		// cout << count << endl;
		for (auto it : curr)
		{
			pll node = it;
			// cout << node.F << " " << node.S << endl;
			next.insert({0, node.S});
			next.insert({node.F, 0});
			next.insert({x, node.S});
			next.insert({node.F, y});
			int rem = y - node.S;
			rem = min(rem, node.F);
			next.insert({node.F - rem, node.S + rem});
			rem = x - node.F;
			rem = min(rem, node.S);
			next.insert({node.F + rem, node.S - rem});
		}
		count++;
		curr = next;
		next.clear();
	}
	int ans = inf;
	for (auto it : curr)
	{
		ans = min(ans, abs(it.F + it.S - m));
	}
	cout << ans << endl;
	return 0;
}
