import java.util.*;
class update
{
	public void /*synchronized*/ call()
	{
		Thread t=Thread.currentThread();
		for(int i=0;i<5;i++)
		{
			System.out.println(t.getName()+";"+i);
			try{Thread.sleep(200);}
			catch(Exception e){}
		}
	}
}
class T implements Runnable
{
	update u=new update();	
	public void run()
	{
		/*u.call();*/
		synchronized(u)
		{
			u.call();
		}
	}
	
}
class Synctest
{
	public static void main(String []a)
	{
		T u=new T();
		Thread t1=new Thread(u);
		Thread t2=new Thread(u);
		t1.setName("A");
		t2.setName("B");
		t1.start();
		t2.start();
	}
}