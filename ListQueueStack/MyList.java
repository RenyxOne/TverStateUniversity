package ListQueueStack;

public class MyList<T> {
	protected class Node<T> {
        protected T info;
        protected Node<T> next;

        public Node(T info, Node<T> next) {
            this.info = info;
            this.next = next;
        }

        public Node(T info) {
            this.info = info;
            this.next = null;
        }
        
        public Node(Node<T> n) {
            this.info = n.info;
            this.next = null;
        }
    
    }
	
	protected Node<T> head;
	protected int size = 0;
	
	public MyList() {
		head=null;
	}
	public MyList(MyList<T> l) {
		if (l.head == null){ this.head = null;}
		else {
			this.head = new Node<T>(l.head.info);
			Node<T> cur = this.head;
		
			for (Node<T> i = l.head.next; i != null; i = i.next) {
				cur.next = new Node<T>(i.info);
				cur = cur.next;
			}
		}
		
	}
	
	public int getSize() {
		return this.size;
	}
	
	public T pop() { //йняршкэ
		return head.info;
	}
	public void push(T info) { //йняршкэ
	}
	
	public void push_back(T info) {
		Node<T> tmp = new Node<T>(info);
		
		if (this.head == null) {
			this.head = tmp;
			this.size++;
			return;
		}
		
		Node<T> cur = head;
		while (cur.next != null) cur = cur.next;
		cur.next = tmp;
		this.size++;
	}
	
	/*public void push_front(T info) {
		Node<T> tmp = new Node<T>(info);
		tmp.next = head;
		this.head = tmp;
		this.size++;
	}
	
	public T at(int pos) {
		if (pos >= size || pos < 0) throw new IllegalArgumentException("Pos "+ pos + " out of range! List size is: " + size + "\n");
		
		Node<T> cur = this.head;
		for (int i = 0; i < pos; i++) cur = cur.next;
		
		return cur.info;
	}
	*/
	void print() {
		Node<T> cur = this.head;
		while (cur != null) {
			System.out.println(cur.info);
			cur = cur.next;
		}
	}
}
