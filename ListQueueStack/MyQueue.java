package ListQueueStack;

public class MyQueue<T> extends MyList<T> {
	@Override
	public void push(T info) {
		if (this.head == null) {
			this.head = new Node(info);
			this.size++;
			return;
		}
		Node<T> cur = head;
		while (cur.next != null) cur = cur.next;
		cur.next = new Node(info);
		this.size++;
	}
	@Override
	public T pop() {
		Node<T> res = head;
		this.head = head.next;
		this.size--;
		return res.info;
	}
	@Override
	public void print() {
		System.out.println("----MyQueue----\n");
		super.print();
	}
}
