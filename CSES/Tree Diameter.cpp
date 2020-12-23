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
bool vis[200005];
int height[200005];
int diameter=0;
void dfs(int src)
{
	vis[src]=true;
	vector<int> childs;
	childs.pb(0);childs.pb(0);
	for(auto it: adjlist[src])
	{
		if(!vis[it])
		{
			dfs(it);
			childs.pb(height[it]);
		}
	}
	sort(childs.begin(),childs.end());
	height[src]=childs[childs.size()-1]+1;
	diameter=max(diameter,childs[childs.size()-1]+childs[childs.size()-2]);
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
	for(int i=1;i<n;i++)
	{
		height[i]=0;
		in(a);in(b);
		adjlist[a].pb(b);
		adjlist[b].pb(a);
	}
	dfs(1);
	cout<<diameter<<endl;
    return 0;
}
