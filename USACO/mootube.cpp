//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
ll n,q;
vector<pll> adjlist[5001];
vector<ll> dist;
vector<bool> vis;
void setdist()
{
    for(int i=0;i<=n;i++){
        dist[i]=inf;
        vis[i]=false;
    }
}
void dfs(ll src)
{
    vis[src]=true;
    for(auto it: adjlist[src])
    {
        if(!vis[it.F])
        {
            dist[it.F]=min(dist[src],it.S);
            dfs(it.F);
        }
    }
}
int main()
{
    ofstream fout ("mootube.out");
    ifstream fin ("mootube.in");
    cin>>n>>q;
    for(int i=0;i<=n;i++)
    {
        dist.pb(inf);
        vis.pb(false);
    }
    for(int i=1;i<n;i++)
    {
        inl(a);inl(b);inl(c);
        adjlist[a].pb({b,c});
        adjlist[b].pb({a,c});
        
    }
    while(q--)
    {
        inl(cost);inl(src);
        setdist();
        dfs(src);
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]!=inf && dist[i] >= cost)
                count++;
        }
        cout<<count<<endl;
    }

    return 0;
}
