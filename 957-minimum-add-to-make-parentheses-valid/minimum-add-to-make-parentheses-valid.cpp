class Solution {
public:
    int minAddToMakeValid(string s) {
        int oB = 0;
        int min = 0;

        for(char c : s){
            if(c == '('){
                oB++;
            } else{
                oB > 0 ? oB-- : min++;
            }
        }
        return min + oB;
    }
};