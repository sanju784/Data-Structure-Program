class Node {
	int data;
	Node next;
	
	public Node(int n) {
		data = n;
		next = null;
	}
}

class Circular {
	static Node head = null;
	
	//print List
	static void printList() {
		Node temp = head;
		do {
			System.out.print(temp.data + "  ");
			temp = temp.next;
		} while(temp != head);
		System.out.println();
	}
	
	//Insert at First
	static void insertFirst(int n) {
		Node newN = new Node(n);
		if(head == null) {
			head = newN;
			newN.next = head;
		} else {
			Node temp = head;
			while(temp.next != head) {
				temp = temp.next;
			}
			newN.next = head;
			head = newN;
			temp.next = head;
		}
	}
	
	//Insert at Last
	static void insertLast(int n) {
		Node newN = new Node(n);
		Node temp = head;
		do{
			temp = temp.next;
		}while(temp.next != head);
		temp.next = newN;
		newN.next = head;
	}
	
	//Insert at position
	static void insertPos(int n, int pos) {
		Node newN = new Node(n);
		if(head == null || pos == 1) {
			insertFirst(n);
			return;
		}
		Node temp = head;
		int count = 1;
		do {
			temp = temp.next;
			count++;
		} while(temp.next != head && count < pos);
		
		if(temp.next == head) {
			insertLast(n);
			return;
		}
		newN.next = temp.next;
		temp.next = newN;
	}
	
	static void deleteFirst() {
		Node temp = head;
		do {
			temp = temp.next;
		} while(temp.next != head);
		temp.next = head.next;
		temp = head;
		head = head.next;
		temp = null;
	}
	
	static void deleteLast() {
		Node temp = head;
		do {
			temp = temp.next;
		} while(temp.next.next != head);
		Node temp2 = temp.next;
		temp.next = temp2.next;
		temp2 = null;
	}
	
	static void deletePos(int pos) {
		Node temp = head;
		int count = 1;
		while (count < pos && temp.next != head){
			count++;
			temp = temp.next;
		}
		if(temp.next != head) {
			Node temp2 = temp.next;
			temp.next = temp2.next;
			temp2 = null;
		}
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
		insertPos(7,2);
		printList();
		deleteFirst();
		printList();
		deleteLast();
		printList();
		deletePos(2);
		printList();
	}
}