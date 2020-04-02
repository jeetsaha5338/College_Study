package com.projname.controller;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import com.projname.dao.DoctorDAOClass;
import com.projname.model.DoctorInfo;



@WebServlet("/UserDel")
public class UserDel extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
    public UserDel() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
		String Uemail=request.getParameter("Uemail");
		
		//PrintWriter out= response.getWriter();//getWriter() creates the object of PrintWriter class
		
		DoctorDAOClass dbobj =new DoctorDAOClass();
		ArrayList<DoctorInfo> docList = dbobj.fetchAllRecord();
		//for each loop
		for(DoctorInfo ob :docList)
		{
			if(Uemail.equals(ob.getDemail()))
			{
				
				DoctorDAOClass daobj=new DoctorDAOClass();
				
				boolean f=daobj.deleteData(ob);
				
				if(f)
				{
					request.setAttribute("errmsg", "0");
					RequestDispatcher rd = request.getRequestDispatcher("Admin.jsp");
					rd.forward(request, response);
				}
				else
				{
					request.setAttribute("errmsg", "1");
					RequestDispatcher rd = request.getRequestDispatcher("Admin.jsp");
					rd.forward(request, response);
				}	
			}
				
		}
		request.setAttribute("errmsg", "2");
		RequestDispatcher rd = request.getRequestDispatcher("UserDelete.jsp");// RequestDispatcher interface create connection b/w the servlet & jsp
		rd.forward(request, response);
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}