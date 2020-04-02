import java.util.*;
import java.io.*;
interface shape
{ 
	double pie=3.14;
	void area();
}
class circle implements shape
{
	static int r;
	circle(int r)
	{
		this.r=r;
	}
	public void area()
	{
		System.out.println("AREA OF CIRCLE:"+(r*pie*r));
	}
}
class rectangular implements shape
{
	static int a,b;
	rectangular(int a,int b)
	{
		this.a=a;
		this.b=b;
	}
	public void area()
	{	
		System.out.println("AREA OF RECTANGULAR:"+(a*b));
	}
}
class T
{
	public static void main(String args[]) throws IOException
	{
		int a,b,r;
		BufferedReader sc=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("ENTER THE VALUE OF A,B & R:");
		a=Integer.parseInt(sc.readLine());
		b=Integer.parseInt(sc.readLine());
		r=Integer.parseInt(sc.readLine());
		shape ob;
		ob=new circle(r);
		ob.area();
		ob=new rectangular(a,b);
		ob.area();
	}
}
		
