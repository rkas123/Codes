//https://github.com/rkas123/TEMPLATE/blob/master/Template.cpp
//Template taken from here

#define cin fin
#define cout fout

using namespace std;
int A[50005];
int n,k;
int main()
{
    ofstream fout ("diamond.out");
    ifstream fin ("diamond.in");
    cin>>n>>k;
    int L[n];
    int R[n];
    for(int i=0;i<n;i++){
    	cin>>A[i];
    	L[i]=0;
    	R[i]=0;
    }
    sort(A,A+n);
    int s=0;
    for(int i=0;i<n;i++)
    {
    	while(A[i]-A[s] > k)
    	{
    		s++;
    	}
    	if(i==0)
    		L[i]=i-s+1;
    	else
    	{
    		L[i]=max(L[i-1],i-s+1);
    	}
    }
    int e=n-1;
    for(int i=n-1;i>=0;i--)
    {
    	while(A[e]-A[i] > k)
    	{
    		e--;
    	}
    	if(i==n-1)
    		R[i]=e-i+1;
    	else
    	{
    		R[i]=max(R[i+1],e-i+1);
    	}
    }
    int answer=0;
    for(int i=0;i<n-1;i++)
    {
    	answer=max(answer,L[i]+R[i+1]);
    }
    cout<<answer<<endl;
    return 0;	
}
