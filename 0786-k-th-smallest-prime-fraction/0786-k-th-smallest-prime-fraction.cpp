class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double low = 0.0, high = 1.0;

        while(true){
            double mid = (low + high) / 2.0;

            int cnt = 0;
            int num = 0, den = 1;
            int j = 1;

            for(int i = 0; i < n - 1; i++){
                while(j < n && arr[i] > mid * arr[j]) j++;
                if(j == n) break;
                cnt += n - j;

                if ((long long)arr[i] * den > (long long)num * arr[j]) {
                    num = arr[i];
                    den = arr[j];
                }
            }

            if (cnt == k)
                return {num, den};
            else if (cnt < k)
                low = mid;
            else
                high = mid;
        }
    }
};