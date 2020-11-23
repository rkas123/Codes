//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int main()
{
    ofstream fout ("haybales.out");
    ifstream fin ("haybales.in");
    in(n);in(q);
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        in(t);
        v.pb(t);
    }
    sort(v.begin(),v.end());
    while(q--)
    {
        in(s);in(e);
        int si=lower_bound(v.begin(),v.end(),s)-v.begin();
        int ei=lower_bound(v.begin(),v.end(),e)-v.begin();
        int ans=ei-si;
        if(v[ei]==e)
            ans++;
        cout<<ans<<endl;
    }

    return 0;
}
