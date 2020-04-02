import java.util.*;

class T
{
	public static void main(String []a)
	{
		try
		{
			int b[]= new int[-5];
			for(int k=0;k<5;k++)
			{
				System.out.println(b[k]);
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		System.out.println("END");
	}
}
