//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b;
    cin>>a>>b;
    ll first=1;
    for(int i=0;i<a.length();i++)
    {
        int num=a[i]-'A'+1;
        first*=num;
        first%=47;
    }
    ll second=1;
    for(int i=0;i<b.length();i++)
    {
        int num=b[i]-'A'+1;
        second*=num;
        second%=47;
    }
    if(first==second)
    {
        cout<<"GO"<<endl;
    }
    else
        cout<<"STAY"<<endl;
    return 0;
}
