package com.projname.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;

import com.projname.model.DoctorInfo;
import com.projname.model.PatientAppointment;

public class PatientBookAppointmentDAOClass {
	
	public boolean insertData(PatientAppointment ob)
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
				pst = con.prepareStatement("Insert into patientbookappointment values(?,?,?)");
				pst.setString(1, ob.getPemail());// "1" denotes first "?" mark
				pst.setString(2, ob.getDate());
				pst.setString(3, ob.getDemail());
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
	
	public ArrayList<PatientAppointment> viewRecordPatient(String patient)
	{
		ArrayList<PatientAppointment> stdList = new ArrayList<PatientAppointment>();
		Connection con =null;
		PreparedStatement pst =null;
		ResultSet rs=null;
		try
		{
			con = DBConnect.getMySQLConnection();
			if(con!=null)
			{
				System.out.println(patient);
				pst = con.prepareStatement("select * from PatientBookAppointment where PatientID = ?");
					pst.setString(1, patient);
				 rs=pst.executeQuery();
				
				while(rs.next())
				{
					//create object
					PatientAppointment ob =new PatientAppointment();
					//Retrive data from record & store in the object
					//Add To The Arraylist
					ob.setPemail(rs.getString(1));
					ob.setDemail(rs.getString(2));
					ob.setDate(rs.getString(3));
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
		System.out.println(stdList.size());
		return stdList;
	}
	
	public ArrayList<PatientAppointment> viewRecordDoctor(String doctor)
	{
		ArrayList<PatientAppointment> stdList = new ArrayList<PatientAppointment>();
		Connection con =null;
		PreparedStatement pst =null;
		ResultSet rs=null;
		try
		{
			con = DBConnect.getMySQLConnection();
			if(con!=null)
			{
				System.out.println(doctor);
				pst = con.prepareStatement("select * from PatientBookAppointment where DoctorID = ?");
					pst.setString(1, doctor);
				 rs=pst.executeQuery();
				
				while(rs.next())
				{
					//create object
					PatientAppointment ob =new PatientAppointment();
					//Retrive data from record & store in the object
					//Add To The Arraylist
					ob.setPemail(rs.getString(1));
					ob.setDemail(rs.getString(2));
					ob.setDate(rs.getString(3));
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
		System.out.println(stdList.size());
		return stdList;
	}
	
	
	
	
	public boolean deleteData(PatientAppointment ob)
	{
		boolean f= false;
		Connection con =null;
		PreparedStatement pst =null;
		try
		{
			con =DBConnect.getMySQLConnection();
			if(con!=null)
			{
				pst = con.prepareStatement("delete from patientbookappointment where DoctorID =? and Date=?");
				pst.setString(1, ob.getDemail());
				pst.setString(2, ob.getDate());
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
	
	public ArrayList<PatientAppointment> fetchAllRecord()
	{
		ArrayList<PatientAppointment> stdList = new ArrayList<PatientAppointment>();
		Connection con =null;
		PreparedStatement pst =null;
		ResultSet rs=null;
		try
		{
			con = DBConnect.getMySQLConnection();
			if(con!=null)
			{
				pst = con.prepareStatement("select * from patientbookappointment");
				
				 rs=pst.executeQuery();
				
				while(rs.next())
				{
					//create object
					PatientAppointment ob =new PatientAppointment();
					
					//Retrive data from record & store in the object
					ob.setPemail(rs.getString(1));
					ob.setDate(rs.getString(2));
					ob.setDemail(rs.getString(3));
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
	
	public int check(String Demail, String Date)
	{
		int count = 0;
		
		Connection con =null;
		PreparedStatement pst =null;
		ResultSet rs=null;
		try
		{
			con = DBConnect.getMySQLConnection();
			if(con!=null)
			{
				//System.out.println(doctor);
				pst = con.prepareStatement("select * from PatientBookAppointment where DoctorID = ? and Date = ?");
					pst.setString(1, Demail);
					pst.setString(2, Date);
				 rs=pst.executeQuery();
				
				while(rs.next())
				{
					//create object
					/*PatientAppointment ob =new PatientAppointment();
					//Retrive data from record & store in the object
					//Add To The Arraylist
					ob.setPemail(rs.getString(1));
					ob.setDemail(rs.getString(2));
					ob.setDate(rs.getString(3));
					stdList.add(ob);*/
					count++;
				}
			
				
			}
		}catch(Exception e){System.out.println(e.toString());}
		finally 
		{
			DBConnect.closeMySQLConnectiion(con);
			DBConnect.closePreparedStatementConnection(pst);
			DBConnect.closeResultSetConnectiion(rs);
		}
		return count;
	}
	
	
	
	
	

}
