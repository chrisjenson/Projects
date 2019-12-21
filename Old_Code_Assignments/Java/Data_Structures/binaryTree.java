import java.util.*;

class Node 
{ 
    char key; 
    Node left, right; 
  
    public Node(char item) 
    { 
        key = item; 
        left = right = null; 
    } 
}

public class binTree
{ 
    Node root; //root of the tree
  
    binTree() 
    { 
        root = null; 
    } 
  
    void postOrder(Node node)  //postorder traversal
    { 
        if (node == null) 
            return; 
  
        postOrder(node.left); //start on the left 
        postOrder(node.right); //then the right
        System.out.print(node.key + " "); //lastly the node
    } 
  
    void inOrder(Node node) //inorder traversal
    { 
        if (node == null) 
            return; 
            
        inOrder(node.left); //start on the left
        System.out.print(node.key + " "); //then the node
        inOrder(node.right); //lastly the right
    } 
  
    void preOrder(Node node) //preorder traversal
    { 
        if (node == null) 
            return; 
  
        /* first print data of node */
        System.out.print(node.key + " "); //first the node
        preOrder(node.left); //then the left
        preOrder(node.right); //lastly the right
    } 
  
    // Wrappers for recursive functions 
    void postOrder()  {     postOrder(root);  } 
    void inOrder()    {     inOrder(root);   } 
    void preOrder()   {     preOrder(root);  } 
  
    public static void main(String[] args) //main
    { 
        binTree tree = new binTree(); 
        tree.root = new Node('F'); 
        tree.root.left = new Node('B'); 
        tree.root.right = new Node('G'); 
        tree.root.left.left = new Node('A'); 
        tree.root.left.right = new Node('D'); 
        tree.root.right.right = new Node('I');
        tree.root.right.right.left = new Node('H');
        tree.root.left.right.left = new Node('C');
        tree.root.left.right.right = new Node('E');
  
        System.out.println("Inorder traversal of binary tree is "); 
        tree.inOrder();  
  
        System.out.println("\nPreorder traversal of binary tree is "); 
        tree.preOrder();  
  
        System.out.println("\nPostorder traversal of binary tree is "); 
        tree.postOrder(); 
    } 
} 