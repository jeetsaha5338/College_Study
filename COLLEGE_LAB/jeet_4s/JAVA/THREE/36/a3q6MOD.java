import java.io.*;

class EMP
{
	String name;
	int id;
	EMP(){}
	EMP(String name,int id)
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
	String exp;
	int noe;
	scientist(){}
	scientist(String name,int id,String exp,int noe)
	{
		super(name,id);
		this.exp=exp;
		this.noe=noe;
	}
	public String toString()
	{
		return super.toString()+" "+exp+" "+noe;
	}
}

class Dscientist extends scientist
{
	String award;
	Dscientist(){}
	Dscientist(String name,int id,String exp,int noe,String award)
	{
		super(name,id,exp,noe);
		this.award=award;
	}
	public String toString()
	{
		return super.toString()+" "+award;
	}
	public static void main(String args[])throws IOException
	{
		String name,exp,award;
		int id,noe;
	
		BufferedReader sc=new BufferedReader(new InputStreamReader(System.in));

		System.out.println("ENTER NAME & ID:");
		name=sc.readLine();
		id=Integer.parseInt(sc.readLine());
		EMP x=new EMP(name,id);
		System.out.println(x);

		System.out.println("ENTER NAME,ID,EXP & NOE:");
		name=sc.readLine();
		id=Integer.parseInt(sc.readLine());
		exp=sc.readLine();
		noe=Integer.parseInt(sc.readLine());
		scientist y=new scientist(name,id,exp,noe);
		System.out.println(y);
	
		System.out.println("ENTER NAME,ID,EXP,NOE & AWARD:");
		name=sc.readLine();
		id=Integer.parseInt(sc.readLine());
		exp=sc.readLine();
		noe=Integer.parseInt(sc.readLine());
		award=sc.readLine();
		Dscientist z=new Dscientist(name,id,exp,noe,award);
		System.out.println(z);
	}
}
