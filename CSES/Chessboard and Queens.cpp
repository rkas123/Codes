//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

using namespace std;
char ch[8][8];
int answer=0;

bool check(string s)
{

    for(int i=0;i<8;i++)
    {
        int y=s[i]-'0';
        if(ch[i][y]=='*')
            return false;
        int X=i-1;int Y=y-1;
        while(X>=0 && Y>=0)
        {
            if(s[X]-'0'==Y)
                return false;
            X--;Y--;
        }
        X=i-1;Y=y+1;
        while(X>=0 && Y<8)
        {
            if(s[X]-'0'==Y)
            {
                return false;
            }
            X--;Y++;
        }
    }
    //cout<<s<<endl;
    return true;
}
void permute(string s,int l,int r)
{
    if(l==r)
    {
        if(check(s))
            answer++;
        return;
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(s[l],s[i]);
            permute(s,l+1,r);
            swap(s[l],s[i]);
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
    
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin>>ch[i][j];
        }
    }
    string permutation="01234567";
    permute(permutation,0,7);
    cout<<answer<<endl;
    return 0;
}
