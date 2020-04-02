import java.util.*;

abstract class Test
{
	int i=50;
	Test()
	{
		i=10;
	}
	void show()
	{
		System.out.println(i);
	}
}

class T extends Test
{
	public static void main(String args[])
	{
		T ob1=new T();
		ob1.show(); 
	}
	void show()
	{	
		super.show();
		System.out.println(i*2);
	}
}
