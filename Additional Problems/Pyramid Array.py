import sys
import heapq
import copy
from bisect import bisect
import math
 
 
class SegmentTree:
    vec = []
    n = 0
 
    def update(self, ind, x):
        cur = self.n + ind
        self.vec[cur] = x
        while cur > 1:
            self.vec[cur >> 1] = self.vec[cur] + self.vec[cur ^ 1]
            cur >>= 1
 
    def query(self, left: int, right: int) -> int:
        res = 0
        left += self.n
        right += self.n + 1
        while left < right:
            if left & 1:
                res += self.vec[left]
                left += 1
            if right & 1:
                right -= 1
                res += self.vec[right]
            left >>= 1
            right >>= 1
        return res
 
    def __init__(self, n):
        self.n = (1 << int(math.log2(n))) * 2
        self.vec = [0] * (2 * self.n)
 
 
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
pos = [0] * len(arr)
barr = []
for i in arr:
    barr.append(i)
barr.sort()
for i in range(len(arr)):
    arr[i] = bisect(barr, arr[i]) - 1
for i in range(len(arr)):
    pos[arr[i]] = i
beginning = []
ending = []  # reverse of ending
ans = 0
st = SegmentTree(n)
for i in range(n):
    st.update(i, 1)
for i in range(len(arr)):
    if st.query(0, pos[i]) - st.query(pos[i], n - 1) < 0:
        beginning.append(i)
    else:
        ending.append(i)
    st.update(pos[i], 0)
ending.reverse()
answer = beginning + ending
for i in range(len(answer)):
    answer[i] = pos[answer[i]]
c = 0
for i in range(len(answer)):
    st.update(answer[i], 1)
    c += st.query(answer[i] + 1, n - 1)
print(c)
