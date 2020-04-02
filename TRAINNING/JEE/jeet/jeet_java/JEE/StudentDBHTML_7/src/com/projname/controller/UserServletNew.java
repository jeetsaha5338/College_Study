package com.projname.controller;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.projname.dao.DAOClass;
import com.projname.model.StudentPersonalInfo;


@WebServlet("/UserServletNew")
public class UserServletNew extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
    public UserServletNew() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
		String Uname=request.getParameter("Uname");
		
		//PrintWriter out= response.getWriter();//getWriter() creates the object of PrintWriter class
		
		DAOClass dbobj =new DAOClass();
		ArrayList<StudentPersonalInfo> stdList = dbobj.fetchAllRecord();
		//for each loop
		for(StudentPersonalInfo ob :stdList)
		{
			if(Uname.equals(ob.getStname()))
			{
				request.setAttribute("info", ob);
				RequestDispatcher rd = request.getRequestDispatcher("DisplayProfile.jsp");
				rd.forward(request, response);
			}			
		}
		request.setAttribute("errmsg", "2");
		RequestDispatcher rd = request.getRequestDispatcher("UID.jsp");// RequestDispatcher interface create connection b/w the servlet & jsp
		rd.forward(request, response);
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}