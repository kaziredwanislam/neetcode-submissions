# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        in_order_traversal=[]
        def inOrderTraversal(node):
            nonlocal in_order_traversal
            if node.left:
                inOrderTraversal(node.left)
            
            in_order_traversal.append(node.val)

            if node.right:
                inOrderTraversal(node.right)

        inOrderTraversal(root)
        return in_order_traversal[k-1]