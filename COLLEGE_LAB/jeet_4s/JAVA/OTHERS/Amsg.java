import java.util.Scanner;

class Amsg{
	public static void main(String a[]){
		Scanner sc=new Scanner(System.in);
		int n,m,j,i=0,r,s=0,k=1;
		System.out.print("enter the no.=");
		n=sc.nextInt();	
		m=n;
		while(n>0)
		{
			r=n%10;
			n=n/10;
			i++;
		}
		n=m;
		while(n>0)
		{
			r=n%10;
			n=n/10;
			for(j=1;j<=i,j++)
			{
				k=k*r;
		}
		if(m==s)
			System.out.print("palindrom");
		else
			System.out.print(" not palindrom");
	}
}
