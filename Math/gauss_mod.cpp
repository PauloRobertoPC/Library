#define ZERO_SOLUTION 0
#define ONE_SOLUTION 1
#define INFINITY_SOLUTION 2

typedef long long ll;

tuple<ll, ll, ll> extended_euclides(ll a, ll b){
    ll x = 1, y = 0, x1 = 0, y1 = 1;
    while(b){
        ll q = a/b;
        tie(x, x1) = make_tuple(x1, x - q*x1);
        tie(y, y1) = make_tuple(y1, y - q*y1);
        tie(a, b) = make_tuple(b, a - q*b);
    }
    return {a, x, y};
}

tuple<ll, ll, ll, ll> diophantine(ll a, ll b, ll c){
    ll g, x, y; tie(g, x, y) = extended_euclides(abs(a), abs(b));
    if(c%g) return {0, 0, 0, g};
    x = x*(c/g);
    y = y*(c/g);
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return {1, x, y, g};
}

ll modular_inverse(ll a, ll m){
    ll ok, x, y, g; tie(ok, x, y, g) = diophantine(a, -m, 1);
    if(!ok) return -1;
    x = (((x%m)+m)%m);
    return x;
}

ll modDiv(ll a, ll b, ll m){
    return ((a%m)*modular_inverse(b, m))%m;
}

//Linear System mod M
//Ax = B mod M
//a = A...B, ans = x(solution), M = mod
ll gaussMOD(vector<vector<ll>> a, vector<ll> &ans, ll M){
    ll n = (ll) a.size();
    ll m = (ll) a[0].size() - 1;
    vector<ll> where (m, -1);
    for(ll col=0, row=0; col<m && row<n; ++col){
        ll sel = row;
        for(ll i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if(a[sel][col] == 0LL)
            continue;
           
        for(ll i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;
 
        for(ll i=0; i<n; ++i)
            if(i != row){
                ll c = modDiv(a[i][col], a[row][col], M);
                for (ll j=col; j<=m; ++j)
                    a[i][j] = ( a[i][j] - ((a[row][j] * c)%M) + M)%M;
            }
        ++row;
    }
    ans.assign(m, 0);
    for(ll i=0; i<m; ++i)
        if(where[i] != -1)
            ans[i] = modDiv(a[where[i]][m], a[where[i]][i], M);
    for(ll i=0; i<n; ++i){
        ll sum = 0;
        for(ll j=0; j<m; ++j)
            sum = (sum + (ans[j] * a[i][j])%M)%M;
        if(sum != a[i][m])
            return 0;
    }
    bool inf = false;  
    for(ll i=0; i<m; ++i)
        if(where[i] == -1)
            ans[i] = -1, inf = true;
    return 1+inf;
}
