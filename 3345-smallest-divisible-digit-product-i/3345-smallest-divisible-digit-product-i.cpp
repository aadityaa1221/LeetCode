class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int x = n;
            int mul = 1;

            while(x > 0){
                mul *= x % 10;
                x /= 10;
            }

            if(mul % t == 0) return n;
            n++;
        }
    }
};