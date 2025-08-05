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

ll a, b, c, k;
bool pred (ll mid) {
    ll pol = a * mid * mid + b * mid + c;
    return pol >= k;
}

int main(){
    optimize();

    //Sieve();

    int t;
    cin >> t;

    while (t--) {
        cin >> a >> b >> c >> k;

        ll l = 0, r = 300000, ans = -1;

        while (l <= r) {
            ll mid = (l + r) / 2;

            if (pred(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << ans << endl;
    }
}
