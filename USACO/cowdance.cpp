//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
ll n,t;
ll A[10005];
bool pos(ll x)
{
    int s=0;
    int e=x;
    priority_queue<ll,vector<int>,greater<int>> pq;
    while(s<x)
    {
        pq.push(A[s]);
        s++;
    }
    while(e<n)
    {
        ll time=pq.top();
        pq.pop();
        pq.push(time+A[e]);
        e++;
    }
    ll greatest=0;
    while(!pq.empty())
    {
        greatest=pq.top();
        pq.pop();
    }
    //cout<<x<<" "<<greatest<<endl;
    if(greatest <= t)
        return true;
    return false;
}
int main()
{
    ofstream fout ("cowdance.out");
    ifstream fin ("cowdance.in");
    cin>>n>>t;
    for(int i=0;i<n;i++)
        cin>>A[i];
    ll s=1;
    ll e=n;
    ll answer;
    while(s<=e)
    {
        ll mid=(s+e)/2;
        if(pos(mid))
        {
            answer=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    cout<<answer<<endl;
    return 0;
}
