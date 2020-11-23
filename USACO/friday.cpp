//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
bool isleap(int n)
{
    if(n%100 == 0)
    {
        if(n%400 == 0)
            return true;
        return false;
    }
    if(n%4==0)
        return true;
    return false;
}
int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    in(n);
    int answer[]={0,0,0,0,0,0,0};
    int curr=5;
    answer[curr]++;
    int year=1900;
    while(n--)
    {
        if(isleap(year))
            months[1]=29;
        else
            months[1]=28;
        for(int i=0;i<12;i++)
        {
            curr+=months[i];
            curr%=7;
            answer[curr]++;
        }
        year++;
    }
    answer[curr]--;
    int i=5;
    do{
        cout<<answer[i];
        i++;
        if(i!=5)
            cout<<" ";
        else
            break;
        i%=7;
    }while(i!=5);
    cout<<endl;
    return 0;
}
