/*
ID: rkrupes1
TASK: 248
LANG: C++
*/
#include<bits/stdc++.h>

#define int long long
#define pll pair<long long,long long>

#define in(x) long long x;cin>>x
#define pb push_back
#define F first
#define S second
#define endl "\n"

#define test() int t;cin>>t;while(t--)
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
#define deb(x) cout<<#x<<" "<<x<<endl;

const long long mod = 1e9 + 7;
const int MAX = INT_MAX;
const long long inf = 1e18 + 5;
const double pi = 3.14159265358979323846;

int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};

#define cin fin
#define cout fout

using namespace std;
int32_t main()
{
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ofstream fout ("248.out");
	ifstream fin ("248.in");
	in(n);
	vector<int> v(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		ans = max(ans, v[i]);
	}

	int L[n][n], R[n][n], S[n][n];
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));
	memset(S, -1, sizeof(S));
	//l----r , l---k & k----j
	//outer loop end
	//inner loop start
	//both rev

	for (int j = 0; j < n; j++)
	{
		L[j][j] = v[j];
		R[j][j] = v[j];
		S[j][j] = 1;

		for (int i = j - 1; i >= 0; i--)
		{
			for (int k = i; k < j; k++)
			{
				//i,k && k+1,j
				L[i][j] = max(L[i][k], L[i][j]);
				R[i][j] = max(R[k + 1][j], R[i][j]);

				//max here
				if (R[i][k] == L[k + 1][j])
				{
					int pos = R[i][k] + 1;

					ans = max(ans, pos);

					if (S[i][k] == 1)
					{
						if (pos >= L[i][j])
						{
							L[i][j] = pos;
						}
					}
					if (S[k + 1][j] == 1)
					{
						if (pos >= R[i][j])
						{
							R[i][j] = pos;
						}
					}
					if (S[i][k] == 1 && S[k + 1][j] == 1)
						S[i][j] = 1;
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}
