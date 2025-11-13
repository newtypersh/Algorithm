import sys, itertools, collections
input = sys.stdin.readline

# same 집합이 연결되어 있는지 확인
# 리턴값: 해당 집합의 인구 합, 연결된 구역 수
def bfs(same):
    start = same[0]
    q = collections.deque([start]) # BFS 큐로 사용할 deque 초기화(시작점 넣음)
    visited = set([start]) # 이미 방문한 구역 집합(중복방지)
    _sum = 0 # 연결된 구역의 인구 수 합산용 변수
    while q:
        v = q.popleft()
        _sum += pp[v]
        for u in g[v]:
            if u not in visited and u in same:
                q.append(u)
                visited.add(u)
    return _sum, len(visited)

n = int(sys.stdin.readline().strip()) # 구역 
pp = [int(x) for x in sys.stdin.readline().split()] # 각 구역 인구 리스트
g = collections.defaultdict(list) # 구역 연결 정보 (그래프)
result = float('inf')

for i in range(n):
    _input = [int(x) for x in sys.stdin.readline().split()]
    for j in range(1, _input[0]+1):
        g[i].append(_input[j]-1)

# 구역을 두 개의 그룹으로 나누는 모든 경우의 수를 생성
# 각 그룹이 실제로 연결되어 있는지 확인
# 연결된 경우라면 인구 차이의 최소값을 갱신
for i in range(1, n//2 + 1):
    # combis에는 n개 중에서 i개를 골라 만든 모든 부분집합이 담김
    combis = list(itertools.combinations(range(n), i))
    for combi in combis:
        sum1, v1 = bfs(combi)
        sum2, v2 = bfs([i for i in range(n) if i not in combi])
        if v1 + v2 == n:
            result = min(result, abs(sum1 - sum2))

# 결과 출력
if result != float('inf'):
    print(result)
else:
    print(-1)



