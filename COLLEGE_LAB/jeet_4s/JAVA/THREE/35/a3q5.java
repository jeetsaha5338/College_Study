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
		T1 t1=new T1();
		t1.display( );
		T2 t2=new T2();
		t2.display();
		T3 t3=new T3();
		t3.display();
		t3.go();
	}
	void go()
	{
		super.display();
	}
	void display()
	{		
		System.out.println("CLASS T3");
	}
}
