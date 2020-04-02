class test
{
	int i;
	test()
	{	
		i=10;
	}
	test display(test ob)
	{
		i=ob.i*2;
		System.out.println(i);
		return ob;
	}
	public static void main(String a[])
	{
		test ob1=new test();
		test ob2=new test();
		System.out.println(ob2.i);
		ob2=ob1.display(ob1);
		System.out.println(ob2.i);
	}
}

