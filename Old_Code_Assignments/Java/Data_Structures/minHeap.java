import java.util.*;

public class minHeap {

	private int[] Heap;
	private int size;
	private int maxsize;

	private static final int FRONT = 1;

	public minHeap(int maxsize) {
		this.maxsize = maxsize;
		this.size = 0;
		Heap = new int[this.maxsize + 1];
		Heap[0] = Integer.MIN_VALUE;
	}

	private int parent(int pos) { //get the parent
		return pos / 2;
	}

	private int leftChild(int pos) { //get the left child
		return (2 * pos);
	}

	private int rightChild(int pos) {   //get the right child
		return (2 * pos) + 1;
	}

	private boolean isLeaf(int pos) {   //verify it exists
		if (pos >= (size / 2) && pos <= size) {
			return true;
		}
		return false;
	}

	private void swap(int fpos, int spos) {   //change positions if necessary
		int tmp;
		tmp = Heap[fpos];
		Heap[fpos] = Heap[spos];
		Heap[spos] = tmp;
	}

	private void minHify(int pos) {  //organize the heap
		if (!isLeaf(pos)) {
			if (Heap[pos] > Heap[leftChild(pos)] || Heap[pos] > Heap[rightChild(pos)]) {
				if (Heap[leftChild(pos)] < Heap[rightChild(pos)]) {
					swap(pos, leftChild(pos));
					minHify(leftChild(pos));
				} else {
					swap(pos, rightChild(pos));
					minHify(rightChild(pos));
				}
			}
		}
	}

	public void insert(int element) {   //add an element
		Heap[++size] = element;
		int current = size;

		while (Heap[current] < Heap[parent(current)]) {
			swap(current, parent(current));
			current = parent(current);
		}
	}

	public void print() {   //print the heap as a heap and as an array
		for (int i = 1; i <= size/2; i++) {
			System.out.println("PARENT : " + Heap[i] + " LEFT CHILD : " + Heap[2 * i] + " RIGHT CHILD :" + Heap[2 * i + 1]);
		}
      System.out.println("\nAs an array:");
      for (int i = 1; i < Heap.length-4; i++) {
			System.out.print(Heap[i] + " ");
		}
	}

	public int remove() {      //remove the smallest value 
		int popped = Heap[FRONT];
		Heap[FRONT] = Heap[size--];
		minHify(FRONT);
		return popped;
	}

	public static void main(String arg[]) {
		minHeap minH = new minHeap(15);  //declare the heap
		minH.insert(11);  //populate the heap
		minH.insert(7);
		minH.insert(2);
		minH.insert(4);
		minH.insert(8);
		minH.insert(9);
		minH.insert(6);
		minH.insert(10);
		minH.insert(5);
      
      System.out.println("The Min value removed is " + minH.remove() + "\n"); //remove the smallest

      minH.insert(1);   //insert elements
      minH.insert(19);
      minH.insert(12);
     
		minH.print();  //print out the heap
	}
}