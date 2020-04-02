package com.projname.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;

import com.projname.model.DoctorInfo;
import com.projname.model.PatientInfo;

public class PatientDAOClass 
{
	public boolean insertData(PatientInfo ob)
	{
		boolean f = false;
		Connection con =null;
		PreparedStatement pst =null;
		try
		{
			//create
			con = DBConnect.getMySQLConnection();
			//create query
			if(con!=null)
			{
				pst = con.prepareStatement("Insert into PatientInfo values(?,?,?,?,?,?)");
				pst.setString(1, ob.getPname());// "1" denotes first "?" mark
				pst.setString(2, ob.getPemail());
				pst.setString(3, ob.getPmob());
				pst.setString(4, ob.getAge());
				pst.setString(5, ob.getGender());
				pst.setString(6, ob.getPpass());
				int i1 = pst.executeUpdate();//when DB is updated "i1" is = to no. of modification & i1 is 0 if no update done.
				if(i1>0)
					f = true;
			}
			
		
			
		}catch(Exception e){System.out.println(e.toString());}
		finally 
		{
			DBConnect.closeMySQLConnectiion(con);
			DBConnect.closePreparedStatementConnection(pst);
		}
		return f;
	}
	
	public ArrayList<PatientInfo> fetchAllRecord()
	{
		ArrayList<PatientInfo> stdList = new ArrayList<PatientInfo>();
		Connection con =null;
		PreparedStatement pst =null;
		ResultSet rs=null;
		try
		{
			con = DBConnect.getMySQLConnection();
			if(con!=null)
			{
				pst = con.prepareStatement("select * from PatientInfo");
				
				 rs=pst.executeQuery();
				
				while(rs.next())
				{
					//create object
					PatientInfo ob =new PatientInfo();
					
					//Retrive data from record & store in the object
					ob.setPname(rs.getString(1));
					ob.setPemail(rs.getString(2));
					ob.setPmob(rs.getString(3));
					ob.setAge(rs.getString(4));
					ob.setGender(rs.getString(5));
					ob.setPpass(rs.getString(6));
					
					//Add To The Arraylist
					stdList.add(ob);
			}
			
				
			}
		}catch(Exception e){System.out.println(e.toString());}
		finally 
		{
			DBConnect.closeMySQLConnectiion(con);
			DBConnect.closePreparedStatementConnection(pst);
			DBConnect.closeResultSetConnectiion(rs);
		}
		
		return stdList;
	}
	
	public boolean updateData(PatientInfo ob)
	{
		boolean f= false;
		Connection con =null;
		PreparedStatement pst =null;
		try
		{
			con =DBConnect.getMySQLConnection();
			pst = con.prepareStatement("update PatientInfo set Pmob= ?,Page= ?,Pgender= ?,Ppass= ? where Pemail = ?");
		//	
			pst.setString(1, ob.getPmob());
			pst.setString(2, ob.getAge());
			pst.setString(3, ob.getGender());
			pst.setString(4, ob.getPpass());
			pst.setString(5, ob.getPemail());
			int i3=pst.executeUpdate();
			if(i3>0)
			{
				f=true;
			}
		}catch (Exception e) {
			System.out.println(e.toString());
		}
		finally 
		{
			DBConnect.closeMySQLConnectiion(con);
			DBConnect.closePreparedStatementConnection(pst);
			
		}
		
		return f;
	}

}
