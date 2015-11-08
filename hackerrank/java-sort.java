import java.util.*;

class Student implements Comparable<Student>{
	private int id;
	private String fname;
	private double cgpa;
	public Student(int id, String fname, double cgpa) {
		super();
		this.id = id;
		this.fname = fname;
		this.cgpa = cgpa;
	}
	public int getId() {
		return id;
	}
	public String getFname() {
		return fname;
	}
	public double getCgpa() {
		return cgpa;
	}
	public int compareTo(Student o){
		int c=Double.valueOf(cgpa).compareTo(o.cgpa);
		if(c!=0)return -c;
		c=fname.compareTo(o.fname);
		if(c!=0)return c;
		c=Integer.valueOf(id).compareTo(o.id);
		return c;
	}
}

class Solution{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.nextLine());
		
		List<Student> studentList = new ArrayList<Student>();
		while(testCases>0){
			int id = in.nextInt();
			String fname = in.next();
			double cgpa = in.nextDouble();
			
			Student st = new Student(id, fname, cgpa);
			studentList.add(st);
			
			testCases--;
		}
		Collections.sort(studentList);
		for(Student st: studentList){
			System.out.println(st.getFname());
		}
	}
}