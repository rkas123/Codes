//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

using namespace std;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
    in(n);in(q);
    int A[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            if(ch=='*')
                A[i][j]=1;
            else
                A[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            A[j][i]+=A[j-1][i];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            A[i][j]+=A[i][j-1];
        }
    }
    while(q--)
    {
        in(x1);in(y1);in(x2);in(y2);
        x1--;x2--;y1--;y2--;
        ll answer=A[x2][y2];
        if(x1 > 0 && y1 > 0)
        {
            answer+=A[x1-1][y1-1];
        }
        if(x1 >0)
        {
            answer-=A[x1-1][y2];
        }
        if(y1 > 0)
        {
            answer-=A[x2][y1-1];
        }
        cout<<answer<<endl;
    }

    return 0;
}
