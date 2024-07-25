a = input()
n = 0
ans = 0
for i in a:
    if i == ',':
        ans += n
        n=0
    else:
        n *=10
        n += int(i)
ans += n
print(ans)