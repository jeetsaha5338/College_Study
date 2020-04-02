import java.util.*;

class Outer
{
	int i=10;
	static int j=10;
	class Inner
	{
		int k=30;
		static final int l=40;
		void show1()
		{
			System.out.println(i+" "+j+" "+k+" "+l);
		}
	}
	void show()
	{
		System.out.println(i+" "+j+" "+new Inner().k+" "+Inner.l);
	}
}

class T
{
	public static void main(String []args)
	{
		Outer ob= new Outer();
		Outer.Inner ob1=ob.new Inner();
		ob.show();
		ob1.show1();
	}
}
	
