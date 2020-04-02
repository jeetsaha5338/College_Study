package first;
// ArrayList == growable array
// LinkedList == 2 directional
// Vector == Legacy
// HashSet == all unique element
// TreeSet == BST(sorted) Unique
// They Does not allow primitive datatype( int,byte,short,..)
// They store objects(references) only , class type
import java.util.*;
public class First {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<String> l =new ArrayList<String>();
		//LinkedList == generic class
		//LinkedList<class/interface> == specific class
		l.add("messi");
		l.add("neymar");
		l.add("cr7");
		//Iterator == interface
		Iterator<String> itr = l.iterator();
		while(itr.hasNext()) {
			String nm = itr.next();
			System.out.println("NAME: "+nm);
		}
	}

}
