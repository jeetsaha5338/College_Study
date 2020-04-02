import java.util.*;

abstract class Account
{
	abstract void diposite();
	abstract void disp();
	abstract void withd();
	abstract void desInt();
	abstract void penalty();
}
class Curr_act extends Account
{
		static double bal;
		void diposite()
		{
			int dipo;
			Scanner sc=new Scanner(System.in);
			System.out.println("ENTER AMOUNT OF DEPOSITE:");
			dipo=sc.nextInt();
			bal=bal+dipo;
		}
		void disp()
		{
			System.out.println("YOUR ACCOUNT BAL. IS:"+bal);
		}
		void withd()
		{
			int withd;
			Scanner sc=new Scanner(System.in);
			System.out.println("ENTER AMOUNT OF WITHDRAW:");
			withd=sc.nextInt();
			bal=bal-withd;
		}
		void desInt()
		{
			int itr,t;
			Scanner sc=new Scanner(System.in);
			System.out.println("ENTER TIME:");
			t=sc.nextInt();
			bal=bal+(bal*0.05*t);
		}
		void penalty()
		{
			if(bal<1000)
			{	
				bal=bal-100;
			}
		}
}
class Savc_act extends Account
{
	static double bal;
	void diposite()
	{
		int dipo;
		Scanner sc=new Scanner(System.in);
		System.out.println("ENTER AMOUNT OF DEPOSITE:");
		dipo=sc.nextInt();
		bal=bal+dipo;
	}
	void disp()
	{
		System.out.println("YOUR ACCOUNT BAL. IS:"+bal);
	}
	void withd()
	{
		int withd;
		Scanner sc=new Scanner(System.in);
		System.out.println("ENTER AMOUNT OF WITHDRAW:");
		withd=sc.nextInt();
		bal=bal-withd;
	}	
	void desInt()
	{
		int itr,t;
		Scanner sc=new Scanner(System.in);
		System.out.println("ENTER TIME:");
		t=sc.nextInt();
		bal=bal+(bal*0.05*t);
	}
	void penalty()
	{
		if(bal<1000)
		{	
			bal=bal-100;
		}
	}
}
class T
{
	public static void main(String a[])
	{
		int i;
		Scanner sc=new Scanner(System.in);
		System.out.println("ENTER 1 FOR CURRENT & 2 FOR SAVINGS:");
		i=sc.nextInt();
		if(i==2)
		{
			Savc_act ob1=new Savc_act();
			ob1.diposite();
			ob1.withd();
			ob1.penalty();
			ob1.disp();
		}
		if(i==1)
		{
			Curr_act ob2=new Curr_act();
			ob2.diposite();
			ob2.withd();
			ob2.desInt();
			ob2.disp();
		}
	}
}
	
