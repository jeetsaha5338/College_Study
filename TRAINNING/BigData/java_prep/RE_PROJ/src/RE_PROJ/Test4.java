package RE_PROJ;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Test4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String records[] = {"amit,1234567890","sumit,9876543210","jeet,7278368361"};
		String what = "(^[a-z]+),(\\d{10})$";
		Pattern p=Pattern.compile(what);
		for(int i=0;i<records.length;i++)
		{
			Matcher m=p.matcher(records[i]);
			if(m.matches()){
				//System.out.println("matched");
				System.out.println(m.group());
			}
			else {
				System.out.println("no matching");
			}
		}
		
		
	}

}
