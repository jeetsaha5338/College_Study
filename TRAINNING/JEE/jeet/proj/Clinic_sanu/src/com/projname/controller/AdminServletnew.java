package com.projname.controller;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;



JPanel a = new J

@WebServlet("/AdminServletnew")
public class AdminServletnew extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
   
    public AdminServletnew() {
        super(); 
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String Aname=request.getParameter("Aname");
		String Apass=request.getParameter("Apass");
		
		//PrintWriter out= response.getWriter();//getWriter() creates the object of PrintWriter class
		
		/*DAOClass dbobj =new DAOClass();
		ArrayList<StudentPersonalInfo> stdList = dbobj.fetchAllRecord();*/
		
		
			if(Aname.equalsIgnoreCase("admin"))
			{
				
				if(Apass.equalsIgnoreCase("admin"))
				{
					//request.setAttribute("info", ob);
					RequestDispatcher rd = request.getRequestDispatcher("AdminAfterLogin.jsp");
					rd.forward(request, response);
				}	//out.println("LOGIN SUCCESSFUL");//prints the output to clients browser by the PrintWriter class
				else
				{
					request.setAttribute("errmsg", "1");
					RequestDispatcher rd = request.getRequestDispatcher("AdminLogin.jsp");
					rd.forward(request, response);
				}//out.println("INVALID USERNAME OR PASSWORD");
					
			}
			
		
		
		
			request.setAttribute("errmsg", "1");
			RequestDispatcher rd = request.getRequestDispatcher("AdminLogin.jsp");// RequestDispatcher interface create connection b/w the servlet & jsp
			rd.forward(request, response);
		
		
		
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
