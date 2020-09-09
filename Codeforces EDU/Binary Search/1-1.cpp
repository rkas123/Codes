#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define pii pair<int,int>
#define vi vector<int> 
#define vvi vector<vi> 
#define vpii vector<pii> 

#define pll pair<ll,ll> 
#define vl vector<ll> 
#define vvl vector<vl> 
#define vpll vector<pll> 

#define inl(x) ll x;cin>>x
#define in(x) int x;cin>>x
#define mk(t,a,n) t*a = new t[n]
#define inp(a,n) for(int i = 0;i<n;i++)cin>>a[i]
#define sea(a,n,v) for(int i = 0;i<n;i++)a[i] = v
#define pb push_back
#define F first
#define S second
#define LEFT 2*I+1
#define RIGHT 2*I+2
#define endl "\n"
#define mii map<int,int>
#define mll map<ll,ll>
#define ub upper_bound
#define lb lower_bound
#define um unordered_map
#define lop(i,n) for(ll i=0;i<n;i++)
#define lop1(i,n) for(ll i=1;i<=n;i++)
#define lopr(i,n) for(ll i=n-1;i>=0;i--)
#define test() int t;cin>>t;while(t--)
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int mod = 1e9+7,MAX = 1e6+5;
const ll inf = 1e18+5;
const double pi = 3.14159265358979323846;

//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

using namespace std;
bool bs(ll*A,ll n,ll key)
{
    ll s=0;
    ll e=n-1;
    while(s<=e)
    {
        ll mid=(s+e)/2;
        if(A[mid]==key)
            return true;
        if(A[mid] > key)
            e=mid-1;
        else
            s=mid+1;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif
    inl(n);inl(q);
    mk(ll,A,n);
    for(ll i=0;i<n;i++)
        cin>>A[i];
    while(q--)
    {
        inl(t);
        if(bs(A,n,t))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;   
}
