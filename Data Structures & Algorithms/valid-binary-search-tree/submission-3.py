# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        in_order_traversal=[]
        def inOrderTraversal(node):
            nonlocal in_order_traversal
            if node.left:
                inOrderTraversal(node.left)
            in_order_traversal.append(node.val)
            #print(node.val)
            if  node.right:
                inOrderTraversal(node.right)
            
        def isSorted(li):
            for i in range(1,len(li)):
                if li[i]<=li[i-1]:return False
            return True
        
        inOrderTraversal(root)
        #print(in_order_traversal)
        return isSorted(in_order_traversal)