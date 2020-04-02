import java.util.*;

interface T
{
	void show();
}

class Anonymous
{
	public static void main(String []args)
	{
		T t=new T(){	public void show()
						{
							System.out.println("Hello");
						}
					};
		t.show();
	}
}

