class Solution {
    public int minMoves(int[] nums) {
        int o = Arrays.stream(nums).min().getAsInt(), moves = 0;
        for (int x : nums) moves += x - o;
        return moves;
    }
}