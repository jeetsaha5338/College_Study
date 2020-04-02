 import java.util.*;

class E1 extends Exception
{
	public String toString()
	{
		return "ExceptionOne";
	}
}

class E2 extends Exception
{
	public String toString()
	{
		return "ExceptionTwo";
	}
}
	
class T
{
	static void f()
	{
		new T().g();
	}
	void g()
	{
		try{throw new E1();}
	
		catch(E1 e)
		{
			System.out.println(e);
			try{throw new E2();}
			catch(E2 e1)
			{
				System.out.println(e1);
			}
		}
	}
	public static void main(String []args)
	{
		T.f();
	}
}
	
