import java.util.*;
class T
{
	public static void main(String a[])
	{
		String str1="Academy Of Technology";
		String str2="demy";
		if(str1.contains(str2))
		{
			int pos=str1.indexOf(str2);
			System.out.println("FOUND AT:"+pos);
		}
		else
		{
			System.out.println("NOT FOUND");
		}
	}
}