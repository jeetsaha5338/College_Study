class test
{
	int i;
	test(int k)
	{	
		i=k;
	}
	void display(test ob)
	{
		int j;
		j=ob.i;
		System.out.println(j);
	}
	public static void main(String a[])
	{
		test ob1=new test(20);
		ob1.display(ob1);
		test1 ob2=new test1();
		ob2.display1(ob2);
	}
}

class test1
{
	int s;
	test1()
	{
		s=100;
	}	
	void display1(test1 ob3)
	{
		int m;
		m=ob3.s;
		System.out.println(m);
	}
}
