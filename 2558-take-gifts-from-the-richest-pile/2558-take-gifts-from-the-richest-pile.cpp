class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;

        for(int i : gifts) pq.push(i);

        while(k--){
            long long i = pq.top();
            pq.pop();
            pq.push((long long)sqrt(i));
        }

        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};