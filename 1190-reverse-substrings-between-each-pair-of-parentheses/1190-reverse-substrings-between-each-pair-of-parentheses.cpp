class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");

        for (char ch : s) {
            if (ch == '(') {
                st.push("");
            }
            else if (ch == ')') {
                string curr = st.top();
                st.pop();

                reverse(curr.begin(), curr.end());

                st.top() += curr;
            }
            else {
                st.top() += ch;
            }
        }

        return st.top();
    }
};