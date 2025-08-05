// Tonight Gehrman Sparrow joins the hunt
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define miracle_invoker ios_base::sync_with_stdio(false);
#define attendant_of_mysteries cin.tie(NULL);
#define the_fool freopen("hvmax.inp", "r", stdin);
#define lord_of_the_mysteries freopen("hvmax.out", "w", stdout);
#define circle_of_inevitability ONLINE_JUDGE

// The Fool That Does Not Belong To This Era
// The Mysterious Ruler Above The Grey Fog
// The King Of Black And Yellow Who Wields Good Luck
  
// The Circle Of Inevitability 
// The Eternal Cycle
// The Predestined Destiny
// Embodiment of Cause, Effect and Process
// Symbol of Past, Future and Present

// The Trojan Horse of Fate
// The Slug of Time 
// The Loopholes in Rules 
// The Manifestations of All Errors 
  
// The Shadow That Wanders Through Fate
// The Past God of Deceit
// The Destined Messiah

// The Clock-Hand that Tampers with Time 
// The Shadow that Roams across Fate 
// The Embodiment of Deceit and Trickery

int m,n,k;
int a[1005+15][1005+15], pre[1005+15][1005+15];
long long ans=-1e18;

int main()
{
	miracle_invoker; attendant_of_mysteries;
  #ifndef ONLINE_JUDGE
		the_fool; lord_of_the_mysteries;
  #endif
	cin >> m >> n >> k;
  for (int i=1; i<=m; i++)
  {
    for (int j=1; j<=n; j++)
    {
      cin >> a[i][j];
      pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
    }
  }
  for (int i=k; i<=n; i++)
  {
    for (int j=k; j<=n; j++)
    {
      long long val = pre[i][j] - pre[i-k][j] - pre[i][j-k] + pre[i-k][j-k];
      ans=max(ans, val);
    }
  }
  cout << ans;
	return 0;
}
