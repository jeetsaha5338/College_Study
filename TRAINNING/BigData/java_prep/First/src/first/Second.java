package first;
import java.util.*;

public class Second {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Student> al = new ArrayList<>();
		al.add(new Student(10,"John"));
		al.add(new Student(11, "tom"));
		al.add(new Student(12, "Jeet"));
		Iterator<Student> itr = al.iterator();
		while (itr.hasNext()) {
			Student s= itr.next();
			System.out.println(s.getRoll()+","+s.getName());
			
		}
		
	}

}
