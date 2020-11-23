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
    vpii v;
    in(n);
    for(int i=0;i<n;i++)
    {
        in(a);
        v.pb({a,1});
        in(b);
        v.pb({b+1,-1});
    }
    sort(v.begin(),v.end());
    int answer=0;
    int curr=0;
    for(int i=0;i<v.size();i++)
    {
        curr+=v[i].S;
        answer=max(curr,answer);
    }
    cout<<answer<<endl;
    return 0;
}
