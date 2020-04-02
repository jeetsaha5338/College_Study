package com.projname.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;



public class DBConnect 
{
	public static Connection getMySQLConnection() //throws ClassNotFoundException,SQLException
	{
		Connection con =null;
		try
		{
			//ClassNotFoundException
			Class.forName("com.mysql.jdbc.Driver");//load and register driver, 
			//establish connection
			//SQLException
			con = DriverManager.getConnection("jdbc:mysql://localhost:3306/clinic","root","sanu..1996");
			
		}catch (ClassNotFoundException e) {System.out.println(e);}
		catch (SQLException e) {System.out.println(e);}
		return con;
	}
	public static void closeMySQLConnectiion(Connection con)
	{
		if(con !=null)
		{
			try
			{
				con.close();
			}catch (SQLException e){e.printStackTrace();}
		}
	}
	public static void closePreparedStatementConnection(PreparedStatement pst)
	{
		if(pst !=null)
		{
			try
			{
				pst.close();
			}catch (SQLException e){e.printStackTrace();}
		}
	}
	public static void closeResultSetConnectiion(ResultSet rs)
	{
		if(rs !=null)
		{
			try
			{
				rs.close();
			}catch (SQLException e){e.printStackTrace();}
		}
	}
}
