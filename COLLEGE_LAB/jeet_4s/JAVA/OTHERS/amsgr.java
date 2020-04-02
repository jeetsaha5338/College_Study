import java.util.Scanner;

class amsgr{
	public static void main(String a[]){
		Scanner sc=new Scanner(System.in);
		int n,m,c,f,j,i,r,s,k;
		System.out.print("enter the range=");
		c=sc.nextInt();	
		for(n=0;n<=c;n++)
		{
			m=n;
			i=0;
			while(n>0)
			{
				r=n%10;
				n=n/10;
				i++;
			}
			n=m;
			s=0;
			while(n>0)
			{	
				r=n%10;
				n=n/10;
				k=1;
				for(j=1;j<=i;j++)
				{
					k=k*r;
				}
				s=s+k;
			}
			n=m;
			if(m==s)
			{
				System.out.println(m);
			}
		}
	}
}
