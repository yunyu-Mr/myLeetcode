/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> eeTable;
        for (auto ee : employees) {
            eeTable[ee->id] = ee;
        }
        
        int importance = 0;
        
        // BFS
        queue<Employee*> q;
        q.push(eeTable[id]);
        while (!q.empty()) {
            Employee *pee = q.front();
            q.pop();
            
            importance += pee->importance;
            
            for (int subordinate : pee->subordinates)
                q.push(eeTable[subordinate]);
        }
        return importance;
    }
};