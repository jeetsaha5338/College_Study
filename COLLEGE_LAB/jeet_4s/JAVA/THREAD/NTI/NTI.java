import java.util.*;
class NTI implements Runnable
{
	public void run()
	{
		System.out.println("Child Thread");
	}
	public static void main(String a[])
	{
		System.out.println("FIRST");
		NTI t=new NTI();
		Thread t1=new Thread(t);
		t1.setName("child");
		t1.setPriority(8);
		t1.start();
		System.out.println(t1.getName());
		System.out.println(t1.getPriority());
		System.out.println("MAIN THREAD");
	}
}

	