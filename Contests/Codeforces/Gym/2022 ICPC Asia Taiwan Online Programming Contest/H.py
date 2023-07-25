def binpow(b, e):
    ans = 1
    while e:
        if(e&1):
            ans *= b
        b *= b
        e >>= 1 
    return ans

a = int(input())

l = 0
r = 10000000
while l < r-1:
    mid = (l+r)//2
    if binpow(6, mid) > a:
        r = mid
    else:
        l = mid

print(r)
