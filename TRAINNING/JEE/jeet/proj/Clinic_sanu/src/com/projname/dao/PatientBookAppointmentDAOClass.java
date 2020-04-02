package com.projname.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;

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

}
