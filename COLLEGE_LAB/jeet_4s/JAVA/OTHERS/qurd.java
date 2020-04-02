import java.util.Scanner;

class qurd{
	public static void main(String z[]){
		Scanner sc=new Scanner(System.in);
		int x1,x2,a,b,c,r1,r2,p;
		System.out.print("enter the value of a=");
		a=sc.nextInt();	
		System.out.print("enter the value of b=");
		b=sc.nextInt();
		System.out.print("enter the value of c=");
		c=sc.nextInt();
		r1=b*(-1);
		p=(b*b)-(4*a*c);
		r2=(float)Math.sqrt(p);
		if(p==0)
		{
			System.out.println("value of x="+r1);
		}
		else
		{
			if(p>0)
			{
				r2=(int)Math.sqrt(p);
				x1=(r1+r2)/(2.0*a);
				x2=(r1-r2)/(2.0*a);
				System.out.println("value of x="+x1);
				System.out.println("value of x="+x2);
			}	
			else
			{
				p=p*(-1);
				r2=(int)Math.sqrt(p);
				r1=r1/(2.0*a);
				r2=r2/(2.0*a);
				System.out.println("value of x="+r1+"+"+r2+"i");
				System.out.println("value of x="+r1+"-"+r2+"i");
			}	
		}	
	}
}
