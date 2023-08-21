#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
bool visited[100000001];
bool flag=false; //마지막 깊이까지 들어갔는지 여부
int cnt=0; //들어간 깊이

void dfs(string cur, vector<vector<string>> tickets){
    if (cnt==(int)tickets.size()) flag=true; //끝까지 들어갔으면 끝끝
    answer.push_back(cur);
    
    for (unsigned int i=0; i<tickets.size(); i++){ //전체 티켓에 대하여 반복복
        if (!visited[i]&&tickets[i][0]==cur){ //현재 공항이 아직 방문하지 않은 곳이면
            visited[i]=true; //현재 공항은 방문한 것으로 처리하고
            cnt++; //다음 깊이로 들어감
            dfs(tickets[i][1], tickets); //도착지를 출발지로 변경하여 재귀한다다
            
            if(!flag){ //길이 끊겼으면 backtrack으로 뒤로 돌아감
                answer.pop_back();
                visited[i]=false;
            }
        }
    }
}