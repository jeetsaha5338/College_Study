package com.projname.iooperation;

import java.util.Scanner;

public class IOstudentLogic
{
	private String Stname;
	private int rollno;
	private double cmarks;
	private double javamarks;
	//array of object
	private IOstudentLogic stdList[]=new IOstudentLogic[3];
	Scanner sc=new Scanner(System.in);
	
	public void userInput()
	{
		for(int i=0;i<3;i++)
		{
			//create object of class and store in the array
			stdList[i]=new IOstudentLogic();
		
			System.out.println("Enter roll no.");
			stdList[i].rollno=sc.nextInt();
		
			System.out.println("Enter C mark");
			stdList[i].cmarks=sc.nextDouble();
		
			System.out.println("Enter java mark");
			stdList[i].javamarks=sc.nextDouble();
		
		System.out.println("Enter Student Nmae");
		stdList[i].Stname=sc.next();
		}
	}

public void display()
{
	//for each loop
	for(IOstudentLogic ob :stdList)
	{
		System.out.println("Student name"+" "+ob.Stname);
		System.out.println("Student roll"+" "+ob.rollno);
		System.out.println("Student c mark"+" "+ob.cmarks);
		System.out.println("Student java marks"+" "+ob.javamarks);
	}
}
}
