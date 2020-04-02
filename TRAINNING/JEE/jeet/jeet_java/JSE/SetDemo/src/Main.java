import java.util.TreeSet;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TreeSet<Integer> tobj = new TreeSet<Integer>();
		tobj.add(50);
		tobj.add(5);
		tobj.add(80);
		tobj.add(10);
		tobj.add(5);
		
		for(Integer x: tobj)
		{
			System.out.println(x);
		}
		
	}

}
