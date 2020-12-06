//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int n,m,c;
ll A[100005];
bool pos(ll x)
{
    ll buses=0;
    int s=0;
    while(s<n)
    {
        ll curr=A[s];
        buses++;
        s++;
        int count=1;
        while(s<n && count<c)
        {
            if(A[s]-curr <= x)
            {
                s++;
                count++;
            }
            else
            {
                break;
            }
        }
    }
    if(buses <= m)
        return true;
    return false;
}
int main()
{
    ofstream fout ("convention.out");
    ifstream fin ("convention.in");
    cin>>n>>m>>c;
    for(int i=0;i<n;i++)
        cin>>A[i];
    sort(A,A+n);
    ll s=0;
    ll e=A[n-1];
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
