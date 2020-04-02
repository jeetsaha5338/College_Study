import java.util.*;


class T

{
	
	public static void main(String a[])	

	{
		
		String s="java is a innovative language";

		String arr[]=s.split(" ");
	
		for(String s1:arr)

		{
	
			System.out.println(s1);

		}	

		for(int i=0;i<arr.length-1;i++)	

		{
	
			for(int j=0;j<arr.length-i-1;j++)

			{
				
				if(arr[j].compareTo(arr[j+1])>0)

				{
				
					String t=arr[j];

					arr[j]=arr[j+1];

					arr[j+1]=t;	

				}
			
			}

		}
	
		System.out.println(" ");

		for(String s2:arr)
	
		{

			System.out.println(s2);

		}

	}

}
		
