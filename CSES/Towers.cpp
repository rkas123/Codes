//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

using namespace std;
multiset<int> s;
int n;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
    cin>>n;
    s.insert(MAX);
    while(n--)
    {
        in(t);
        auto it = s.upper_bound(t);
        if(it==s.end())
        {
            s.insert(t);
        }
        else
        {
            s.erase(it);
            s.insert(t);
        }
    }
    cout<<s.size()<<endl;
    return 0;
}
