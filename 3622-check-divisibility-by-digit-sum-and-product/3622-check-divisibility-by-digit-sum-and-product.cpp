class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int x = n;

        while(x > 0){
            int r = x % 10;
            x /= 10;
            sum += r;
            prod *= r;
        }

        sum += prod;
        return n % sum == 0;
    }
};