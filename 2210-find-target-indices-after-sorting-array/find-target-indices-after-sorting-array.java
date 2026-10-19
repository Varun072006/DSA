class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        int len =  nums.length;
        Arrays.sort(nums);
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i < len; i++){
            if(nums[i] == target){
                res.add(i);
            }
        }
        return res;
    }
}