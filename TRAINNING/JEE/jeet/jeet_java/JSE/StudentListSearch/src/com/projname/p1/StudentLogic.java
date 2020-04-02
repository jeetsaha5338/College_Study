package com.projname.p1;

import java.util.ArrayList;
import java.util.Scanner;

public class StudentLogic {

	//private StudentInfo stdList[]=new StudentInfo[3];
	
	private ArrayList<StudentInfo> stdList= new ArrayList<StudentInfo>();
	
	Scanner sc=new Scanner(System.in);
	String reply;
	StudentInfo ob1 = new StudentInfo();
	public void userInput()
	{
		
		do
		{
			//create object of class and store in the array
			StudentInfo sob = new StudentInfo();
		
			System.out.println("Enter roll no.");
			sob.setRollno(sc.nextInt());
		
			System.out.println("Enter C mark");
			sob.setCmarks(sc.nextDouble());
		
			System.out.println("Enter java mark");
			sob.setJavamarks(sc.nextDouble());
		
			System.out.println("Enter Student Nmae");
			sob.setStname(sc.next());
			//Add Studentinfo object into arraylist
			stdList.add(sob);
			
			System.out.println("Want To Add Another Y/N");
			reply = sc.next();
		}while(reply.equalsIgnoreCase("y"));
		System.out.println("Enter roll no. to find:");
		ob1.setRollfind(sc.nextInt());
		//stdList.add(ob);
	}

public void display()
{
	int k=ob1.getRollfind();
	//for each loop
	for(StudentInfo ob :stdList)
	{
		if(k==ob.getRollno())
		{
			System.out.println("Student name"+" "+ob.getStname());
			System.out.println("Student roll"+" "+ob.getRollno());
			System.out.println("Student c mark"+" "+ob.getCmarks());
			System.out.println("Student java marks"+" "+ob.getJavamarks());

		}
	}
}

}
