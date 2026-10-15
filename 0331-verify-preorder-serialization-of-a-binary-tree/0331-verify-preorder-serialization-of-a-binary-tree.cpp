class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slot = 1;

        for(int i = 0; i < preorder.size(); i++){
            if(preorder[i] == ',') continue;

            slot--;
            if(slot < 0) return false;
            if(preorder[i] != '#') {
                while (i < preorder.size() && preorder[i] != ',') {
                    i++;
                }
                slot += 2;
            }
        }

        return slot == 0;
    }
};