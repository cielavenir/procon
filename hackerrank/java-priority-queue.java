import java.util.*;

class Student implements Comparable<Student>{
	private int token;
	private String fname;
	private double cgpa;
	public Student(int id, String fname, double cgpa) {
		super();
		this.token = id;
		this.fname = fname;
		this.cgpa = cgpa;
	}
	public int getToken() {
		return token;
	}
	public String getFname() {
		return fname;
	}
	public double getCgpa() {
		return cgpa;
	}
	public int compareTo(Student other){
		if(getCgpa()>other.getCgpa())return -1;
		if(getCgpa()<other.getCgpa())return 1;
		int n=getFname().compareTo(other.getFname());
		if(n!=0)return n;
		if(getToken()<other.getToken())return -1;
		if(getToken()>other.getToken())return 1;
		return 0;
	}
}

class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int totalEvents = Integer.parseInt(in.nextLine());
		PriorityQueue<Student> q=new PriorityQueue<Student>();
		for(int i=0;i<totalEvents;i++){
			String event = in.next();
			if(event.equals("SERVED")){
				q.poll();
			}else{
				String name=in.next();
				double cgpa=in.nextDouble();
				int id=in.nextInt();
				q.offer(new Student(id,name,cgpa));
			}
		}
		if(q.size()==0){
			System.out.println("EMPTY");
		}else{
			for(;;){
				Student stu=q.poll();
				if(stu==null)break;
				System.out.println(stu.getFname());
			}
		}
	}
}