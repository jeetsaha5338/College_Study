package com.projname.dao;

import java.sql.Connection;//interface
import java.sql.PreparedStatement;//interface
import java.sql.ResultSet;
import java.util.ArrayList;

import com.projname.model.StudentPersonalInfo;//class
public class DAOClass 
{

	
	public boolean insertData(StudentPersonalInfo ob)
	{
		boolean f = false;
		Connection con =null;
		PreparedStatement pst = null;
		try
		{
			//create
			con = DBConnect.getMySQLConnection();
			if(con !=null)
			{
			//create query
			pst = con.prepareStatement("Insert into StudentPersonalInfo1 values(?,?,?,?,?,?,?,?)");
			pst.setString(1, ob.getStname());// "1" denotes first "?" mark
			pst.setString(2, ob.getStemail());
			pst.setString(3, ob.getStmob());
			pst.setString(4, ob.getStpass());
			pst.setString(5, ob.getStdob());
			pst.setString(6, ob.getGender());
			pst.setString(7, ob.getHobby());
			pst.setString(8, ob.getStcountry());
		
			int i1 = pst.executeUpdate();//when DB is updated "i1" is = to no. of modification & i1 is 0 if no update done.
			if(i1>0)
				f = true;
			}
		}catch(Exception e){System.out.println(e.toString());}
		finally {
			DBConnect.closeMySQLConnection(con);
			DBConnect.closePreparedConnection(pst);
		}
		return f;
	}
	public boolean deleteData(StudentPersonalInfo ob)
	{
		boolean f = false;
		Connection con =null;
		PreparedStatement pst = null;
		try
		{
			//create
			con =DBConnect.getMySQLConnection();
			//create query
			
			pst = con.prepareStatement("delete from StudentPersonalInfo1 where Stname =?");
			/*pst.setInt(1, ob);*/pst.setString(1, ob.getStname());
			
			int i1 = pst.executeUpdate();//when DB is updated "i1" is = to no. of modification & i1 is 0 if no update done.
			if(i1>0)
				f = true;
		}catch(Exception e){System.out.println(e.toString());}
		return f;
	}
	
	public ArrayList<StudentPersonalInfo> fetchAllRecord()
	{
		ArrayList<StudentPersonalInfo> stdList = new ArrayList<StudentPersonalInfo>();
		
		Connection con = null;
		PreparedStatement pst = null;
		ResultSet rs= null;
		try
		{
			con = DBConnect.getMySQLConnection();
			pst = con.prepareStatement("select * from StudentPersonalInfo1");
			
			rs=pst.executeQuery();
			
			while(rs.next())
			{
				//create object
				StudentPersonalInfo ob =new StudentPersonalInfo();
				
				//Retrieve data from record & store in the object
				ob.setStname(rs.getString(1));
				ob.setStemail(rs.getString(2));
				ob.setStmob(rs.getString(3));
				ob.setStpass(rs.getString(4));
				ob.setStdob(rs.getString(5));
				ob.setGender(rs.getString(6));
				ob.setHobby(rs.getString(7));
				ob.setStcountry(rs.getString(8));
				//Add To The Arraylist
				stdList.add(ob);
				
			}
		}catch(Exception e){System.out.println(e.toString());}
		finally {
			DBConnect.closeMySQLConnection(con);
			DBConnect.closePreparedConnection(pst);
			DBConnect.closeResultSetConnection(rs);
		}
		
		return stdList;
	}
}
