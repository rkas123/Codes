//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
ll n,m;
int Count;
vector<pair<pll,ll>> v;
int parent[100001];
bool vis[100001];
int A[100001];
void dfs(int src,vector<ll> adjlist[])
{
    vis[src]=true;
    for(auto it: adjlist[src])
    {
        if(!vis[it])
        {
            dfs(it,adjlist);
            parent[it]=Count;
        }
    }
}
bool pos(ll x)
{
    vector<ll> adjlist[n+1];
    
    for(int i=1;i<=n;i++){
        vis[i]=false;
        parent[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        if(v[i].S >= x)
        {
            adjlist[v[i].F.S].pb(v[i].F.F);
            adjlist[v[i].F.F].pb(v[i].F.S);
        }
    }
    Count=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            parent[i]=Count;
            dfs(i,adjlist);
        }
        Count++;
    }
    // for(int i=0;i<n;i++)
    //     cout<<parent[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(parent[i] != parent[A[i]])
            return false;
    }
    return true;
}
int main()
{
    ofstream fout ("wormsort.out");
    ifstream fin ("wormsort.in");
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<m;i++)
    {
        inl(a);inl(b);inl(c);
        v.pb({{a,b},c});
    }
    ll s=0;
    ll e=1e9 + 1;
    ll answer=-1;
    while(s<=e)
    {
        ll mid=(s+e)/2;
       // cout<<mid<<endl;
        if(pos(mid))
        {
            //cout<<mid<<endl;
            answer=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    if(answer == 1e9+1)
        cout<<"-1"<<endl;
    else
        cout<<answer<<endl;
    return 0;
}
