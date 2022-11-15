p = [-1] * 300
d = 0
for c in input() :
    r = d
    d = (2 * d - p[ord(c)]) % int(1e9 + 7)
    p[ord(c)] = r
print(d)
