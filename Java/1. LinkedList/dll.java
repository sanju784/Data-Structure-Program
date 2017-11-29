//Doubly Linked List
class Node {
	int data;
	Node prev;
	Node next;
	
	public Node(int n) {
	  data = n;
	  prev = null;
	  next = null;
	}
}

class DLL {
	static Node head = null;
	
	//Insert at First
	static void insertFirst(int n) {
		Node newN = new Node(n);
		if(head == null)
			head = newN;
		else {
			newN.next = head;
			head.prev = newN;
			head = newN;
		}
	}
	
	//Print List
	static void printList() {
		Node temp = head;
		while(temp != null) {
			System.out.print(temp.data + "  ");
			temp = temp.next;
		}
		System.out.println();
	}
	
	//Insert last
	static void insertLast(int n) {
		Node newN = new Node(n);
		Node temp = head;
		while(temp.next != null) {
			temp = temp.next;
		}
		newN.prev = temp;
		temp.next = newN;
	}
	
	//Insert at given position
	static void insertPos(int n, int p) {
		Node temp = head;
		int count = 1;
		while (temp != null && count < p) {
			temp = temp.next;
			count++;
		}
		if (temp == null)
			insertLast(n);
		else {
			Node newN = new Node(n);
			newN.prev = temp;
			newN.next = temp.next;
			newN.next.prev = newN;
			temp.next = newN;
		}
	}
	
	//delete at first
	static void deleteFirst() {
		Node temp = head;
		head = head.next;
		head.prev = null;
		temp = null;
	}
	
	//delete Last
	static void deleteLast() {
		Node temp = head;
		while(temp.next.next != null) {
			temp = temp.next;
		}
		Node last = temp.next;
		temp.next = null;
		last = null;
	}
	
	//delete at given position
	static void deletPos(int pos) {
		Node temp = head;
		int count = 1;
		while(temp != null && pos < count-1) {
		  count++;
		  temp = temp.next;
		}
		
		if(temp == null)
			return;
		
		if(temp.next == null) 
			deleteLast();
		else {
			Node nodeDel = temp.next;
			temp.next.next.prev = temp;
			temp.next = temp.next.next;
			nodeDel = null;
		}
	}
	
	//delete complete list
	static void deleteList() {
		head = null;
	}
	
	public static void main(String args[]) {
		insertFirst(1);
		insertFirst(2);
		insertFirst(3);
		insertFirst(4);
		insertFirst(5);
		printList();
		insertLast(6);
		printList();
		insertPos(0,2);
		printList();
		deleteFirst();
		printList();
		deleteLast();
		printList();
		deletPos(2);
		printList();
	}
}