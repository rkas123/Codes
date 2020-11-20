//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int main()
{
    ofstream fout ("paint.out");
    ifstream fin ("paint.in");
    in(a);in(b);
    in(c);in(d);
    if(d < a || c > b)
    {
        cout<<(b-a) + (d-c)<<endl;
    }
    else
    {
        int s=min(a,c);
        int e=max(b,d);
        cout<<e-s<<endl;
    }
    return 0;
}
