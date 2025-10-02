package main

import "fmt"

// Node structure
type Node struct {
	value int
	left  *Node
	right *Node
}

// Pre-order traversal: root -> left -> right
func preOrder(node *Node) {
	if node != nil {
		fmt.Print(node.value, " ")
		preOrder(node.left)
		preOrder(node.right)
	}
}

// In-order traversal: left -> root -> right
func inOrder(node *Node) {
	if node != nil {
		inOrder(node.left)
		fmt.Print(node.value, " ")
		inOrder(node.right)
	}
}

// Post-order traversal: left -> right -> root
func postOrder(node *Node) {
	if node != nil {
		postOrder(node.left)
		postOrder(node.right)
		fmt.Print(node.value, " ")
	}
}

// Level-order traversal (BFS)
func levelOrder(root *Node) {
	if root == nil {
		return
	}

	queue := []*Node{root}

	for len(queue) > 0 {
		current := queue[0]
		queue = queue[1:]
		fmt.Print(current.value, " ")

		if current.left != nil {
			queue = append(queue, current.left)
		}
		if current.right != nil {
			queue = append(queue, current.right)
		}
	}
}

func main() {
	// Create a simple binary tree
	root := &Node{value: 1}
	root.left = &Node{value: 2}
	root.right = &Node{value: 3}
	root.left.left = &Node{value: 4}
	root.left.right = &Node{value: 5}

	fmt.Print("Pre-order: ")
	preOrder(root)
	fmt.Println()

	fmt.Print("In-order: ")
	inOrder(root)
	fmt.Println()

	fmt.Print("Post-order: ")
	postOrder(root)
	fmt.Println()

	fmt.Print("Level-order: ")
	levelOrder(root)
	fmt.Println()
}
