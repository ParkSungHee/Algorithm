#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 50;
bool visit[50];

bool diff(string s1,string s2){
    int diffSize = 0;
    for(int i=0;i<s1.size();i++){
        if(s1[i] != s2[i])
            diffSize++;
    }
    if(diffSize == 1){
        return true;
    }else{
        return false;
    }
}

void dfs(string begin, string target, vector<string> words, int step){
    if(answer <= step)
        return;
    if(begin == target){
        answer = min(answer, step);
        return;
    }

    for(int i=0;i<words.size();i++){
        if(!visit[i] && diff(begin, words[i])){
            visit[i] = true;
            dfs(words[i], target, words,step + 1);
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);

    if(answer == 50)
        return 0;
    return answer;
}