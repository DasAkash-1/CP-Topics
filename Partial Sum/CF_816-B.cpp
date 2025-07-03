#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define mxe max_element
#define mne min_element
#define vi vector <int>
#define vll vector <long long>
#define pii pair<int, int>
#define pll pair<long, long>
#define pss pair<string, string>
#define psi pair<pss, int>
#define mii map <int, int>
#define mll map <long long, long long>
#define umii unordered_map <int, int>
#define ust unordered_set <int>
#define umst unordered_multiset <int>
#define print_yes cout << "yes" << '\n'
#define print_no cout << "no" << '\n'

bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int gcd(int a, int b) { return b ? gcd (b, a % b) : a; }
int lcm(int a, int b) { return abs(a * (b / gcd(a, b))); }

bool cmp2 (int a, int b) { return a > b; }

int digit_sum (int a) {
    return (a == 0) ? 0 : a % 10 + digit_sum(a / 10);
}
const ll N = 200005;

int main(){
    optimize();

    //Sieve();

    ll n, k, q;
    cin >> n >> k >> q;
    ll rcp = n;

    vll a(N, 0), b(N, 0);

    while (rcp--)
    {
        ll l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }

    for (int i = 1; i <= N; i++) {
        b[i] = b[i - 1] + a[i];
    }

    vll ftmp(N, 0), psum(N, 0);

    for (int i = 0; i <= N; i++) {
        if (b[i] >= k) ftmp[i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + ftmp[i];
    }

    while (q--){
        ll l, r;
        cin >> l >> r;
        cout << psum[r] - psum[l - 1] << endl;
    }
}
