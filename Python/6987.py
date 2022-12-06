score = [[0,0,0] for _ in range(6)]
from itertools import combinations as comb
flag = 1
def dfs(play):
    global flag

    if flag : return
    if play == 15:
        flag =1
        for i in range(6):
            for j in range(3):
                if score[i][j] :
                    flag =0
                    break
            if not flag:
                break
        return

    i,j = game[play]
    for w,l in [[0,2],[1,1],[2,0]]:
        if score[i][w] >0 and score[j][l]>0:
            score[i][w]-=1
            score[j][l] -=1
            dfs(play+1)
            if flag: return
            score[i][w]+=1
            score[j][l]+=1
game = list(comb(range(6), 2))
for _ in range(4):
    arr = list(map(int, input().split()))
    for i in range(6):
        for j in range(3):
            score[i][j] = arr[i*3+j]
    flag = 0
    dfs(0)
    print(flag, end=" ")
