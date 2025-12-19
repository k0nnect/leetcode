class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });
        
        unordered_set<int> knows = {0, firstPerson};
        int i = 0;
        int m = meetings.size();
        
        while (i < m) {
            int t = meetings[i][2];
            
            unordered_map<int, vector<int>> graph;
            int j = i;
            while (j < m && meetings[j][2] == t) {
                int a = meetings[j][0], b = meetings[j][1];
                graph[a].push_back(b);
                graph[b].push_back(a);
                j++;
            }
            
            unordered_set<int> visited;
            for (auto &[person, _] : graph) {
                if (visited.count(person)) continue;
                
                vector<int> component;
                bool hasSecret = false;
                queue<int> q;
                q.push(person);
                visited.insert(person);
                
                while (!q.empty()) {
                    int curr = q.front(); q.pop();
                    component.push_back(curr);
                    if (knows.count(curr)) hasSecret = true;
                    for (int nei : graph[curr]) {
                        if (!visited.count(nei)) {
                            visited.insert(nei);
                            q.push(nei);
                        }
                    }
                }
                
                if (hasSecret) {
                    for (int p : component) knows.insert(p);
                }
            }
            
            i = j;
        }
        
        return vector<int>(knows.begin(), knows.end());
    }
};