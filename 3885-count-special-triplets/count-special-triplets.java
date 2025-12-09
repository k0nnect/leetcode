class Solution {
    public int specialTriplets(int[] nums) {
        int MOD = 1_000_000_007;
        int max = 200000;
        long[] left = new long[max + 1];
        long[] right = new long[max + 1];
        for (int x : nums) right[x]++;

        long res = 0;
        for (int j = 0; j < nums.length; j++) {
            right[nums[j]]--;
            int target = nums[j] * 2;
            if (target <= max) {
                res = (res + left[target] * right[target]) % MOD;
            }
            left[nums[j]]++;
        }
        return (int) res;
    }
}