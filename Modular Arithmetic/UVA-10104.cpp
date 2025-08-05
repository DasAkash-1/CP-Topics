#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define mxe max_element
#define mne min_element
#define vi vector <int>
#define vll vector <long long>
#define pii pair<ll, ll>
#define pss pair<string, string>
#define psi pair<pss, ll>
#define mll map <ll, ll>
#define pb push_back
#define print_yes cout << "yes" << '\n'
#define print_no cout << "no" << '\n'
#define srt(v) sort(v.begin(), v.end())

bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int gcd(ll a, ll b) { return b ? gcd (b, a % b) : a; }
int lcm(ll a, ll b) { return abs(a * (b / gcd(a, b))); }

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int digit_sum (int a) {
    return (a == 0) ? 0 : a % 10 + digit_sum(a / 10);
}

int lb (vll &v, ll tgt) {
    ll n = v.size();
    ll l = 0, r = n - 1, ans = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (v[mid] < tgt) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}
int ub (vll &v, ll tgt) {
    ll n = v.size();
    ll l = 0, r = n - 1, ans = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (v[mid] <= tgt) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

ll egcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

int main(){
    optimize();

    //Sieve();

    ll a, b, x, y;

    while (cin >> a >> b) {
        ll g = egcd(a, b, x, y);
        cout << x << " " << y << " " << g << endl;
    }
}
