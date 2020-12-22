//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int X[]={1,-1,0,0};
int Y[]={0,0,1,-1};
int n,lx,ly,rx,ry;
char A[21][21];
bool vis[21][21];
int colors[26];
bool ok(int x,int y)
{
    if(x<lx || y<ly || x>rx || y>ry)
        return false;
    return true;
}
void dfs(int x,int y)
{
    vis[x][y]=true; 
    for(int i=0;i<4;i++)
    {
        int newX=x+X[i];
        int newY=y+Y[i];
        if(ok(newX,newY) && !vis[newX][newY] && A[x][y]==A[newX][newY])
        {
            dfs(newX,newY);
        }
    }
}
bool check()
{
    for(int i=0;i<26;i++)
    {
        colors[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            vis[i][j]=false;
    }
    for(int i=lx;i<=rx;i++)
    {
        for(int j=ly;j<=ry;j++)
        {
            if(vis[i][j])
                continue;
            colors[A[i][j]-'A']++;
            dfs(i,j);
        }
    }
    int count1=0,count2=0;
    for(int i=0;i<26;i++)
    {
        if(colors[i]==1)
        {
            count1++;
        }
        else if(colors[i] > 1)
        {
            count2++;
        }
    }
    if(count1==1 && count2 == 1)
        return true;
    return false;
}
int main()
{
    ofstream fout ("where.out");
    ifstream fin ("where.in");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
    vector<pair<pii,pii>> v;
    int answer=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=i;k<n;k++)
            {
                for(int l=j;l<n;l++)
                {
                    lx=i;
                    ly=j;
                    rx=k;
                    ry=l;
                    if(check())
                    {
                        v.pb({{lx,ly},{rx,ry}});
                    }
                }
            }
        }
    }
    for(int i=0;i<v.size();i++)
    {
        bool flag=true;
        for(int j=0;j<v.size();j++)
        {
            if(i==j)
                continue;
            if(v[j].F.F <= v[i].F.F && v[j].F.S <= v[i].F.S && v[j].S.F >= v[i].S.F && v[j].S.S >= v[i].S.S)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            answer++;
        }
    }
    cout<<answer<<endl;
    return 0;
}
