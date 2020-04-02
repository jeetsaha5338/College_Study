import java.util.*;

class T
{
	public static void main(String a[])
	{
		try
		{
			String s=a[0].substring(Integer.parseInt(a[1]),Integer.parseInt(a[2]));
			System.out.println(s);
			StringBuffer sb=new StringBuffer(s);
			System.out.println(sb.reverse());
		}
		catch(StringIndexOutOfBoundsException e)
		{
			System.out.println(e);
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println(e);
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}
	}
}
