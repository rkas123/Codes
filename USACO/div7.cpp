//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int main()
{
    ofstream fout ("div7.out");
    ifstream fin ("div7.in");
    in(n);
    int A[n];
    int first[7];
    int last[7];
    for(int i=0;i<7;i++)
    {
        first[i]=-1;
        last[i]=-1;
    }
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        sum+=A[i];
        ll rem=sum%7;
        if(first[rem]==-1)
        {
            first[rem]=i;
        }
        last[rem]=i;
    }
    int answer=max(last[0]+1,0);
    for(int i=1;i<7;i++)
    {
        answer=max(answer,last[i]-first[i]);
    }
    cout<<answer<<endl;
    return 0;
}
