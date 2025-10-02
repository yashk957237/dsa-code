# Define the TreeNode class
class TreeNode
  attr_accessor :val, :left, :right

  def initialize(val)
    @val = val
    @left = nil
    @right = nil
  end
end

# In-order traversal: Left → Root → Right
def inorder(node)
  return [] if node.nil?
  inorder(node.left) + [node.val] + inorder(node.right)
end

# Pre-order traversal: Root → Left → Right
def preorder(node)
  return [] if node.nil?
  [node.val] + preorder(node.left) + preorder(node.right)
end

# Post-order traversal: Left → Right → Root
def postorder(node)
  return [] if node.nil?
  postorder(node.left) + postorder(node.right) + [node.val]
end

# Build a sample binary tree:
#       1
#      / \
#     2   3
#    / \
#   4   5

root = TreeNode.new(1)
root.left = TreeNode.new(2)
root.right = TreeNode.new(3)
root.left.left = TreeNode.new(4)
root.left.right = TreeNode.new(5)

# Run traversals
puts "In-order traversal: #{inorder(root).inspect}"    # [4, 2, 5, 1, 3]
puts "Pre-order traversal: #{preorder(root).inspect}"  # [1, 2, 4, 5, 3]
puts "Post-order traversal: #{postorder(root).inspect}"# [4, 5, 2, 3, 1]