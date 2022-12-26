MAX = 1000000

dp = [1] * (MAX+1)
s = [0] * (MAX+1)

# 입력 받은 수 N은 곧 N의 약수들의 배수라는 것을 이용해
# dp 배열을 채운다. dp 배열에는 각 자연수의 약수의 합이 저장된다.
for i in range(2,MAX+1):
    j = 1
    while i*j <= MAX:
        dp[i*j] += i
        j+=1

# dp 배열엔 약수의 합들이 저장되고 s 배열에는 누적합을 저장
for i in range(1,MAX+1):
    s[i] = s[i-1] + dp[i]

n = int(input())
ans = []

for _ in range(n):
    tmp = int(input())
    ans.append(s[tmp])

print('\n'.join(map(str, ans)))