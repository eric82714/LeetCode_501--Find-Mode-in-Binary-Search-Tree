# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root: TreeNode) -> List[int]:        
        def dfs(root):
            if root is None: return []

            s = [root.val]
            if root.left:
                s += dfs(root.left)
            if root.right:
                s += dfs(root.right)
                
            return s
        
        elements = dfs(root)
        max_frequency = 0

        hashmap = {}
        for val in elements:
            if val in hashmap:
                hashmap[val] += 1
            else:
                hashmap[val] = 1
            max_frequency = max(max_frequency, hashmap[val])

        return [k for k, v in hashmap.items() if v == max_frequency]
