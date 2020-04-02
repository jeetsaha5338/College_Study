import java.util.*;

class EMP
{
	String name,id;
	EMP(){}
	EMP(String name,String id)
	{
		this.name=name;
		this.id=id;
	}
	public String toString()
	{
		return name+" "+id;
	}
	
}

class scientist extends EMP
{
	String exp,noe;
	scientist(){}
	scientist(String name,String id,String exp,String noe)
	{
		this.name=name;
		this.id=id;
		this.exp=exp;
		this.noe=noe;
	}
	public String toString()
	{
		return name+" "+id+" "+exp+" "+noe;
	}
}

class Dscientist extends scientist
{
	String award;
	Dscientist(){}
	Dscientist(String name,String id,String exp,String noe,String award)
	{
		this.name=name;
		this.id=id;
		this.exp=exp;
		this.noe=noe;
		this.award=award;
	}
	public String toString()
	{
		return name+" "+id+" "+exp+" "+noe+" "+award;
	}
	public static void main(String args[])
	{
		String name,id,exp,noe,award;
	
		Scanner sc=new Scanner(System.in);

		System.out.println("ENTER NAME & ID:");
		name=sc.next();
		id=sc.next();
		EMP x=new EMP(name,id);
		System.out.println(x);

		System.out.println("ENTER NAME,ID,EXP & NOE:");
		name=sc.next();
		id=sc.next();
		exp=sc.next();
		noe=sc.next();
		scientist y=new scientist(name,id,exp,noe);
		System.out.println(y);
	
		System.out.println("ENTER NAME,ID,EXP,NOE & AWARD:");
		name=sc.next();
		id=sc.next();
		exp=sc.next();
		noe=sc.next();
		award=sc.next();
		Dscientist z=new Dscientist(name,id,exp,noe,award);
		System.out.println(z);
	}
}
