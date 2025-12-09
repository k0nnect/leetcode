void moveZeroes(int* nums, int numsSize) {
    int write = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[write++] = nums[i];
        }
    }

    while (write < numsSize) {
        nums[write++] = 0;
    }
}