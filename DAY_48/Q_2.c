404. Sum of Left Leaves

def sumOfLeftLeaves(root):
    if not root:
        return 0
    
    total = 0
    if root.left:
        # if left child is a leaf
        if not root.left.left and not root.left.right:
            total += root.left.val
        else:
            total += sumOfLeftLeaves(root.left)
        total += sumOfLeftLeaves(root.right)
    
    return total
