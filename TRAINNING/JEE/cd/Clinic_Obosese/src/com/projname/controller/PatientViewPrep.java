package com.projname.controller;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import com.projname.dao.PrespDAOClass;

import com.projname.model.PrescriptionInfo;



@WebServlet("/PatientViewPrep")
public class PatientViewPrep extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
    public PatientViewPrep() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		String Uname;
		Uname = request.getParameter("patient");
		
		
		PrespDAOClass dbobj = new PrespDAOClass();
		
		ArrayList<PrescriptionInfo> stdList = dbobj.fetchMedicineRecord();
		//ArrayList<PrescriptionInfo> stdList1 = dbobj.fetchPathologyRecord();
		ArrayList<PrescriptionInfo> dobj = new ArrayList<PrescriptionInfo>();
	//	ArrayList<PrescriptionInfo> dobj1 = new ArrayList<PrescriptionInfo>();
		//for each loop
		int flag=0;
		for(PrescriptionInfo sobj :stdList)
		{
			if(Uname.equals(sobj.getPid()))
			{
				dobj.add(sobj);
				flag=1;		
			}
				
		}
		/*for(PrescriptionInfo sobj1 :stdList1)
		{
			if(Uname.equals(sobj1.getPid()))
			{
				dobj1.add(sobj1);
				flag=1;
			}
		}*/
		

		if(flag==1)
		{
			request.setAttribute("info", dobj);
			//request.setAttribute("info1", dobj1);
			RequestDispatcher rd = request.getRequestDispatcher("PatientViewPrescription.jsp");
			rd.forward(request, response);
		}
		else
		{
			request.setAttribute("errmsg", "invalid1");
			RequestDispatcher rd = request.getRequestDispatcher("PatientAfterLogin.jsp");
			rd.forward(request, response);
		}
		
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}















/*package com.projname.controller;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/PatientViewPrep")
public class PatientViewPrep extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public PatientViewPrep() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}*/
