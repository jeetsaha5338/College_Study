import java.util.*;

class T
{
	public static void main(String []args)
	{
		try
		{
			int i=10;
			System.out.println(i);
			throw new ArithmeticException();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		System.out.println("end");
	}
}
		
