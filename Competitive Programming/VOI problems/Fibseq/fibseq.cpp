// Tonight Gehrman Sparrow joins the hunt
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define miracle_invoker ios_base::sync_with_stdio(false);
#define attendant_of_mysteries cin.tie(NULL);
#define the_fool freopen("fibseq.inp", "r", stdin);
#define lord_of_the_mysteries freopen("fibseq.out", "w", stdout);
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

int t,n,k;
long long x;

struct matrix 
{
  long long a[5][5]; 
};

matrix ident()
{
  matrix res;
  for (int i=1; i<=2; i++)
  {
    for (int j=1; j<=2; j++)
    {
      res.a[i][j]=(i==j);
    }
  }
  return res;
}


matrix operator*(const matrix &c, const matrix &b) 
{
  matrix res;
  //res.a[1][1]=res.a[1][2]=res.a[2][1]=res.a[2][2]=0;
  for (int i=1; i<=2; i++)
  {
    for (int j=1; j<=2; j++)
    {
      res.a[i][j]=0;
      for (int z=1; z<=2; z++)
      {
        res.a[i][j] += (c.a[i][z] * b.a[z][j]) % k;
      }
    }
  }
  return res;
}

matrix exponen(matrix a, long long n)
{
  if (n==0)
  {
    matrix res = ident();
    return res;
  }
  matrix val = exponen(a, n/2);
  if (n&1) return val*val*a;
  else return val*val;
}

long long getfib(long long dis)
{
  dis -= 2;
  matrix fib;
  fib.a[1][1]=fib.a[1][2]=fib.a[2][1]=1;
  fib.a[2][2]=0;
  matrix val;
  val.a[1][1]=val.a[2][1]=1;

  matrix ex = exponen(fib, dis);
  matrix ans = ex * val;
  return ans.a[1][1]%k;
}

int pre[1000006+16];
long long a[1000005+15];
long long sum[1000005+16];

void solve()
{
  for (int i=0; i<=n; i++)
  {
    a[i]=0;
    pre[i]=0;
    sum[i]=0;
  }
  a[1] = getfib(x);
  a[2] = getfib(x+1);
  pre[0]=1;
  pre[a[1]]=2;
  pre[(a[1]+a[2])%k]=3;
  sum[1] = a[1];
  sum[2] = (a[1] + a[2]) % k;
  for (int i=3; i<=n; i++)
  {
    a[i] = (a[i-1] + a[i-2])%k;
    sum[i] = (sum[i-1] + a[i]) % k;

    if (pre[sum[i]] > 0)
    {
      cout << i - pre[sum[i]] + 1 << " ";
      for (int j=pre[sum[i]]; j<=i; j++)
      {
        cout << j+x-1 << " ";
      }
      cout << endl;
      return;
    }
    pre[sum[i]] = i+1;
  }
  cout << 0 << endl;
}

int main()
{
	miracle_invoker; attendant_of_mysteries;
  #ifndef ONLINE_JUDGE
		the_fool; lord_of_the_mysteries;
  #endif
  cin >> t;
  while (t--)
  {
    cin >> n >> x >> k;
    solve();
  }
	return 0;
}
