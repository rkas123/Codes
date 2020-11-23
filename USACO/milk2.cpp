//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int main()
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    in(n);
    vector<pii> v;
    for(int i=0;i<n;i++)
    {
        in(a);in(b);
        v.pb({a,b});
    }
    sort(v.begin(),v.end());
    int idle=0,occ=0;
    int s=v[0].F;
    int e=v[0].S;
    idle=0;
    occ=e-s;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].F > e)
        {
            idle=max(idle,v[i].F-e);
            occ=max(occ,e-s);
            s=v[i].F;
            e=v[i].S;
        }
        else
        {
            e=max(e,v[i].S);
        }
    }
    cout<<occ<<" "<<idle<<endl;
    return 0;
}
