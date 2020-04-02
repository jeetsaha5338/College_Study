import java.util.*;

class Box
{
	static double v1,v2;
	void display(int x)
	{
		v1=Math.pow(x,3);
		System.out.println("volume of cube:"+v1);
	}
	void display(int a,int b)
	{
		v2=(Math.pow(a,2)*b*Math.PI)/3;
		System.out.println("volume of cone:"+v2);
	}
	public static void main(String ar[])
	{
		int r,h,a;
		System.out.print("ENTER THE VALUE OF R,H,A:");
		Scanner sc=new Scanner(System.in);
		r=sc.nextInt();
		h=sc.nextInt();
		a=sc.nextInt();
		Box ob=new Box();
		ob.display(a);
		ob.display(r,h);
	}
}
