/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MOD 1000000007

long long all_sums[50000];
int count = 0;

long long get_sums(struct TreeNode* root) {
    if (root == NULL) return 0;
    
    long long current_sum = root->val + get_sums(root->left) + get_sums(root->right);
    all_sums[count++] = current_sum;
    return current_sum;
}

int maxProduct(struct TreeNode* root) {
    count = 0;
    long long totalSum = get_sums(root);
    long long max_prod = 0;
    
    for (int i = 0; i < count; i++) {
        long long current_prod = all_sums[i] * (totalSum - all_sums[i]);
        if (current_prod > max_prod) {
            max_prod = current_prod;
        }
    }
    
    return (int)(max_prod % MOD);
}