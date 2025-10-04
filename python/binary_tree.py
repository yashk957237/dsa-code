class TreeNode:
    """Node class for binary tree"""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BinaryTree:
    """Binary Tree implementation with common operations"""
    
    def __init__(self):
        self.root = None
    
    def insert(self, val):
        """Insert a new node into the tree"""
        if not self.root:
            self.root = TreeNode(val)
        else:
            self._insert_recursive(self.root, val)
    
    def _insert_recursive(self, node, val):
        """Helper method for insertion"""
        if val < node.val:
            if node.left is None:
                node.left = TreeNode(val)
            else:
                self._insert_recursive(node.left, val)
        else:
            if node.right is None:
                node.right = TreeNode(val)
            else:
                self._insert_recursive(node.right, val)
    
    def search(self, val):
        """Search for a value in the tree"""
        return self._search_recursive(self.root, val)
    
    def _search_recursive(self, node, val):
        """Helper method for search"""
        if not node or node.val == val:
            return node
        
        if val < node.val:
            return self._search_recursive(node.left, val)
        return self._search_recursive(node.right, val)
    
    def inorder_traversal(self):
        """In-order traversal (Left, Root, Right)"""
        result = []
        self._inorder_recursive(self.root, result)
        return result
    
    def _inorder_recursive(self, node, result):
        """Helper method for in-order traversal"""
        if node:
            self._inorder_recursive(node.left, result)
            result.append(node.val)
            self._inorder_recursive(node.right, result)
    
    def preorder_traversal(self):
        """Pre-order traversal (Root, Left, Right)"""
        result = []
        self._preorder_recursive(self.root, result)
        return result
    
    def _preorder_recursive(self, node, result):
        """Helper method for pre-order traversal"""
        if node:
            result.append(node.val)
            self._preorder_recursive(node.left, result)
            self._preorder_recursive(node.right, result)
    
    def postorder_traversal(self):
        """Post-order traversal (Left, Right, Root)"""
        result = []
        self._postorder_recursive(self.root, result)
        return result
    
    def _postorder_recursive(self, node, result):
        """Helper method for post-order traversal"""
        if node:
            self._postorder_recursive(node.left, result)
            self._postorder_recursive(node.right, result)
            result.append(node.val)
    
    def level_order_traversal(self):
        """Level-order traversal (Breadth-First Search)"""
        if not self.root:
            return []
        
        result = []
        queue = [self.root]
        
        while queue:
            node = queue.pop(0)
            result.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        return result
    
    def height(self):
        """Calculate height of the tree"""
        return self._height_recursive(self.root)
    
    def _height_recursive(self, node):
        """Helper method for height calculation"""
        if not node:
            return -1
        
        left_height = self._height_recursive(node.left)
        right_height = self._height_recursive(node.right)
        
        return max(left_height, right_height) + 1
    
    def count_nodes(self):
        """Count total number of nodes"""
        return self._count_recursive(self.root)
    
    def _count_recursive(self, node):
        """Helper method for counting nodes"""
        if not node:
            return 0
        return 1 + self._count_recursive(node.left) + self._count_recursive(node.right)
    
    def find_min(self):
        """Find minimum value in the tree"""
        if not self.root:
            return None
        
        current = self.root
        while current.left:
            current = current.left
        return current.val
    
    def find_max(self):
        """Find maximum value in the tree"""
        if not self.root:
            return None
        
        current = self.root
        while current.right:
            current = current.right
        return current.val

def tree_from_array(arr):
    """Create a binary tree from array representation"""
    if not arr:
        return None
    
    root = TreeNode(arr[0])
    queue = [root]
    i = 1
    
    while queue and i < len(arr):
        node = queue.pop(0)
        
        # Add left child
        if i < len(arr) and arr[i] is not None:
            node.left = TreeNode(arr[i])
            queue.append(node.left)
        i += 1
        
        # Add right child
        if i < len(arr) and arr[i] is not None:
            node.right = TreeNode(arr[i])
            queue.append(node.right)
        i += 1
    
    return root

# Test the binary tree
if __name__ == "__main__":
    # Create a binary search tree
    tree = BinaryTree()
    values = [50, 30, 70, 20, 40, 60, 80]
    
    print("Building binary search tree with values:", values)
    for val in values:
        tree.insert(val)
    
    # Test traversals
    print(f"In-order traversal: {tree.inorder_traversal()}")
    print(f"Pre-order traversal: {tree.preorder_traversal()}")
    print(f"Post-order traversal: {tree.postorder_traversal()}")
    print(f"Level-order traversal: {tree.level_order_traversal()}")
    
    # Test other operations
    print(f"\nTree height: {tree.height()}")
    print(f"Total nodes: {tree.count_nodes()}")
    print(f"Minimum value: {tree.find_min()}")
    print(f"Maximum value: {tree.find_max()}")
    
    # Test search
    search_val = 40
    found = tree.search(search_val)
    print(f"\nSearching for {search_val}: {'Found' if found else 'Not found'}")
    
    search_val = 25
    found = tree.search(search_val)
    print(f"Searching for {search_val}: {'Found' if found else 'Not found'}")