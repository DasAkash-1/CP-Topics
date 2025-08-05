#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define vi vector <int>
#define vll vector <long long>
#define pii pair<int, int>
#define mii map <int, int>
#define mll map <long long, long long>
#define print_yes cout << "yes" << '\n'
#define print_no cout << "no" << '\n'

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

bool isOK(ll mid, ll n) {
    ll y = (mid * (mid + 1)) / 2;
    return y <= n;
}

int main(){
    optimize();

    //Sieve();

    int t;
    cin >> t;
    
    while (t--) {
        ll n;
        cin >> n;

        ll l = 1, r = n, ans = -1;

        while (l <= r) {
            ll mid = l + (r - l) / 2;

            if (isOK(mid, n)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        ll y_m = (ans * (ans + 1)) / 2;
        if (y_m != n) cout << "NAI" << endl;
        else cout << ans << endl;
    }
}
