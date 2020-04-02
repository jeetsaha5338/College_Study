import java.util.*;
import java.io.*;

interface I1
{
	void show1();
	void show2();
}
interface I2
{
	void show3();
	void show4();
}
interface I extends I1,I2
{
	void show();
}
class Test
{
	void display()
	{
		System.out.println("TEST");
	}
}
class T extends Test implements I
{
	public void show1()
	{
		System.out.println("SHOW1");
	}
	public void show2()
	{
		System.out.println("SHOW2");
	}
	public void show3()
	{
		System.out.println("SHOW3");
	}
	public void show4()
	{
		System.out.println("SHOW4");
	}
	void display()
	{
		System.out.println("DISPLAY");
	}
	public void show()
	{
		System.out.println("SHOW");
	}
	public static void main(String args[])
	{
		T ob=new T();
		ob.show1();
		ob.show2();
		ob.show3();
		ob.show4();
		ob.show();
		ob.display();
	}
}
		
		
