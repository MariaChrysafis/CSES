import sys
n, q = map(int, sys.stdin.readline().split())
m = [list(map(int,sys.stdin.readline().split())) for i in range(n)]
mx = 1000000 + 3
d = [[mx - 1 for _ in range(mx)] for _ in range(20)]
for i in range(n) :
    d[0][m[i][0]] = min(d[0][m[i][0]], m[i][1])
for i in range(mx - 2, -1, -1) :
    d[0][i] = min(d[0][i], d[0][i + 1])
for j in range(1, 20):
    for i in range(mx) :
        d[j][i] = d[j - 1][d[j - 1][i]]
pr = []
for i in range(q) :
    l, r = map(int, sys.stdin.readline().split())
    cur = l
    ans = 0
    for j in range(19, -1, -1) :
        if d[j][cur] <= r :
            cur = d[j][cur]
            ans += (1 << j)
    pr.append(ans)
print("\n".join(str(s) for s in pr))
