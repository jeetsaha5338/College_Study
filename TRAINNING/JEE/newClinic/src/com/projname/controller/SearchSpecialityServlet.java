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



@WebServlet("/SearchSpecialityServlet")
public class SearchSpecialityServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
    public SearchSpecialityServlet() {
        super();
        
    }

	
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    	
		String Uname=request.getParameter("Dspec");
		
		//PrintWriter out= response.getWriter();//getWriter() creates the object of PrintWriter class
		DoctorDAOClass dbobj =new DoctorDAOClass();
		ArrayList<DoctorInfo> docList = dbobj.fetchAllRecord();
		ArrayList<DoctorInfo> dobj = new ArrayList<DoctorInfo>();
		int flag = 0;
		
		//for each loop
		for(DoctorInfo ob :docList)
		{
			if(Uname.equalsIgnoreCase(ob.getDspec()))
			{
				if(ob.getEnable().equalsIgnoreCase("true"))
				{
					dobj.add(ob);
					flag=1;
				}
			}
		//out.println("LOGIN SUCCESSFUL");//prints the output to clients browser by the PrintWriter class
			
		}
		if(flag==1)
		{	
			request.setAttribute("info", dobj);
			RequestDispatcher rd = request.getRequestDispatcher("DisplayDoc.jsp");
			rd.forward(request, response);
		}
		request.setAttribute("errmsg", "2");
		RequestDispatcher rd = request.getRequestDispatcher("SearchSpeciality.jsp");// RequestDispatcher interface create connection b/w the servlet & jsp
		rd.forward(request, response);
		
		
			
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
