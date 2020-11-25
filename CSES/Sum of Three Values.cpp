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
    in(n);
    in(t);
    vector<pii> v;
    for(int i=0;i<n;i++)
    {
        in(a);
        v.pb({a,i+1});
    }
    sort(v.begin(),v.end());
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        int curr=t-v[i].F;
        int s=i+1;
        int e=v.size()-1;
        while(s<e)
        {
            if(v[s].F + v[e].F == curr)
            {
                cout<<v[i].S<<" "<<v[s].S<<" "<<v[e].S<<endl;
                flag=true;
                break;
            }
            else if(v[s].F + v[e].F > curr)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
        if(flag)
            break;
    }
    if(!flag)
        cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
