class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if(word == endWord) return step;

            for(int i = 0; i < word.size(); i++){
                char og = word[i];

                for(char k = 'a'; k <= 'z'; k++){
                    word[i] = k;

                    if(st.find(word) != st.end()){
                        q.push({word, step + 1});
                        st.erase(word);
                    }
                }

                word[i] = og;
            }
        }

        return 0;
    }
};