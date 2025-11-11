from sys import stdin

input = stdin.readline

k = int(input())              # 부등호 개수
sign = list(input().split())  # 부등호 리스트 ['<', '>', '<' ...]
visited = [0]*10              # 0~9 숫자 사용 여부 체크
max_ans = ""                  # 최댓값 저장
min_ans = ""                  # 최솟값 저장

def check(i, j, k):
    if k == "<":
        return i < j
    else:
        return i > j

def solve(depth, s):
    global max_ans, min_ans

    # 종료 조건: k+1개 숫자를 모두 선택했을 때
    if(depth == k+1):
        if len(min_ans) == 0:
            min_ans = s    # 첫 번째 발견 = 최솟값
        else:
            max_ans = s    # 마지막 발견 = 최댓값
        return

    for i in range(10):              # 0~9까지 시도
        if not visited[i]:           # 아직 사용 안 한 숫자면
            # depth==0: 첫 자리는 검사 없이 선택
            # depth>0: 이전 숫자와 부등호 관계 확인
            if(depth == 0 or check(s[-1], str(i), sign[depth-1])):
                visited[i] = True           # 숫자 사용 표시
                solve(depth+1, s+str(i))    # 재귀 호출
                visited[i] = False          # 백트래킹: 사용 해제

solve(0, "")
print(max_ans)
print(min_ans)