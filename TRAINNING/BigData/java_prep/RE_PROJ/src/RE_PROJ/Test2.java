package RE_PROJ;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Test2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String phone ="7001212121,abc@gmail.com";
		
		String what = "[76]\\d{9},([a-z0-9]+)@\\w+(.com)";
		//String what = ",[a-z0-9]+@";
		
		Pattern p=Pattern.compile(what);
		Matcher m=p.matcher(phone);
		if(m.matches()){
			System.out.println(m.start()+","+(m.end()-1)+","+"matched");
			System.out.println("user"+":"+m.group(1)+",domain"+":"+m.group(2));
		}
		else {
			System.out.println("no matching");
		}
		

	}

}