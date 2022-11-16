import copy
def compare (s1, s2) :
    new_s = copy.copy(s1)
    while len(new_s) != 0 :
        if len(new_s) <= len(s2) and s2[:len(new_s)] == new_s :
            return len(new_s)
        new_s = new_s[1:]
    return 0
def get_array (n, m) :
    arr = []
    while len(arr) != n :
        arr.append([0] * m)
    return arr
import sys
n = int(sys.stdin.readline())
s = sys.stdin.readline().strip()
m = len(s)
d = get_array(m + 1, n + 1)
pref = get_array(m + 1, 26)
string = str()
for i in range(0, m + 1) :
    if i != 0 :
        string += s[i - 1]
    for c in range(0, 26) :
        ch = chr(ord('A') + c)
        string += ch
        pref[i][c] = compare(string, s)
        string = string[:len(string) - 1]
d[0][0] = 1
for i in range(0, n) :
    for j in range(0, m) :
        for c in range(0, 26) :
            d[pref[j][c]][i + 1] += d[j][i]
x = 0
pow = 1
mod = int(1e9 + 7)
for i in range(n, -1, -1) :
    x += d[m][i] * pow
    pow *= 26
    x %= mod
print(x)
