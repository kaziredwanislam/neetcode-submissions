# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        height=0
        def calculateHeight(node,curheight):
            nonlocal height
            if node != None:
                if curheight+1 > height :
                    height=curheight+1
            
                if node.left !=None:
                    calculateHeight(node.left,curheight+1)
                
                if node.right != None:
                    calculateHeight(node.right,curheight+1)
                
        
        calculateHeight(root,0)
        return height