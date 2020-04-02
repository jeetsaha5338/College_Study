package com.projname.p1;

import java.util.Scanner;

public class MainClass 
{
	public static void main(String[] args)
	{
		StudentLogic stdobj = new StudentLogic();
		
		int i;
		Scanner sc=new Scanner(System.in);
	
		{
			System.out.println("Enter Your Choise:");
			System.out.println("\tInsert: 1");
			System.out.println("\tDelete: 2");
			System.out.println("\tUpdate: 3");
			System.out.println("\tDisplay: 4");
			i=sc.nextInt();
			switch(i)
			{
			
				case 1: stdobj.userInput();
						stdobj.insertRecord();
						break;
				case 2: stdobj.deleteRecord();
						break;
				case 3: stdobj.userInfo();
						stdobj.updateRecord();
						break;
				case 4: stdobj.display();
						break;
			}
		}while(i>4);
		
		
	}

}
