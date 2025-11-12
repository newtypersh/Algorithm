def solution(sizes):    
    transverse = 0
    length = 0
    
    for i in range(len(sizes)):
        if sizes[i][0] > sizes[i][1]:
            transverse = max(transverse, sizes[i][0])
            length = max(length, sizes[i][1])
        else:
            transverse = max(transverse, sizes[i][1])
            length = max(length, sizes[i][0])
    
    return transverse * length