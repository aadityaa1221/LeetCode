class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.rbegin(), tasks.rend());

        int ans = 0, j = 0;
        for(int i : processorTime){
            for(int k = 0; k < 4; k++){
                ans = max(ans, i + tasks[j++]);
            }
        }

        return ans;
    }
};