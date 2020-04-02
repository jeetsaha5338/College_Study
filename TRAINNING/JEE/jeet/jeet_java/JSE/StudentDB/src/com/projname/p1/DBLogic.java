package com.projname.p1;
import java.sql.Connection;//interface
import java.sql.DriverManager;//class
import java.sql.PreparedStatement;//interface
import java.sql.ResultSet;
import java.sql.SQLException;//class
import java.util.ArrayList;
public class DBLogic {

	public static Connection getMySQLConnection() throws ClassNotFoundException,SQLException
	{
		Class.forName("com.mysql.jdbc.Driver");//load and register driver, 
		//establish connection
		Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/jee","root","sanu..1996");
		return con;
	}
	public boolean insertData(StudentInfo ob)
	{
		boolean f = false;
		try
		{
			//create
			Connection con = getMySQLConnection();
			//create query
			PreparedStatement pst = con.prepareStatement("Insert into StudentInfo values(?,?,?,?)");
			pst.setString(1, ob.getStname());// "1" denotes first "?" mark
			pst.setInt(2, ob.getRollno());
			pst.setString(3, ""+ob.getCmarks());
			pst.setString(4, ""+ob.getJavamarks());
			/*
			//PreparedStatement pst = con.prepareStatement("delete from StudentInfo where roll =?");
			//pst.setInt(1, 5);
			
			PreparedStatement pst = con.prepareStatement("update StudentInfo set cmarks =?, javamarks =? where roll =?");
			pst.setInt(3, ob.getRollno());
			pst.setString(1, ""+ob.getCmarks());
			pst.setString(2, ""+ob.getJavamarks());*/
			
			int i1 = pst.executeUpdate();//when DB is updated "i1" is = to no. of modification & i1 is 0 if no update done.
			if(i1>0)
				f = true;
		}catch(Exception e){System.out.println(e.toString());}
		return f;
	}
	public ArrayList<StudentInfo> fetchAllRecord()
	{
		ArrayList<StudentInfo> stdList = new ArrayList<StudentInfo>();
		try
		{
			Connection con = getMySQLConnection();
			PreparedStatement pst = con.prepareStatement("select * from studentinfo");
			
			ResultSet rs=pst.executeQuery();
			
			while(rs.next())
			{
				//create object
				StudentInfo ob =new StudentInfo();
				
				//Retrive data from record & store in the object
				ob.setStname(rs.getString(1));
				ob.setRollno(rs.getInt(2));
				ob.setCmarks(Double.parseDouble(rs.getString(3)));
				ob.setJavamarks(Double.parseDouble(rs.getString(4)));
				
				//Add To The Arraylist
				stdList.add(ob);
				
			}
		}catch(Exception e){System.out.println(e.toString());}
		
		return stdList;
	}
}
//insert,delete,update---> executeUpdate()
//select--->executeQuery()
