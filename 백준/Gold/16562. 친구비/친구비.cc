/*
#include<iostream>
#include <vector>
using namespace std;
#define MAX 51

int N;
int parent[MAX];
int rank_of_tree[MAX];

void init();
void unionPartyMem(int member1, int member2);
int getRoot(int v);
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int M;
    cin >> N >> M; // 아는 사람의 수 + 파티의 수
    init();
    vector<int> party_members[MAX];
    int num_know_truth;
    int know_truth[MAX];
    cin >> num_know_truth; // 진실을 아는 사람의 수
    for (int i = 0; i < num_know_truth; i++) {
        cin >> know_truth[i]; // 진실을 아는 사람의 번호
    }

    for (int party = 0; party < M; party++) {
        int num_party_mem;
        cin >> num_party_mem;
        for (int i = 0; i < num_party_mem; i++) {
            int party_member;
            cin >> party_member;
            party_members[party].push_back(party_member);
        } // save the people who com to the party
    }

    for (int party = 0; party < M; party++) {
        for (int i = 1; i < party_members[party].size(); i++) {
            unionPartyMem(party_members[party][i - 1], party_members[party][i]);
        } // 동일한 파티에 온 사람을 연결
    }

    int cnt_canLie = 0;
    for (int party = 0; party < M; party++) {
        bool canLie = true;
        for (int i = 0; i < num_know_truth; i++) {
            if (getRoot(party_members[party][0]) == getRoot(know_truth[i])) {
                canLie = false;
                break;
            }
        }
        if (canLie) {
            cnt_canLie++;
        }
    }
    cout << cnt_canLie;
    return 0;
}

// 초기화 함수
void init() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i; // 각 사람에 대한 N개의 집합을 생성한다.
        rank_of_tree[i] = 1; // 트리의 높이를 1로 초기화
    }
}
// 파티 참여자들을 연결하는 함수
void unionPartyMem(int member1, int member2) {
    member1 = getRoot(member1); // member1이 속한 집합의 루트를 반환 받는다.
    member2 = getRoot(member2); // member2이 속한 집합의 루트를 반환 받는다.
    if (member1 == member2) {
        return; // 이미 같은 집합에 속한 경우 종료한다.
    }
    if (rank_of_tree[member1] > rank_of_tree[member2]) {
        swap(member1, member2);
    }
    parent[member1] = member2; // 높이가 낮은 트리가 높은 트리에 병합시킨다.
    if (rank_of_tree[member1] == rank_of_tree[member2]) {
        rank_of_tree[member2]++;
    } // 트리의 높이가 같을 경우 병합 후 부모에 위치한 트리의 높이를 1 증가시킨다.
}
// 루트를 반환하는 함수
int getRoot(int person) {
    if (person == parent[person]) { // person이 루트라면 그대로 반환한다.
        return person;
    }
    else { // 아니라면 루트를 재귀적으로 찾아 반환한다.
        return parent[person] = getRoot(parent[person]);
    } // person의 부모를 재귀적으로 찾은 루트로 바뀌주면서 경로를 압축한다.
}
*/

#include <iostream>
using namespace std;
#define MAX 10001

int n;
int friendCost[MAX];
int parent[MAX];

int getRoot(int student) {
    if (student == parent[student]) {
        return student;
    }
    else {
        return parent[student] = getRoot(parent[student]);
    }
}

void unionFriend(int f1, int f2) {
    f1 = getRoot(f1);
    f2 = getRoot(f2);
    if (f1 == f2) {
        return;
    }
    if (friendCost[f1] > friendCost[f2]) {
        swap(f1, f2);
    }
    parent[f2] = f1;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool visited[MAX] = { false };
    int m, k, v, w;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> friendCost[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v >> w;
        unionFriend(v, w);
    }
    int result = 0;
    for (int student = 1; student <= n; student++) {
        int root = getRoot(student);
        if (!visited[root]) {
            result += friendCost[root];
            visited[root] = true;
        }
    }

    if (result > k) {
        cout << "Oh no";
    }
    else {
        cout << result;
    }
    return 0;
}