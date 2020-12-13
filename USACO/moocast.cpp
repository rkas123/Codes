//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int n;
vector<pair<int,int>> v;
vector<int> radius;
vector<bool> visited;
vector<int> adjlist[205];
int dfs(int i)
{
    visited[i]=true;
    int count=1;
    for(auto it: adjlist[i])
    {
        if(!visited[it])
        {
            count+=dfs(it);
        }
    }
    return count;
}
int main()
{
    ofstream fout ("moocast.out");
    ifstream fin ("moocast.in");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        in(a);in(b);in(r);
        v.pb({a,b});
        radius.pb(r);
        visited.pb(false);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            int x=v[i].F-v[j].F;
            int y=v[i].S-v[j].S;
            int dis=x*x + y*y;
            if(dis <= radius[i]*radius[i])
            {
                adjlist[i].pb(j);
            }
        }
    }
    int answer=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            visited[j]=false;
        answer=max(answer,dfs(i));
    }
    cout<<answer<<endl;
    return 0;
}
