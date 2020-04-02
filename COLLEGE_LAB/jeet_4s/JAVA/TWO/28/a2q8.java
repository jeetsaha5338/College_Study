import java.util.Scanner;

class student
{
	static long roll;
	static String name,stream,college;
	public static void main(String a[])
	{
		System.out.print("enter the roll no.,name,stream,college=");
		Scanner sc=new Scanner(System.in);
		name=sc.next();
		stream=sc.next();
		college=sc.next();
		roll=sc.nextInt();
		System.out.print("enter the roll no.="+roll+",name="+name+",stream="+stream+",college="+college);
	}
}
