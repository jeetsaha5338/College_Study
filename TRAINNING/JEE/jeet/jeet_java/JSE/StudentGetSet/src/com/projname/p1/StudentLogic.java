package com.projname.p1;

import java.util.Scanner;

public class StudentLogic {

	private StudentInfo stdList[]=new StudentInfo[3];
	
	Scanner sc=new Scanner(System.in);
	
	public void userInput()
	{
		for(int i=0;i<3;i++)
		{
			//create object of class and store in the array
			stdList[i]=new StudentInfo();
		
			System.out.println("Enter roll no.");
			stdList[i].setRollno(sc.nextInt());
		
			System.out.println("Enter C mark");
			stdList[i].setCmarks(sc.nextDouble());
		
			System.out.println("Enter java mark");
			stdList[i].setJavamarks(sc.nextDouble());
		
		System.out.println("Enter Student Nmae");
		stdList[i].setStname(sc.next());
		}
	}

public void display()
{
	//for each loop
	for(StudentInfo ob :stdList)
	{
		System.out.println("Student name"+" "+ob.getStname());
		System.out.println("Student roll"+" "+ob.getRollno());
		System.out.println("Student c mark"+" "+ob.getCmarks());
		System.out.println("Student java marks"+" "+ob.getJavamarks());
	}
}

}
