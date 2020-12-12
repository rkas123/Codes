//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

using namespace std;
bool cmp(pii a,pii b)
{
    return a.S < b.S;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif   
    in(n);in(k);
    vpll v;
    for(int i=0;i<n;i++)
    {
        inl(a);inl(b);
        v.pb({a,b});
    }
    multiset<ll> s;
    for(int i=0;i<k;i++)
    {
        s.insert(0);
    }
    s.insert(inf);
    sort(v.begin(),v.end(),cmp);
    int answer=0;
    for(int i=0;i<n;i++)
    {
        
        auto it=s.lower_bound(v[i].F);
        if(*it == v[i].F)
        {
            s.erase(it);
            s.insert(v[i].S);
            answer++;
            continue;
        }
        if(it==s.begin())
        {
            continue;
        }
        it--;
        if(*it <= v[i].F)
        {
            s.erase(it);
            s.insert(v[i].S);
            answer++;
        }
    }
    cout<<answer<<endl;
    return 0;
}
