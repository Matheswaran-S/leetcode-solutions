# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        def build(left: int, right: int) -> Optional[TreeNode]:
            if left > right:
                return None
            
            # Find max value and its index in [left, right]
            max_val = max(nums[i] for i in range(left, right + 1))
            max_idx = nums.index(max_val, left, right + 1)
            
            root = TreeNode(max_val)
            root.left = build(left, max_idx - 1)
            root.right = build(max_idx + 1, right)
            
            return root
        
        return build(0, len(nums) - 1)
