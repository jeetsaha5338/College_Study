import java.util.*;

class ME extends Exception
{
	public String toString()
	{
		return "PayOutOfBoundsException";
	}
}
class T extends Exception
{
	public static void main(String []args)
	{
		System.out.println("ENTER THE VALUE OF SALARY:");
		Scanner sc=new Scanner(System.in);
		try
		{
			int i=sc.nextInt();
			if(i<10000)
			{
				throw new ME();
			}
			else
			{
				System.out.println("DONE");
			}
		}
		catch(ME e)
		{
			System.out.println(e);
		}
	}
}
