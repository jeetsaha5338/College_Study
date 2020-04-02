package RE_PROJ;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class First {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String input = "This is an apple. There are 33 apples, Phrase...";
		//String what = "Th"; // "Th" == RE, simplest RE
		//String what = "[TP]h"; // Th/Ph
		String what="\\w+";// tring to escape from the escape character
		
		Pattern p=Pattern.compile(what);
		Matcher m=p.matcher(input);
		
		//'find' is only for finding the substring whole over the string
		while(m.find()){
			String matched=m.group();
			int start=m.start();
			int end = m.end();
			System.out.println(matched+"="+start+","+(end-1));
		}
		
		//'match' is for checking the whole string is following the pattern or not
		/*if(m.matches()){
			System.out.println(m.start()+","+(m.end()-1));
		}
		else {
			System.out.println("no matching");
		}*/
			
		
	}

}
