package ListQueueStack;

public class main {
	public static void main(String[] args) { 
		MyList<Integer>[] help = new MyList[2];
		help[0] = new MyQueue<>();
		help[1] = new MyStack<>();
		
		for (int i = 0; i < 3; i++) {
			help[0].push(i);
			help[1].push(i);
		}
		
		help[0].print();
		help[1].print();
		
		System.out.println("Pop 1 element");
		help[0].pop();
		help[1].pop();
		
		help[0].print();
		help[1].print();
		
	}
}
