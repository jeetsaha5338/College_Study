import java.util.*;

class T
{
	public static void main(String []a)
	{
		String s="HELLO";
		int b[]={10,20};
		try
		{
			for(int k=0;k<2;k++)
			{
				System.out.println(b[k]);
			}
			System.out.println(s.charAt(s.length()));
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		System.out.println("END");
	}
}
