///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;
#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
#define input(v)   for(auto &x: v)cin>>x
#define SetBit(x,k) (x|=(1LL<<k))
#define ClearBit(x,k) (x&=~(1LL<<k))
#define CheckBit(x,k) ((x>>k)&1)
#define ChangeBit(x,k) (x^=(1LL<<k))
#define mod 1000000007
#define N 100005

ll fx[]= {0,0,1,-1,1,1,-1,-1};
ll fy[]= {1,-1,0,0,-1,1,-1,1};

void faltu ()
{
    cerr << endl;
}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest)
{
    cerr << arg << ' ';
    faltu(rest...);
}

ll gcd ( ll a, ll b )
{
    return __gcd ( a, b );
}
ll lcm ( ll a, ll b )
{
    return a * ( b / gcd ( a, b ) );
}
int maxN=1e4;
vector<ll>pw;

int main()
{
    optimize();
    for(int i=1; i<=maxN; i++)
    {
        pw.push_back(pow(i,3));///কিঊবের পূরা ভেক্টর প্রি ক্যাল্কুলেশন করা,যেন(x-[pw[i]/a^3]) সেটা খুজে বের করা যেতে পারে।
    }
ll t;
cin>>t;
while(t--)
    {
        long long x;
        cin>>x;
        bool ok=false;
        for(ll i=0; i<maxN; i++)
        {

            if(pw[i]>=x)///এই শর্তটা হলোঃ যদি বিয়োগ করার পরে দরকারি value টা নেগেটিভ হয়ে যায়,তা যেন পরে বাইনারি সার্চ করে না খুজা হয়,সেজন্য ব্রেক করে দেওয়া।
            {
                break;
            }
            ll l=0,r=maxN-1,mid;
            ll dorkar=x-pw[i];///এটাই মেইন লজিক,দেওয়া এক্স এর মান থেকে প্রি ক্যাল্কুলেশন করা প্রতিটি মান বিয়োগ করে দরকারি মান টা এরের মধ্যে আছে কিনা,তা বাইনারি সার্চ করে চেক করা।
            while(l<=r)
            {
                mid=l+(r-l)/2;
                if(pw[mid]==dorkar)
                {
                    ok=true;
                    break;
                }
                else if(pw[mid]>dorkar)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
        }
        if(ok)
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

