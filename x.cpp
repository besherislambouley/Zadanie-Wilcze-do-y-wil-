/*
 * lets first learn how to check if a segment could be the answer , assume the f(l,r) is the max sum of a window of size d in the segemtn , sum(l,r) is the sum of a segment so easily you can see the if sum(l,r) - f(l,r) <= p than this segment may be the answer , instead of trying all the l,r pairs you can use two pointers 
 */ 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 400
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll mod=1e9+7;
const ll inf= 4e18;
const ld pai=acos(-1);
ll n , num , d;
mset<ll>s;
ll a[2000009] , bs[2000009] , sum[2000009] ;
ll SUM ( int l, int r ){
	ll ans = bs[r];
	if ( l ) ans -= bs [l-1];
	return ans;
}
int check ( int l ,int r ){
	ll all = SUM ( l, r );
	ll mx  = *s.rbegin ();
	ll more = all - mx ;
	return ( more <= num );
}
int main(){
	scanf("%lld%lld%lld",&n,&num,&d);
	for ( int i =0 ;i < n ;i ++ ){
		scanf("%lld",&a[i]);
		bs [i] = a[i];
		if ( i ) bs[i]+=bs[i-1];
	}
	for ( int i =d-1 ; i < n ;i ++ ){
		int l = i - d +1 , r = i ;
		sum [i] = SUM ( l ,r );
	}
	int l = 0 ;
	int ans = 0 ;
	for ( int r = d-1 ; r < n ; r ++ ){
		s.ins ( sum [r] ) ;
		while (  !check(l,r) ) {
			s.era ( s.find ( sum [l+d-1] ) ) ;
			l ++ ;
		}
		ans = max ( ans , r-l+1 ) ;
	}
	printf("%d\n",ans);
}
