package com.projname.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;

import com.projname.model.DoctorInfo;


public class DoctorDAOClass 
{
	public boolean insertData(DoctorInfo ob)
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
				pst = con.prepareStatement("Insert into DoctorInfo values(?,?,?,?,?,?,?,?,?,?,?,?)");
				pst.setString(1, ob.getDname());// "1" denotes first "?" mark
				pst.setString(2, ob.getDemail());
				pst.setString(3, ob.getDmob());
				pst.setString(4, ob.getQual());
				pst.setString(5, ob.getDspec());
				pst.setString(6, ob.getExp());
				pst.setString(7, ob.getReg());
				pst.setString(8, ob.getDfees());
				pst.setString(9, ob.getDtime());
				pst.setString(10, ob.getDpno());
				pst.setString(11, ob.getDpass());
				pst.setString(12, ob.getEnable());
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
	
	public ArrayList<DoctorInfo> fetchAllRecord()
	{
		ArrayList<DoctorInfo> stdList = new ArrayList<DoctorInfo>();
		Connection con =null;
		PreparedStatement pst =null;
		ResultSet rs=null;
		try
		{
			con = DBConnect.getMySQLConnection();
			if(con!=null)
			{
				pst = con.prepareStatement("select * from DoctorInfo");
				
				 rs=pst.executeQuery();
				
				while(rs.next())
				{
					//create object
					DoctorInfo ob =new DoctorInfo();
					
					//Retrive data from record & store in the object
					ob.setDname(rs.getString(1));
					ob.setDemail(rs.getString(2));
					ob.setDmob(rs.getString(3));
					ob.setQual(rs.getString(4));
					ob.setDspec(rs.getString(5));
					ob.setExp(rs.getString(6));
					ob.setReg(rs.getString(7));
					ob.setDfees(rs.getString(8));
					ob.setDtime(rs.getString(9));
					ob.setDpno(rs.getString(10));
					ob.setDpass(rs.getString(11));
					ob.setEnable(rs.getString(12));
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
	
	public boolean enableDoctor(DoctorInfo ob)
	{
		boolean f= false;
		Connection con =null;
		PreparedStatement pst =null;
		try
		{
			con =DBConnect.getMySQLConnection();
			if(con!=null)
			{
				pst = con.prepareStatement("update doctorinfo set Enable = ? where Demail = ?");
				pst.setString(1, "true");
				pst.setString(2, ob.getDemail());
				int i2=pst.executeUpdate();
				if(i2>0)
				{
					f=true;
				}
				
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
	
	public boolean disableDoctor(DoctorInfo ob)
	{
		boolean f= false;
		Connection con =null;
		PreparedStatement pst =null;
		try
		{
			con =DBConnect.getMySQLConnection();
			if(con!=null)
			{
				pst = con.prepareStatement("update doctorinfo set Enable = ? where Demail = ?");
				pst.setString(1, "false");
				pst.setString(2, ob.getDemail());
				int i2=pst.executeUpdate();
				if(i2>0)
				{
					f=true;
				}
				
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
	
	public boolean deleteData(DoctorInfo ob)
	{
		boolean f= false;
		Connection con =null;
		PreparedStatement pst =null;
		try
		{
			con =DBConnect.getMySQLConnection();
			if(con!=null)
			{
				pst = con.prepareStatement("delete from StudentPersonalInfo1 where Stemail =?");
				pst.setString(1, ob.getDemail());
				int i2=pst.executeUpdate();
				if(i2>0)
				{
					f=true;
				}
				
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
	
	public DoctorInfo LoginCheck(String uname, String pass)
	{
		Connection con =null;
		PreparedStatement pst =null;
		ResultSet rs=null;
		DoctorInfo ob = new DoctorInfo();
		ob.setEnable("invalid");
		try
		{
			con = DBConnect.getMySQLConnection();
			if(con!=null)
			{
				pst = con.prepareStatement("select * from DoctorInfo where Demail =? and Dpass=?");
				pst.setString(1, uname);
				pst.setString(2, pass);
				 rs=pst.executeQuery();
				
				if(rs.next())
				{
				    System.out.println("FOUNND");
					
					//Retrive data from record & store in the object
					ob.setDname(rs.getString(1));
					ob.setDemail(rs.getString(2));
					ob.setDmob(rs.getString(3));
					ob.setQual(rs.getString(4));
					ob.setDspec(rs.getString(5));
					ob.setExp(rs.getString(6));
					ob.setReg(rs.getString(7));
					ob.setDfees(rs.getString(8));
					ob.setDtime(rs.getString(9));
					ob.setDpno(rs.getString(10));
					ob.setDpass(rs.getString(11));
					ob.setEnable(rs.getString(12));
			}
			
				
			}
		}catch(Exception e){System.out.println(e.toString());}
		finally 
		{
			DBConnect.closeMySQLConnectiion(con);
			DBConnect.closePreparedStatementConnection(pst);
			DBConnect.closeResultSetConnectiion(rs);
		}
		
		return ob;
	}
	
	
	
	
	
	
}
