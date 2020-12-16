//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

using namespace std;
int n;
vector<int> adjlist[100001];
vector<int> revadjlist[100001];
bool vis[100001];
stack<int> s;
void dfs(int src)
{
    vis[src]=true;
    for(auto it: adjlist[src])
    {
        if(!vis[it])
        {
            dfs(it);
        }
    }
    s.push(src);
}
void dfs2(int src)
{
    vis[src]=true;
    for(auto it: revadjlist[src])
    {
        if(!vis[it])
        {
            dfs2(it);
        }
    }
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
    cin>>n;in(m);
    
    for(int i=0;i<m;i++)
    {
        in(a);in(b);
        adjlist[a].pb(b);
        revadjlist[b].pb(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++)
        vis[i]=false;
    vector<int> ssc;
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        if(!vis[node])
        {
            ssc.pb(node);
            dfs2(node);
        }
    }
    if(ssc.size()==1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
        cout<<ssc[1]<<" "<<ssc[0]<<endl;
    }

    return 0;
}
