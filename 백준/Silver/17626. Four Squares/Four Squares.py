import math
import sys

n = int(sys.stdin.readline())
dp = [0] + [int(1e9)] * n

squares = [i*i for i in range(1, int(n**0.5)+1)]
for i in range(1, n + 1):
    for square in squares:
        if i < square:
            break;
        dp[i] = min(dp[i], dp[i - square] + 1)

print(dp[n])
