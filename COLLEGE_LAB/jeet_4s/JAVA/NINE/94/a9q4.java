import java.util.*;

class T
{
	public static void main(String []a)
	{
		T ob= null;
		try
		{
			ob.go();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
		System.out.println("END");
	}
	void go()
		{
			System.out.println("IN");
		}
}
