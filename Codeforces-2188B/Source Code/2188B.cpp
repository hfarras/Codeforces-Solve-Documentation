#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    
    vector<bool> v;
    ll sum = count(s.begin(), s.end(), '1');
    if(n <= 2) cout << 1 << "\n";
    else {
        for(int i = 0; i < n; i++) {
            if(i == 0 && (s[i] == '1' || s[i+1] == '1')) v.push_back(false);
            else if(i == n-1 && (s[i] == '1' || s[i-1] == '1')) v.push_back(false);
            else {
                if(s[i] == '1' || s[i+1] == '1' || s[i-1] == '1') v.push_back(false);
                else v.push_back(true);
            }
        }
    
        int cnt = 0;
        for(int j = 0; j <= n; j++) {
            if(j < n && v[j] == true) cnt++;
            else {
                if(cnt > 0) {
                    if((cnt + 1) % 3 == 0) sum += (cnt+1)/3;
                    else if((cnt + 3) % 3 == 0) sum += (cnt+3)/3 -1;
                    else if((cnt + 5) % 3 == 0) sum += (cnt+5)/3 -1;
                }
                cnt = 0;
            }
        }
        cout << sum << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
