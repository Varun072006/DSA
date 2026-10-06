class Solution {
    public int minAddToMakeValid(String s) {
        int oB = 0;
        int min = 0;

        for(char c : s.toCharArray()){
            if(c == '('){
                oB++;
            } else {
                if(oB > 0){
                    oB--;
                } else{
                    min++;
                }
            }
        }
        return min + oB;
    }
}