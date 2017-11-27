class Node {
	int data;
	Node next;
	
	public Node(int n) {
		data = n;
		next = null;
	}
}

class List {
	static Node head;
	public static void main(String args[])
	{
		head = null;
		
		head = new Node(1);
		head.next = new Node(2);
		head.next.next = new Node(3);
		head.next.next.next = new Node(4);
		
		printList(head);
		
		insertAtBegin(0);
		System.out.println();
		printList(head);
		
		insertAtEnd(5);
		System.out.println();
		printList(head);
		
		insertAtPosition(6,3);
		System.out.println();
		printList(head);
		
		deleteAtFirst();
		System.out.println();
		printList(head);
		
		deleteAtLast();
		System.out.println();
		printList(head);
		
		deleteAtPosition(3);
		System.out.println();
		printList(head);
		
		deleteList();
		System.out.println();
		printList(head);
	}
	
	//Traverse a List
	static void printList(Node head) {
		while(head != null)
		{
			System.out.print(head.data + "  ");
			head = head.next;
		}
	}
	
	//Insert at First position of List
	static void insertAtBegin(int n) {
		Node newNode = new Node(n);
		newNode.next = head;
		head = newNode;
	}
	
	//Insert at Last position of List
	static void insertAtEnd(int n) {
		Node newNode = new Node(n);
		if(head == null) {
			head = newNode;
		} else {
			Node temp = head;
			while(temp.next != null)
			{
				temp = temp.next;
			}
			temp.next = newNode;
		}
	}
	
	//Insert at position pos
	static void insertAtPosition(int n, int pos) {
		if(head == null) {
			insertAtBegin(n);
		} else {
			Node temp = head;
			int count = 0;
			while(temp != null && count < pos-1) {
				count++;
				temp = temp.next;
			}
			if(temp == null)
				insertAtEnd(n);
			else {
				Node newNode = new Node(n);
				newNode.next = temp.next;
				temp.next = newNode;
			}
		}
	}
	
	//Delete first node
	static void deleteAtFirst() {
		if(head == null)
			return;
		Node temp = head;
		head = head.next;
		temp = null;
	}
	
	//Delete last node
	static void deleteAtLast() {
		if(head == null)
			return;
		Node temp = head;
		Node prev = null;
		while(temp.next != null)
		{
			prev = temp;
			temp = temp.next;
		}
		prev.next = null;
		temp = null;
	}
	
	//Delete at position pos
	static void deleteAtPosition(int pos) {
		if(head == null)
			return;
		int count = 0;
		Node temp = head;
		Node prev = null;
		while(temp != null && count < pos-1)
		{
			count++;
			prev = temp;
			temp = temp.next;
		}
		prev.next = temp.next;
		temp = null;
	}
	
	//Delete Complete List
	static void deleteList() {
		head = null;
	}
}