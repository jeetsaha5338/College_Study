class MyThread_1 implements Runnable
{
	Thread t;
	 
	MyThread_1()
	{
		t=new Thread(this,"Demo Thread");
		System.out.println("Runnable_Child Thread:"+t);
		t.start();
	}
	
	public void run()
	{
		try
		{
			for(int i=0;i<5;i++)
			{
				System.out.println("Runnable_Child Thread: "+i);
				t.sleep(500);
			}
		}
		catch(Exception e)
		{
			System.out.println(e.toString());
		}
		System.out.println("EXIT Runnable_Child=XXXXXXXXXXXXXXXXXXXXXXXXX");
	}
}

class MyThread_2 extends Thread
{
	Thread t;
	 
	MyThread_2()
	{
		super("Demo Thread");
		System.out.println("Thread_Child Thread:"+this);
		start();
	}
	
	public void run()
	{
		try
		{
			for(int i=0;i<5;i++)
			{
				System.out.println("Thread_Child Thread: "+i);
				Thread.sleep(500);
			}
		}
		catch(Exception e)
		{
			System.out.println(e.toString());
		}
		System.out.println("EXIT Thread_Child=XXXXXXXXXXXXXXXXXXXXXXXXX");
	}
}

class ThreadDemo
{
	public static void main(String a[])
	{
		Thread t=Thread.currentThread();
		new MyThread_1();
		new MyThread_2();
		try
		{
			for(int i=0;i<5;i++)
			{
				System.out.println("Main Thread: "+i);
				t.sleep(1000);
			}
		}
		catch(Exception e)
		{
			System.out.println(e.toString());
		}
		System.out.println("EXIT Main=XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	}
}