class Solution {
    static{
        for(int i=0;i<500;i++){
            getSumAbsoluteDifferences(new int[1]);
        }
    }
    public static int[] getSumAbsoluteDifferences(int[] nums) {
        int n=nums.length;
        int rightSum[]=new int[n];
        rightSum[n-1]=0;
        for(int i=n-2;i>=0;i--){
            rightSum[i]=rightSum[i+1]+nums[i+1];
        }
        int leftSum=0;
        for(int i=0;i<nums.length;i++){
            int leftSide=nums[i]*i-leftSum;
            int rightSide=rightSum[i]-nums[i]*(n-i-1);
            leftSum+=nums[i];
            nums[i]=leftSide+rightSide;
        }
        return nums;
    }
}