z = int(1e9 + 7)
 
 
def b (x, y):
    r = x
    u = 1
    while y != 0 :
        if y & 1 :
            u *= r
            u %= z
        r *= r
        r %= z
        y >>= 1
    return u
 
 
def c (x, y) :
    return (f[x] * b((f[y] * f[x - y]) % z, z - 2)) % z
 
 
def p (x, y) :
    return c(x + y - 2, x - 1)
 
f = [1]
n, m = map(int,input().split())
while len(f) != 2 * n :
    f.append((f[-1] * len(f)) % z)
v = []
for i in range(m) :
    v.append(list(map(int, input().split())))
v.sort(key = lambda x: x[0] + x[1])
v.append([n, n])
a = [0] * len(v)
for i in range(len(v)) :
    a[i] = p(v[i][0], v[i][1])
    for j in range(i) :
        if v[j][0] <= v[i][0] and v[j][1] <= v[i][1] :
            d = a[j]
            d *= p(v[i][0] - v[j][0] + 1, v[i][1] - v[j][1] + 1)
            a[i] -= d
            a[i] %= z
print(a[-1])
