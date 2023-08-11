#include <bits/stdc++.h>

using namespace std;

struct BIT{
    int maxn;
    vector<int> bit;

    BIT(int n) : maxn(n+10), bit(n+10, 0){}

    void update(int pos, int val){
        for(; pos < maxn; pos += (pos&(-pos))) bit[pos] += val;
    }

    int get(int pos){
        int sum = 0;
        for(; pos > 0; pos -= (pos&(-pos))) sum += bit[pos];
        return sum;
    }

    //the biggest suffix with sum = sum
    int suffix_sum(int sum){
        sum = get(maxn-1)-sum;
        int l = -1, r = maxn, mid;
        while(l < r-1){
            mid = (l+r)/2;
            if(get(mid) >= sum) r = mid;
            else l = mid;
        }
        return r;
    }
};

int main(){
    int n, k; cin >> n >> k;
    long long ans = 0;
    BIT bit(n);
    map<int, int> last_pos;
    for(int i = 1, num; i <= n; i++){
        cin >> num;
        if(last_pos.count(num)) bit.update(last_pos[num], -1);

        ans += i-bit.suffix_sum(k-1);

        last_pos[num] = i;
        bit.update(i, 1);
    }
    cout << ans << "\n";
    return 0;
}
