from itertools import permutations

n = int(input())
arr = [i+1 for i in range(n)]

for perm in permutations(arr, n):
    print(*perm)