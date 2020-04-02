import java.util.Scanner;

class primer{
	public static void main(String a[]){
		Scanner sc=new Scanner(System.in);
		int n,c,f,i;
		System.out.print("enter the range=");
		c=sc.nextInt();	
		for(n=2;n<=c;n++)
		{
			f=0;
			for(i=2;i<=n/2;i++)
			{
				if(n%i==0)
				{
					f=1;
					break;
				}
				
			}
			if(f==0)
			{
				System.out.println(n);
			}
		}
	}
}
