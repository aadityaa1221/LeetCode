class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(char c : s){
            if(c == ')'){
                int i = st.top();
                st.pop();

                i = max(i * 2, 1);
                st.top() += i;
            }else{
                st.push(0);
            }
        }
        return st.top();
    }
};