package com.projname.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;

import com.projname.model.PatientInfo;
import com.projname.model.PrescriptionInfo;

public class PrespDAOClass 
{
	public boolean insertMedicineData(PrescriptionInfo ob)
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
				pst = con.prepareStatement("Insert into MedicineDetails values(?,?,?,?,?,?,?,?)");
				pst.setString(1, ob.getMname1());// "1" denotes first "?" mark
				pst.setString(2, ob.getMdose1());
				pst.setString(3, ob.getMdur1());
				pst.setString(4, ob.getMname2());
				pst.setString(5, ob.getMdose2());
				pst.setString(6, ob.getMdur2());
				pst.setString(7, ob.getPid());
				pst.setString(8, ob.getDocId());
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
	
	public boolean insertPathologyData(PrescriptionInfo ob)
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
				pst = con.prepareStatement("Insert into PathologyDetails values(?,?,?,?)");
				pst.setString(1, ob.getPtest1());// "1" denotes first "?" mark
				pst.setString(2, ob.getPtest2());
				pst.setString(3, ob.getPid());
				pst.setString(4, ob.getDocId());
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
	
	public ArrayList<PrescriptionInfo> fetchMedicineRecord()
	{
		ArrayList<PrescriptionInfo> stdList = new ArrayList<PrescriptionInfo>();
		Connection con =null;
		PreparedStatement pst =null;
		ResultSet rs=null;
		try
		{
			con = DBConnect.getMySQLConnection();
			if(con!=null)
			{
				pst = con.prepareStatement("select * from medicinedetails");
				
				 rs=pst.executeQuery();
				
				while(rs.next())
				{
					//create object
					PrescriptionInfo ob =new PrescriptionInfo();
					
					//Retrive data from record & store in the object
					ob.setMname1(rs.getString(1));
					ob.setMdose1(rs.getString(2));
					ob.setMdur1(rs.getString(3));
					ob.setMname2(rs.getString(4));
					ob.setMdose2(rs.getString(5));
					ob.setMdur2(rs.getString(6));
					ob.setPid(rs.getString(7));
					ob.setDocId(rs.getString(8));
					
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
	
	public ArrayList<PrescriptionInfo> fetchPathologyRecord()
	{
		ArrayList<PrescriptionInfo> stdList1 = new ArrayList<PrescriptionInfo>();
		Connection con =null;
		PreparedStatement pst =null;
		ResultSet rs=null;
		try
		{
			con = DBConnect.getMySQLConnection();
			if(con!=null)
			{
				pst = con.prepareStatement("select * from PathologyDetails");
				
				 rs=pst.executeQuery();
				
				while(rs.next())
				{
					//create object
					PrescriptionInfo ob =new PrescriptionInfo();
					
					//Retrive data from record & store in the object
					ob.setPtest1(rs.getString(1));
					ob.setPtest2(rs.getString(2));
					ob.setPid(rs.getString(3));
					ob.setDocId(rs.getString(4));
					
					//Add To The Arraylist
					stdList1.add(ob);
			}
			
				
			}
		}catch(Exception e){System.out.println(e.toString());}
		finally 
		{
			DBConnect.closeMySQLConnectiion(con);
			DBConnect.closePreparedStatementConnection(pst);
			DBConnect.closeResultSetConnectiion(rs);
		}
		
		return stdList1;
	}
	
	public boolean updateData(PrescriptionInfo ob)
	{
		boolean f= false;
		Connection con =null;
		PreparedStatement pst =null;
		try
		{
			con =DBConnect.getMySQLConnection();
			pst = con.prepareStatement("update medicinedetails set Mname1 =?,Mdose1 =?,Mdur1 =?,Mname2 =?,Mdose2 =?,Mdur2 =? where PatientId =?");
			pst.setString(1, ob.getMname1());
			pst.setString(2, ob.getMdose1());
			pst.setString(3, ob.getMdur1());
			pst.setString(4, ob.getMname2());
			pst.setString(5, ob.getMdose2());
			pst.setString(6, ob.getMdur2());
			pst.setString(7, ob.getPid());
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
