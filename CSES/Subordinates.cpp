#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

#define inl(x) long long x;cin>>x
#define in(x) int x;cin>>x
#define pb push_back
#define F first
#define S second
#define endl "\n"

#define test() int t;cin>>t;while(t--)
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const long long mod = 1e9+7;
const int MAX = INT_MAX;
const long long inf = 1e18 + 5;
const double pi = 3.14159265358979323846; 

int dirX[]={1,-1,0,0};
int dirY[]={0,0,1,-1};

using namespace std;
int n;
vector<int> adjlist[200005];
int answer[200005];
int func(int src)
{
	int count=0;
	for(int i=0;i<adjlist[src].size();i++)
	{
		count+=func(adjlist[src][i]);
	}
	answer[src]=count;
	return count+1;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		in(t);
		adjlist[t].pb(i);
	}
	func(1);
	for(int i=1;i<=n;i++)
		cout<<answer[i]<<" ";
	cout<<endl;
    return 0;
}
