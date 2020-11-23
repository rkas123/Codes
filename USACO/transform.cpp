//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
char A[10][10],B[10][10],temp[10][10];
int n;
void Copy()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            temp[i][j]=A[i][j];
    }
}
bool check()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(B[i][j] != temp[i][j])
                return false;
        }
    }
    return true;
}
void rotate()
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(temp[i][j],temp[j][i]);
        }
    }
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(temp[i][j],temp[n-i-1][j]);
        }
    }
}
void Reflect()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            swap(temp[i][j],temp[i][n-1-j]);
        }
    }
}

int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>A[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>B[i][j];
    }
    int answer=7;
    Copy();
    if(check())
    {
        
        answer=6;
    }
    rotate();
   
    if(check())
    {
        
        answer=3;
    }
    rotate();
   
    if(check())
    {
        
        answer=2;
    }
    rotate();
   
    if(check())
    {
        
        answer=1;
    }
    Copy();
    Reflect();
   
    if(check())
    {
        answer=min(answer,4);
    }
    rotate();
   
    if(check())
    {
        answer=min(answer,5);
    }
    rotate();
   
    if(check())
    {
        answer=min(answer,5);
    }
    rotate();
   
    if(check())
    {
        answer=min(answer,5);
    }   
    cout<<answer<<endl;


    return 0;
}
