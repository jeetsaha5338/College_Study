import java.util.*;

class T
{
	public static void main(String []a)
	{
		int i=a.length;
		try
		{
			System.out.println(i);
			int j= 10/i;
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		System.out.println("END");
	}
}
