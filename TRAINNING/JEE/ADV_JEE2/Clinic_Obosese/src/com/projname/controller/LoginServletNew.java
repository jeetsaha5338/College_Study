package com.projname.controller;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.projname.dao.PatientDAOClass;
import com.projname.model.PatientInfo;



@WebServlet("/LoginServletNew")
public class LoginServletNew extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
    public LoginServletNew() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
		String Uname=request.getParameter("Pemail");
		String Upass=request.getParameter("Ppass");
		
		//PrintWriter out= response.getWriter();//getWriter() creates the object of PrintWriter class
		
		PatientDAOClass dbobj =new PatientDAOClass();
		ArrayList<PatientInfo> patList = dbobj.fetchAllRecord();
		//for each loop
		for(PatientInfo ob :patList)
		{
			if(Uname.equals(ob.getPemail()))
			{
				
				if(Upass.equals(ob.getPpass()))
				{
					HttpSession session = request.getSession(true);
					session.setAttribute("pemail", ob.getPemail());
					session.setAttribute("pname", ob.getPname());
					
					request.setAttribute("info", ob);
					RequestDispatcher rd = request.getRequestDispatcher("PatientAfterLogin.jsp");
					rd.forward(request, response);
				}	//out.println("LOGIN SUCCESSFUL");//prints the output to clients browser by the PrintWriter class
				else
				{
					request.setAttribute("errmsg", "1");
					RequestDispatcher rd = request.getRequestDispatcher("PatientLogin.jsp");
					rd.forward(request, response);
				}//out.println("INVALID USERNAME OR PASSWORD");
					
			}
			
		}
		
		
			request.setAttribute("errmsg", "2");
			RequestDispatcher rd = request.getRequestDispatcher("PatientLogin.jsp");// RequestDispatcher interface create connection b/w the servlet & jsp
			rd.forward(request, response);
		
		
		
			
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
