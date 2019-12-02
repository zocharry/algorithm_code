#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 200100;
ll a[N];
ll b[N];
int find(int left,int right, ll e) {
    int mid;
    ++right;
    while(left < right) {
        mid = (left+right)/2;
        (e < b[mid]) ? right = mid : left = mid + 1;
    }
    return left-1;
}
int main()
{
    int n, m;
    ll sum = 0;
    cin >> n >> m;
    b[0] = 0;
 
    for(int i=1;  i<=n; ++i) {
        scanf("%I64d", &a[i]);
        sum += a[i];
        b[i] = a[i] + b[i-1];
    }
 
    ll now = 0, temp;
    int cnt = 0;
 
    for(int i=1; i<=m; ++i) {
        scanf("%I64d", &temp);
        now += temp;
 
        if(now >= sum) {
            cout << n << endl;
            now = 0;
            continue;
        }
 
        cnt = find(0, n, now);
        if(b[cnt] - now > 0)
            cout << n-cnt+1 << endl;
        else
            cout << n-cnt << endl;
    }
    return 0;
}
