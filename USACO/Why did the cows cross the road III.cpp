//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int dirx[]={1,-1,0,0};
int diry[]={0,0,1,-1};
int n,k,r;
int A[101][101];
bool row[101][101];
bool col[101][101];
bool vis[101][101];
int Count;
int answer=0;
bool ok(int x,int y)
{
	if(x<=0 || y<=0 || x>n || y>n)
	{
		return false;
	}
	return true;
}
void dfs(int x,int y)
{
	//cout<<x<<","<<y<<" ";
	vis[x][y]=true;
	if(A[x][y]==1)
		Count++;
	for(int i=0;i<4;i++)
	{
		int newX=x+dirx[i];
		int newY=y+diry[i];
		if(!ok(newX,newY))
			continue;
		if(x==newX)
		{
			int Y=min(y,newY);
			if(row[x][Y]  && !vis[newX][newY])
			{
				dfs(newX,newY);
			}
				
		}
		if(y==newY)
		{
			int X=min(x,newX);
			if(col[X][y]  && !vis[newX][newY])
			{
				dfs(newX,newY);
			}
		}
	}
}
int main()
{
    ofstream fout ("countcross.out");
    ifstream fin ("countcross.in");
    cin>>n>>k>>r;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		A[i][j]=0;
    		row[i][j]=true;
    		col[i][j]=true;
    		vis[i][j]=false;
    	}
    }
    for(int i=0;i<r;i++)
    {
    	in(a);in(b);in(c);in(d);
    	if(a==c)
    	{	
    		int y=min(b,d);
    		row[a][y]=false;
    	}
    	else if(b==d)
    	{
    		int x=min(a,c);
    		col[x][b]=false;
    	}
    }
    for(int i=0;i<k;i++)
    {
    	in(a);in(b);
    	A[a][b]=1;
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(!vis[i][j] && A[i][j]==1)
    		{
    			Count=0;
    			dfs(i,j);
    			answer+=((Count*(Count-1))/2);
    		}
    	}
    }
    answer=(k*(k-1))/2 - answer;
    cout<<answer<<endl;
    return 0;
}
