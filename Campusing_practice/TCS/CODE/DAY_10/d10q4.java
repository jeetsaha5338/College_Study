import java.util.*;
class Test
{
	public static void main(String str[])
	{
		if(str.length<1)
		{
			System.out.println("ERORR");
			return;
		}
		ArrayList<String> l=new ArrayList<String>();
		for(String s1:str)
		{
			int count=0;
			for(String s2:str)
			{
				if(s2.equals(s1))
				{
					count++;
				}
			}
			if(count>1)
			{
				int f=0;
				for(String s3:l)
				{
					if(s3.equals(s1))
					{
						f=1;break;
					}
				}
				if(f==0)
				{
					l.add(s1);
					System.out.println(s1+": "+count);
				}
			}
		}
	}
}
