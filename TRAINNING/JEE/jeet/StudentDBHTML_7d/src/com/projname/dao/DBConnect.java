package com.projname.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;


public class DBConnect {
	public static Connection getMySQLConnection() //throws ClassNotFoundException,SQLException
	{
		Connection con = null;
		
		try
		{
		//CLASS NOT FOUND	
		Class.forName("com.mysql.jdbc.Driver");//load and register driver, 
		//establish connection
		
		//SQLEXCEPTION
		con = DriverManager.getConnection("jdbc:mysql://localhost:3306/jee","root","Jeet1998@");
		
		}
		catch (ClassNotFoundException e) {
			// TODO: handle exception
			System.out.println(e);
		}
		catch (SQLException e) {
			// TODO: handle exception
			System.out.println(e);
		}
		
		return con;
	}
	public static void closeMySQLConnection(Connection con)
	{
		if(con != null)
		{
			try{con.close();}
			catch (SQLException e) {e.printStackTrace();}
			
		}
	}
	
	public static void closePreparedConnection(PreparedStatement pst)
	{
		if(pst != null)
		{
			try{pst.close();}
			catch (SQLException e) {e.printStackTrace();}
				
		}
	}
	
	public static void closeResultSetConnection(ResultSet rs)
	{
		if(rs != null)
		{
			try
			{rs.close();}
			catch (SQLException e) {e.printStackTrace();}
		}
	}

}
