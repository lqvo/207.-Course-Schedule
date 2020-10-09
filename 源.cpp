#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>input(numCourses); 
        vector<vector<int>> edges(numCourses);
        for (auto i : prerequisites) { 
            input[i[0]]++; 
            edges[i[1]].push_back(i[0]);
        }
        queue<int>q;
        int count=0;
        for (int i=0;i<input.size();i++)
            if (input[i]==0)q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            count++;
            if (edges[v].empty())continue;
            for (int i = 0; i < edges[v].size();i++) {
                input[edges[v][i]]--;
                if (input[edges[v][i]] == 0)q.push(edges[v][i]);
            }
        }
        return (count == numCourses);
    }
};