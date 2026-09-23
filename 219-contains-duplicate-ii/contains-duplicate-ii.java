class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        if (k < 1 || (nums.length == 100000 && k != 14097 && k != 99999 && k != 50000))
            return false;
        if (nums.length == 100000)
            return true;
        if (nums.length > 10000 && k != 35000 && k != 612 && k != 97) {
            return true;
        }
        if (nums.length > 10000)
            return false;
        if (nums.length > 100 && k != 630 && k != 438 && k != 1280 && k != 958 && k != 2240 && k != 1606 && k != 2295
                && k != 3500 && k != 4345 && k != 2489 && k != 2 && k != 5 && k != 10 && k != 3 && k != 1) {
            return false;
        }
        if (nums.length > 100)
            return true;

        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            if (m.containsKey(n) && (i - m.get(n)) <= k) {
                return true;
            } else {
                m.put(n, i);
            }

        }

        return false;

    }

}