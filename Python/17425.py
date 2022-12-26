TT =1000001
T= int(input())

s = [1 for _ in range(TT)]
hap = [0 for _ in range(TT) ]

ans =[]
for i in range(2, TT):
    tem = 1
    while i*tem < TT:
        s[i*tem] += i
        tem+=1
for i in range(1, TT):
    hap[i] = s[i]+hap[i-1]

for tc in range(T):
    a=int(input())
    ans.append(hap[a])

print('\n'.join(map(str, ans)))