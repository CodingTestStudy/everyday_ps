#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
vector<pair<int, int>>Key;
vector<pair<int, int>>Lock;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n,m;
unordered_set<string>visit;
void rotate(vector<pair<int, int>>&a) {
    for (int i = 0; i < a.size(); i++) {// 시계방향 90도회전
        auto [x, y] = a[i];
        int x_temp = y;
        int y_temp = m - 1 - x;
        a[i] = { x_temp,y_temp };
    }
}
bool search(vector<pair<int, int>>& x) {// 자물쇠랑 키랑 비교
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == Lock[i])continue;
        return false;
    }
    return true;
}
bool bfs(vector<pair<int, int>>& a) {
    queue <vector<pair<int, int>>>q;
    q.push(a);
    while (!q.empty()) {
        vector<pair<int,int>>x = q.front();
        q.pop();
        if (x.size() < Lock.size())continue;// 자물쇠의 개수보다 키의 개수가 작아지면 stop
        if (x.size()==Lock.size()&&search(x)) {// 자물쇠랑 키의 개수가 같을떄 검사 
            return true;
            break;
        }
        for (int i = 0; i < 4; i++) {// bfs 4방향 탐색
            vector<pair<int, int>>T;
            for (int j = 0; j < x.size(); j++) {// 현재의 키값들을 전부 방향대로 한칸씩옮겨본다
                int nx = x[j].first + dx[i];
                int ny = x[j].second + dy[i];
                if (nx >= n || ny >= n || nx < 0 || ny < 0)continue;//범위를 벗어나면 T에넣지않는다.
                T.push_back({ nx,ny });
            }
            sort(T.begin(), T.end());// T를 정렬
            string S = "";
            for (auto [a, b] : T) {// visit 체크  string에 다때려박고 set에 넣는다 
                S += a;
                S += b;
            }
            if (visit.count(S))continue;// 이미 방문했다면 pass
            visit.insert(S);
            q.push(T);// 정렬된 vector T를 넣는다 
        }
    }
    return false;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    n = lock.size();
    m = key.size();
    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            if (key[i][j])Key.push_back({ i,j });// 키 원소 
        }
    }
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            if (!lock[i][j])Lock.push_back({ i,j }); // 자물쇠 원소

        }
    }
    vector<pair<int, int>>temp = Key;// temp를 90씩 회전한다
    sort(Lock.begin(), Lock.end());
    for (int i = 0; i < 4; i++) {
        if(i>0)rotate(temp);//0->90->180->270 회전
        vector<pair<int, int>>temp1 = temp;
        if (bfs(temp1)) {
            answer = true;
            break;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>>key = { {0,0,0},{1,0,0},{0,1,1} };
    vector<vector<int>>lock = { {1,1,1},{1,1,0},{1,0,1} };
    if(solution(key, lock))cout<<"true";
    else cout<<"false";
}