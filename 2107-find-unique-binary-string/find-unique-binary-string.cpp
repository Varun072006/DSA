class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        vector<int> x(n);
        for(int i=0;i<n;i++){
            int m=nums[i].length(),y=0,z=1;
            while(m--){
                if(nums[i][m]=='1') y+=z;
                z*=2;
            }
            x[i]=y;
        }
        sort(x.begin(),x.end());
        int ans=-1;
        for(int i=0;i<n;i++){
            if(x[i]!=i) {
                ans=i;
                break;
            }
        }
        if(ans==-1) ans=n;
        string sol="";
        while(ans!=0){
            if(ans%2==1) sol="1"+sol;
            else sol="0"+sol;
            ans/=2;
        }
        while(sol.length()<nums[0].length()){
            sol="0"+sol;
        }
        return sol;
    }
};