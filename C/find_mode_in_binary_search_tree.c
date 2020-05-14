/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find(int val, int* tmp, int* index){
    for(int i = 0; i < *index; i++){
        if(val == *(tmp+i)) return i;
    }

    *(tmp + *index) = val;
    *index = *index + 1;
    return *index - 1;
}

void dfs(struct TreeNode* root, int* hashmap, int* mx, int* tmp, int* index){ 
    if(!root) return;
    int pos = find(root->val, tmp, index);
    *(hashmap + pos) = *(hashmap + pos) + 1;
    *mx = fmax(*mx, *(hashmap + pos));
    dfs(root->left, hashmap, mx, tmp, index);
    dfs(root->right, hashmap, mx, tmp, index);
}

int* findMode(struct TreeNode* root, int* returnSize){
    int size = 10000;
    int* result = malloc(size * sizeof(int));
      
    if (!root){
        *returnSize = 0;
        return result;
    }
    
    int max_frequency = 0;
    int* hashmap = calloc(size, sizeof(int));
    int* tmp = calloc(size, sizeof(int));
    int index = 0;
    dfs(root, hashmap, &max_frequency, tmp, &index);
    
    int index2 = 0;
    for(int i = 0; i < size; i++)
        if(hashmap[i] == max_frequency)
            result[index2++] = tmp[i];
    
    *returnSize = index2;
    return result;

}
