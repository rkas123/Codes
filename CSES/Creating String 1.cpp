//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

using namespace std;
set<string> perms;
void permute(string s,int l,int r)
{
    if(l==r)
    {
        perms.insert(s);
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
    string s;
    cin>>s;
    permute(s,0,s.length()-1);
    cout<<perms.size()<<endl;
    while(!perms.empty())
    {
        cout<<*(perms.begin())<<endl;
        perms.erase(perms.begin());
    }
    return 0;
}
