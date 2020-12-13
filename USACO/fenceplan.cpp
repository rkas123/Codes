//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int n,m;
pair<ll,ll> A[100005];
bool visited[100005];
vector<ll> adjlist[100005];
ll xmin=inf;
ll xmax=0;
ll ymin=inf;
ll ymax=0;
void dfs(int i)
{
    visited[i]=true;
    xmin=min(xmin,A[i].F);
    xmax=max(xmax,A[i].F);
    ymin=min(ymin,A[i].S);
    ymax=max(ymax,A[i].S);
    for(auto it: adjlist[i])
    {
        if(!visited[it])
        {
            dfs(it);
        }
    }
}
int main()
{
    ofstream fout ("fenceplan.out");
    ifstream fin ("fenceplan.in");
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i].F>>A[i].S;
        visited[i]=false;
    }
    for(int i=0;i<m;i++)
    {
        in(a);in(b);
        adjlist[a].pb(b);
        adjlist[b].pb(a);
    }
    ll answer=inf;
    
    for(int i=1;i<=n;i++)
    {
        xmin=inf;
        xmax=0;
        ymin=inf;
        ymax=0;
        if(!visited[i])
        {
            dfs(i);
            answer=min(answer,2*((xmax-xmin)+(ymax-ymin)));
        }
        
    }
    cout<<answer<<endl;
    return 0;
}
