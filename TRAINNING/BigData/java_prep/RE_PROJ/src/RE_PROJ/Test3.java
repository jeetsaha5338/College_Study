package RE_PROJ;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Test3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String record ="px123,kingstone,340,1|3|4|1";
		String record1 ="px125,electronics,storege,pendrive,kingstone,340,1|3|4|1";
		String record2 ="px125,electronics,storege,pendrive,kingstone,340";
		String what = "\\d+,(\\d\\|*)+$";
		Pattern p=Pattern.compile(what);
		Matcher m=p.matcher(record);
		if(m.find())
		{
			System.out.println("correct");
			String str[]=m.group().split(",");
			System.out.println(str[1]);
		}
		else
		{
			System.out.println("wrong");
		}
		
	}

}