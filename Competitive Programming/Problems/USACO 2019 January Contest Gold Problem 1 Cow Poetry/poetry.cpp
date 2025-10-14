// Tonight Gehrman Sparrow joins the hunt
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define Monarch_of_Decay ios_base::sync_with_stdio(false);
#define Son_of_Chaos cin.tie(nullptr);
#define Mother_Goddess_of_Depravity cout.tie(nullptr);
#define Inextinguishable_Ravings freopen("poetry.in", "r", stdin);
#define Lord_of_The_Mysteries freopen("poetry.out", "w", stdout);
#define Circle_of_Inevitability ONLINE_JUDGE
#define Primordial signed
#define God_Almighty main()

int n,m,k;
pair<int, int> a[5010];
int ct[27];
const long long mod = 1e9+7;
long long dp[5010][5010];
long long pre[5010];
int mx_class=0;

__int128 expo(__int128 cur, int n, long long mod)
{
  if (n==0) return 1;
  __int128 val = expo(cur, n/2, mod) % mod;
  if (n&1) return val%mod * val%mod * cur%mod;
  else return val%mod * val%mod;
}

Primordial God_Almighty
{
	Monarch_of_Decay 
  Son_of_Chaos
  Mother_Goddess_of_Depravity
  #ifndef ONLINE_JUDGE
		Inextinguishable_Ravings
    Lord_of_The_Mysteries
  #endif
	cin >> n >> m >> k;
  for (int i=1; i<=n; i++)
  {
    cin >> a[i].first >> a[i].second;
    mx_class = max(mx_class, a[i].second);
  }
  for (int i=1; i<=m; i++)
  {
    char val;
    cin >> val;
    ct[val-'A']++;
  }
  pre[0]=1;
  dp[0][0]=1;
  for (int i=1; i<=k; i++)
  {
    for (int j=1; j<=n; j++)
    {
      int len = a[j].first;
      int type = a[j].second;
      if (i < len) continue;
      dp[i][type] = (dp[i][type] + pre[i-len]%mod) % mod;
    }
    for (int j=1; j<=mx_class; j++) pre[i] = (pre[i] + dp[i][j]%mod) % mod;
  }
  long long ans=1;
  for (int i=0; i<=26; i++) 
  {
    if (ct[i]==0) continue;
    int am = ct[i];
    long long res=0;
    for (int j=1; j<=mx_class; j++)
    {
      long long ways = dp[k][j];
      __int128 total = expo(ways, am, mod) % mod;
      res += total;
      res %= mod;
    }
    ans = ans * res % mod;
  }
  cout << ans%mod;
	return 0;
}
