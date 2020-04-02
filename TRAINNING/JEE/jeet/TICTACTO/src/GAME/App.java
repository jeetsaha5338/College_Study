package GAME;

import java.util.Scanner;

class Box{
	private final String index[][]=new String[3][3];
	public int turn;
		
	Scanner sc=new Scanner(System.in);
	
	Box(){
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				index[i][j]="_";
			}
		}
		turn=0;
	}
	
	public boolean check(String s)
	{
		if(index[0][0]==s && index[0][1]==s && index[0][2]==s)
		{
			System.out.print("Game Finished!  "+s+" WON");
			return false;
		}
		else if(index[1][0]==s && index[1][1]==s && index[1][2]==s)
		{
			System.out.print("Game Finished!  "+s+" WON");
			return false;
		}
		else if(index[2][0]==s && index[2][1]==s && index[2][2]==s)
		{
			System.out.print("Game Finished!  "+s+" WON");
			return false;
		}
		else if(index[0][0]==s && index[1][0]==s && index[2][0]==s)
		{
			System.out.print("Game Finished!  "+s+" WON");
			return false;
		}
		else if(index[0][1]==s && index[1][1]==s && index[2][1]==s)
		{
			System.out.print("Game Finished!  "+s+" WON");
			return false;
		}
		else if(index[0][2]==s && index[1][2]==s && index[2][2]==s)
		{
			System.out.print("Game Finished!  "+s+" WON");
			return false;
		}
		else if(index[0][0]==s && index[1][1]==s && index[2][2]==s)
		{
			System.out.print("Game Finished!  "+s+" WON");
			return false;
		}
		else if(index[0][2]==s && index[1][1]==s && index[2][0]==s)
		{
			System.out.print("Game Finished!  "+s+" WON");
			return false;
		}
		else
		{
			int f=0;
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(index[i][j]=="_")
					{
						f=1;
					}
				}
			}
			if(f==0)
			{
				System.out.println("Box is Full. Gamw Draw!");
				return false;
			}
		}
		return true;
	}
	
	public void start()
	{
		System.out.println("Game Started.");
		System.out.println("Box is :");
		this.show();
		while(this.check("X") && this.check("O"))
		{
			if(turn%2==0)
			{
				System.out.print("Player X ->");
			}
			else
			{
				System.out.print("Player O ->");
			}
			System.out.println("Enter Your Position:(1-9)");
			int pos=sc.nextInt();
			if(pos<1 || pos>9)
			{
				System.out.println("Position Invalid!. Try A New Place");
				continue;
			}
			int i=(pos-1)/3;
			int j=(pos-1)%3;
			if(index[i][j]!="_")
			{
				System.out.println("Position Already Full. Try A New Place");
				continue;
			}
			if(turn%2==0)
			{
				index[i][j]="X";
			}
			else
			{
				index[i][j]="O";
			}
			turn++;
			this.show();
		}	
	}
	
	public void show()
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				System.out.print(index[i][j]+"  ");
			}
			System.out.print("\t\t");
			for(int j=0;j<3;j++)
			{
				int k=i*3+j+1;
				System.out.print("["+k+"]  ");
			}
			System.out.println("\n");
		}
	}
	
}

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Box b=new Box();
		b.start();
	}

}
