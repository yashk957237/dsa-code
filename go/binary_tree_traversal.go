package main

import "fmt"

// Node structure
type Node struct {
	data  int
	left  *Node
	right *Node
}

// Insert into binary tree (simple BST insert)
func insert(root *Node, val int) *Node {
	if root == nil {
		return &Node{data: val}
	}
	if val < root.data {
		root.left = insert(root.left, val)
	} else {
		root.right = insert(root.right, val)
	}
	return root
}

// Inorder Traversal
func inorder(root *Node) {
	if root != nil {
		inorder(root.left)
		fmt.Printf("%d ", root.data)
		inorder(root.right)
	}
}

// Preorder Traversal
func preorder(root *Node) {
	if root != nil {
		fmt.Printf("%d ", root.data)
		preorder(root.left)
		preorder(root.right)
	}
}

// Postorder Traversal
func postorder(root *Node) {
	if root != nil {
		postorder(root.left)
		postorder(root.right)
		fmt.Printf("%d ", root.data)
	}
}

func main() {
	var root *Node
	values := []int{10, 5, 20, 3, 7, 15, 25}

	for _, v := range values {
		root = insert(root, v)
	}

	fmt.Print("Inorder: ")
	inorder(root)
	fmt.Println()

	fmt.Print("Preorder: ")
	preorder(root)
	fmt.Println()

	fmt.Print("Postorder: ")
	postorder(root)
	fmt.Println()
}
