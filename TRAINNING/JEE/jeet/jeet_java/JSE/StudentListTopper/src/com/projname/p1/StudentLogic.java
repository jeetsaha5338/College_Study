package com.projname.p1;

import java.util.ArrayList;
import java.util.Scanner;

public class StudentLogic {

	//private StudentInfo stdList[]=new StudentInfo[3];
	
	private ArrayList<StudentInfo> stdList= new ArrayList<StudentInfo>();
	
	Scanner sc=new Scanner(System.in);
	String reply;
	
	public void userInput()
	{
		do
		{
			//create object of class and store in the array
			StudentInfo sob =new StudentInfo();
		
			System.out.println("Enter roll no.");
			sob.setRollno(sc.nextInt());
		
			System.out.println("Enter C mark");
			sob.setCmarks(sc.nextDouble());
		
			System.out.println("Enter java mark");
			sob.setJavamarks(sc.nextDouble());
		
			System.out.println("Enter Student Nmae");
			sob.setStname(sc.next());
			double sum= sob.getCmarks()+ sob.getJavamarks();
			sob.setSum(sum);
			//Add Studentinfo object into arraylist
			stdList.add(sob);
			
			System.out.println("Want To Add Another Y/N");
			reply = sc.next();
		}while(reply.equalsIgnoreCase("y"));
	}

public void display()
{
	StudentInfo ob1= new StudentInfo();
	double highest = stdList.get(0).getSum();
	//for each loop
	for(StudentInfo ob :stdList)
	{
		if(highest<ob.getSum())
		{
			highest=ob.getSum();
			ob1=ob;
		}
	}
	System.out.println("Student name"+" "+ob1.getStname());
	System.out.println("Student roll"+" "+ob1.getRollno());
	System.out.println("Student c mark"+" "+ob1.getCmarks());
	System.out.println("Student java marks"+" "+ob1.getJavamarks());
	System.out.println("Total Marks:"+" "+highest);
}

}
