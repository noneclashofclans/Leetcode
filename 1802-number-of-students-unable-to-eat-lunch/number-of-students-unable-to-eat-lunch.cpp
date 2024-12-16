class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        queue<int> q;
        for (auto i : students){
            q.push(i);
        }
        stack<int> sandwichStack;
         for(int i=n-1;i>=0;i--) 
            sandwichStack.push(sandwiches[i]);

            int cnt = 0;
            while (!q.empty() && cnt<q.size()){
                if (sandwichStack.top()==q.front()){
                    sandwichStack.pop();
                    q.pop();
                    cnt = 0;
                }else{
                    q.push(q.front());
                    q.pop();
                    cnt++;
                }
            }

            return q.size();
    }
};