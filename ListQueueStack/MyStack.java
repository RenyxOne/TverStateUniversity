package ListQueueStack;

public class MyStack<T> extends MyList<T> {
	public void push(T info) {
		this.head = new Node<T>(info, this.head);
		this.size++;
	}
	public T pop() {
		Node<T> res = this.head;
		this.head = this.head.next;
		this.size--;
		return res.info;
	}
	
	@Override
	public void print() {
		System.out.println("----MyStack----\n");
		super.print();
	}
}
