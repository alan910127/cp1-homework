n = int(input())

for _ in range(n):
    line = list(map(int, input().split()))
    a, b = line[0:-2:2], line[1:-2:2]
    c, d = line[-2],     line[-1]
    
    line = list(map(int, input().split()))
    x, y = line[0::2], line[1::2]

    dp = [[None for i in range(100)] for j in range(100)]

    def f(x, y):
        if x <= 0 or y <= 0: return d
        if dp[x][y] != None: return dp[x][y]

        ans = c
        for i, j in zip(a, b):
            ans += f(x - i, y - j)
        
        dp[x][y] = ans
        return dp[x][y]

    for i, j in zip(x, y):
        print(f(i, j))
        
    print()