def solution(n):
    answer = 0
    while n > 0:
        if answer != 0:
            answer = (answer * 3)    
        answer = answer + (n % 3);
        n = n // 3;
    return answer