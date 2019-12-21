import java.util.*;

public class BinarySearchTree 
{
	public static  Node root;
	public BinarySearchTree()
   {
		this.root = null;
	}
	
	public boolean find(int id)//checks if a node exists
   {
		Node current = root;
		while(current != null)
      {
			if(current.data == id)
				return true;
			else if(current.data > id)
				current = current.left;
			else
				current = current.right;
		}
		return false;
	}
   
	public boolean delete(int id) //deletes a specified node
   {
		Node parent = root;
		Node current = root;
		boolean isLeftChild = false;
		while(current.data != id)
      {
			parent = current;
			if(current.data > id)
         {
				isLeftChild = true;
				current = current.left;
			}
         else
         {
				isLeftChild = false;
				current = current.right;
			}
			if(current == null)
				return false;
		}
		
		//Case 1: if node to be deleted has no children
		if(current.left==null && current.right==null)
      {
			if(current == root)
				root = null;
			if(isLeftChild == true)
				parent.left = null;
			else
				parent.right = null;
		}
		
      //Case 2 : if node to be deleted has only one child
		else if(current.right == null)
      {
			if(current == root)
				root = current.left;
			else if(isLeftChild)
				parent.left = current.left;
			else
				parent.right = current.left;
		}
		else if(current.left == null)
      {
			if(current == root)
				root = current.right;
			else if(isLeftChild)
				parent.left = current.right;
			else
				parent.right = current.right;
		}
      else if((current.left != null) && (current.right != null))
      {
			//found the minimum element in the right sub tree
			Node successor	 = getSuccessor(current);
			if(current == root)
				root = successor;
			else if(isLeftChild)
				parent.left = successor;
			else
				parent.right = successor;
			successor.left = current.left;
		}		
		return true;		
	}
	
	public Node getSuccessor(Node deleleNode) //find the previous
   {
		Node successsor = null;
		Node successsorParent = null;
		Node current = deleleNode.right;
		while(current != null){
			successsorParent = successsor;
			successsor = current;
			current = current.left;
		}
		
      //check if successor has the right child, it cannot have left child
		// if it does have the right child, add it to the left of successorParent
		if(successsor != deleleNode.right)
      {
			successsorParent.left = successsor.right;
			successsor.right = deleleNode.right;
		}
		return successsor;
	}
   
	public void insert(int id) //add a node
   {
		Node newNode = new Node(id);
		if(root == null){
			root = newNode;
			return;
		}
		Node current = root;
		Node parent = null;
		while(true)
      {
			parent = current;
			if(id < current.data)
         {				
				current = current.left;
				if(current == null)
            {
					parent.left = newNode;
					return;
				}
			}
         else
         {
				current = current.right;
				if(current==null)
            {
					parent.right = newNode;
					return;
				}
			}
		}
	}
	
   public void display(Node root)   //print out the tree
   {
		if(root != null)
      {
			display(root.left);
			System.out.print(" " + root.data);
			display(root.right);
		}
	}
	public static void main(String arg[])
   {                                                          //               64
		BinarySearchTree b = new BinarySearchTree();            //       /               \
		b.insert(64); b.insert(60); b.insert(70); b.insert(50); //      60               70                
      b.insert(55); b.insert(80); b.insert(90); b.insert(40); //   /      \         /      \ 
		b.insert(45); b.insert(54); b.insert(58); b.insert(84); //  50      55       80      90 
		                                                        // /  \    /  \     /  
                                                              //40  45  54  58   84  
      System.out.println("Original Tree: "); //tree where 64 is the root and lesser values
		b.display(b.root);		               //are on the right and greater on the left
		
      System.out.println("\n\nCheck whether Node with value of 70 exists: " + b.find(70));   //finds a node
		
      System.out.println("\nDelete Node(84): " + b.delete(84));   //deletes a node
		b.display(root);
      
      System.out.println("\n\nAll values of the tree with the min on the left and max on the right: ");
	   b.display(root);           //shows nodes
   }
}

class Node
{
	int data;
	Node left;
	Node right;	
	public Node(int data)
   {
		this.data = data;
		left = null;
		right = null;
	}
}