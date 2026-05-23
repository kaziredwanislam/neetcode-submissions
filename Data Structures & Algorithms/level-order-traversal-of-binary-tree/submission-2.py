# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        ansnodes=[]
        nodes=[]
        ans=[]
        nodes.append(root)
        while len(nodes)>0:
            ansnodes.append(nodes)
            cur_nodes=[]
            for node in nodes:
                if node.left is not None:
                    cur_nodes.append(node.left)
                if node.right is not None:
                    cur_nodes.append(node.right)
            nodes=cur_nodes
        
        for nodes in ansnodes:
            row=[]
            for node in nodes:
                row.append(node.val)
            ans.append(row)
        return ans