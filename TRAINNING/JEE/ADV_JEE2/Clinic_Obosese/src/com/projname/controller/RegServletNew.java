package com.projname.controller;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import com.projname.dao.PatientDAOClass;
import com.projname.model.PatientInfo;



@WebServlet("/RegServletNew")
public class RegServletNew extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public RegServletNew() {
        super();
        
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PatientInfo sobj=new PatientInfo();
	
		
		sobj.setPname(request.getParameter("Pname"));
		sobj.setPemail(request.getParameter("Pemail"));
		sobj.setPmob(request.getParameter("Pmob"));
		sobj.setAge(request.getParameter("Age"));
		sobj.setGender(request.getParameter("gender"));
		sobj.setPpass(request.getParameter("Ppass"));
		
		
		
		PatientDAOClass daobj=new PatientDAOClass();
		
		boolean f=daobj.insertData(sobj);
		if(f)
		{
			request.setAttribute("info", sobj);
			request.setAttribute("Success", "RECORD INSERTED");
			RequestDispatcher rd = request.getRequestDispatcher("PatientLogin.jsp");
			rd.forward(request, response);
		}//System.out.println("RECORD INSERTED");
		else
		{
			request.setAttribute("errmsg", "RECORD NOT INSERTED");
			RequestDispatcher rd = request.getRequestDispatcher("RegPage.jsp");
			rd.forward(request, response);
		}	//System.out.println("RECORD NOT INSERTED");	
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
