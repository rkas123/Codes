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
    in(x);
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    int s=0;
    int e=0;
    int answer=0;
    int curr=A[0];
    while(e<n)
    {
        if(curr < x)
        {
            e++;
            curr+=A[e];
        }
        else if (curr > x)
        {
            curr-=A[s];
            s++;
        }
        else if(curr==x)
        {
            //cout<<s<<" "<<e<<endl;
            answer++;
            curr-=A[s];
            s++;
            
        }
    }
    cout<<answer<<endl;
    return 0;
}
