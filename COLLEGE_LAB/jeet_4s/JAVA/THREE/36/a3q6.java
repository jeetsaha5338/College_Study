import java.util.*;

class T
{
	void display()
	{		
		System.out.println("CLASS T");
	}
}

class T1 extends T
{
	void display()
	{
		System.out.println("CLASS T1");
	}
}

class T2 extends T
{
	void display()
	{
		System.out.println("CLASS T2");
	}
}

class T3 extends T
{
	public static void main(String a[])
	{		
		T t=new T();
		t.display( );
		t=new T1();
		t.display( );
		t=new T2();
		t.display();
		t=new T3();
		t.display();
		
	}
	
	void display()
	{		
		System.out.println("CLASS T3");
	}
}
