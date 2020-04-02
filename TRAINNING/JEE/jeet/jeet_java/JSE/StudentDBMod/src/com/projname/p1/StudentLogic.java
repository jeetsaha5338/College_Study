package com.projname.p1;

import java.util.ArrayList;
import java.util.Scanner;

public class StudentLogic
{

	StudentInfo stdobj=new StudentInfo();
	StudentInfo stdobj1=new StudentInfo();
	
	Scanner sc=new Scanner(System.in);
	
	public void userInput()
	{
		
			//create object of class and store in the array
			
			System.out.println("Enter roll no.");
			stdobj.setRollno(sc.nextInt());
		
			System.out.println("Enter C mark");
			stdobj.setCmarks(sc.nextDouble());
		
			System.out.println("Enter java mark");
			stdobj.setJavamarks(sc.nextDouble());
		
			System.out.println("Enter Student Nmae");
			stdobj.setStname(sc.next());
		
	}
	
	public  void insertRecord()
	{
		DBLogic dbobj = new DBLogic();
		boolean replyfromdb = dbobj.insertData(stdobj);
		if(replyfromdb)
			System.out.println("RECORD INSERTED");
		else
			System.out.println("RECORD NOT INSERTED");
	}
	
	
	public void userInfo()
	{
		
			//create object of class and store in the array
			
			System.out.println("Enter roll no.");
			stdobj1.setRollno(sc.nextInt());
		
			System.out.println("Enter C mark");
			stdobj1.setCmarks(sc.nextDouble());
		
			System.out.println("Enter java mark");
			stdobj1.setJavamarks(sc.nextDouble());
		
	}
	
	public  void updateRecord()
	{
		DBLogic dbobj = new DBLogic();
		boolean replyfromdb = dbobj.updateData(stdobj1);
		if(replyfromdb)
			System.out.println("RECORD UPDATED");
		else
			System.out.println("RECORD NOT UPDATED");
	}
	
	public  void deleteRecord()
	{
		DBLogic dbobj = new DBLogic();
		System.out.println("Enter The Roll no.");
		
		boolean replyfromdb = dbobj.deleteData(sc.nextInt());
		if(replyfromdb)
			System.out.println("RECORD DELETED");
		else
			System.out.println("RECORD NOT DELETED");
	}

	public void display()
	{
		DBLogic dbobj =new DBLogic();
		ArrayList<StudentInfo> stdList = dbobj.fetchAllRecord();
		//for each loop
		for(StudentInfo ob :stdList)
		{
			System.out.println(" ");
			System.out.println("Student name"+" "+ob.getStname());
			System.out.println("Student roll"+" "+ob.getRollno());
			System.out.println("Student c mark"+" "+ob.getCmarks());
			System.out.println("Student java marks"+" "+ob.getJavamarks());
			System.out.println(" ");
		}
	
	}

}
