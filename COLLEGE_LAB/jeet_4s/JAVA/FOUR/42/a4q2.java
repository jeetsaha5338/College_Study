import java.util.*;

abstract class T
{
	int i;
	T()
	{
		i=10;
	}
	abstract void show1();
	abstract void show2();
	abstract void show3();
}
class T1 extends T
{
	T1()
	{
		super();
	}
	public static void main(String args[])
	{
		T1 ob=new T1();
		ob.show1();
		ob.show2();
	}
	void show1( )
	{
		System.out.println(i+1);
	}
	void show2( )
	{			
		 System.out.println(i+2);
	}
}
