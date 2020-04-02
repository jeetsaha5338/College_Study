import java.util.*;

class NTE extends Thread
{
	public String toString()
	{
		return "New Thread";
	
	}
	public void run()
	{
		Thread t=Thread.currentThread();
		System.out.println(t);
		System.out.println("Child Thread");
	}
	public static void main(String a[])
	{
		NTE t=new NTE();
		Thread t1=Thread.currentThread();
		t.start();
		System.out.println(t);
		System.out.println(t1);
	}
}