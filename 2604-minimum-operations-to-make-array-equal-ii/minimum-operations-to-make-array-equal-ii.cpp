class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long  neg =0  ; 
        long long  pos =  0 ; 

        if ( k==0){
            for (int i =0 ; i<nums1.size() ; i++){
                if ( nums1[i]!=nums2[i]) return -1 ; 
            }
            return 0 ; 
        }
          for (int i =0 ; i<nums1.size() ; i++){
            if (abs (nums1[i]- nums2[i]) %k!=0) return -1 ; 
            int x  = nums1[i]-nums2[i] ; 
          if (x>0)  neg+= abs( x/k) ; 
          else if ( x!=k)pos+= abs( x/k) ; 
          }

          if ( pos!=neg) return -1 ; 
             return neg ; 
    }
};