import java.util.Scanner;

class Pal{
	public static void main(String a[]){
		Scanner sc=new Scanner(System.in);
		int n,m,i,r,s=0;
		System.out.print("enter the no.=");
		n=sc.nextInt();	
		m=n;
		while(n>0)
		{
			r=n%10;
			n=n/10;
			s=s*10+r;
		}
		if(m==s)
			System.out.print("palindrom");
		else
			System.out.print(" not palindrom");
	}
}
