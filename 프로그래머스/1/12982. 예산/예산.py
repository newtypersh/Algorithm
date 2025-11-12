def solution(d, budget):
    answer = 0
    d.sort();
    for i in range(len(d)):
        if(d[i] <= budget) :
            budget -= d[i];
            answer = answer + 1;
        
    return answer