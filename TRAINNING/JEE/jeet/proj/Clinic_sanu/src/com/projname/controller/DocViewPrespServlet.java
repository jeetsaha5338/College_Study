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

import com.projname.dao.PrespDAOClass;

import com.projname.model.PrescriptionInfo;



@WebServlet("/DocViewPrespServlet")
public class DocViewPrespServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
    public DocViewPrespServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String Uname=request.getParameter("Pid");
		
		PrespDAOClass dbobj = new PrespDAOClass();
		PrescriptionInfo sobj2=new PrescriptionInfo();
		ArrayList<PrescriptionInfo> stdList = dbobj.fetchMedicineRecord();
		ArrayList<PrescriptionInfo> stdList1 = dbobj.fetchPathologyRecord();
		ArrayList<PrescriptionInfo> dobj = new ArrayList<PrescriptionInfo>();
		ArrayList<PrescriptionInfo> dobj1 = new ArrayList<PrescriptionInfo>();
		//for each loop
		int flag=0;
		for(PrescriptionInfo sobj :stdList)
		{
			if(Uname.equals(sobj.getPid()))
			{
				dobj.add(sobj);
				flag=1;		
				HttpSession session = request.getSession(true);
				session.setAttribute("med1", sobj.getMname1());
				session.setAttribute("med2", sobj.getMname2());
				session.setAttribute("dos1", sobj.getMdose1());
				session.setAttribute("dos2", sobj.getMdose2());
				session.setAttribute("dur1", sobj.getMdur1());
				session.setAttribute("dur2", sobj.getMdur2());
				session.setAttribute("pid", sobj.getPid());
			}
				
		}
		for(PrescriptionInfo sobj1 :stdList1)
		{
			if(Uname.equals(sobj1.getPid()))
			{
				dobj1.add(sobj1);
				flag=1;
			}
		}
		

		if(flag==1)
		{
			
			request.setAttribute("info", dobj);
			request.setAttribute("info1", dobj1);
			RequestDispatcher rd = request.getRequestDispatcher("RequestedPrescription.jsp");
			rd.forward(request, response);
		}
		else
		{
			request.setAttribute("errmsg", "invalid1");
			RequestDispatcher rd = request.getRequestDispatcher("DoctorViewPrescription.jsp");
			rd.forward(request, response);
		}
		
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
