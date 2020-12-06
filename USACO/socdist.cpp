#define cin fin
#define cout fout

using namespace std;
ll n,m;
vector<pair<ll,ll>> v;
bool pos(ll x)
{
    
    ll prev=-1*inf;
    ll count=0;
    for(int i=0;i<m;i++)
    {
        ll newpos=prev+x;
        newpos=max(newpos,v[i].F);
        
        if(newpos > v[i].S)
        {
            continue;
        }        
        
        ll space=(v[i].S - newpos + 1);
        ll more=(space + x - 1)/x;
        count+=more;
        prev=newpos + (more-1)*x;
    }
    
    if(count >= n){
        
        return true;
    }
    return false;
}
int main()
{
    ofstream fout ("socdist.out");
    ifstream fin ("socdist.in");
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        inl(a);inl(b);
        v.pb({a,b});
    }
    sort(v.begin(),v.end());
    ll answer;
    ll s=0;
    ll e=1e18;
    while(s<=e)
    {
        ll mid=(s+e)/2;
        if(pos(mid))
        {
            answer=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    cout<<answer<<endl;
    return 0;
}
