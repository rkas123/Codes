//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int X[]={1,-1,0,0};
int Y[]={0,0,1,-1};
int n;
char A[1001][1001];
bool vis[1001][1001];
int a,p;
bool ok(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    return true;
}
void dfs(int x,int y)
{
    vis[x][y]=true;
    a++;
    int count=0;
    for(int i=0;i<4;i++)
    {
        int newX=x+X[i];
        int newY=y+Y[i];
        if(ok(newX,newY) && A[newX][newY]=='#')
        {
            count++;
        }
    }
    p+=(4-count);
    for(int i=0;i<4;i++)
    {
        int newX=x+X[i];
        int newY=y+Y[i];
        if(ok(newX,newY) && !vis[newX][newY] && A[newX][newY]=='#')
        {
            dfs(newX,newY);
        }
    }
}
int main()
{
    ofstream fout ("perimeter.out");
    ifstream fin ("perimeter.in");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>A[i][j];
            vis[i][j]=false;
        }
    }
    int area=0,perimeter;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j] && A[i][j]=='#')
            {
                a=0;p=0;
                dfs(i,j);
                if(a>area)
                {
                    area=a;
                    perimeter=p;
                }
                else if(a==area)
                {
                    perimeter=min(perimeter,p);
                }
            }   
        }
    }
    cout<<area<<" "<<perimeter<<endl;
    return 0;
}
