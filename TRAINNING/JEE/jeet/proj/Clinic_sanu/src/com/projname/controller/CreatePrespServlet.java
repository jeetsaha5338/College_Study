package com.projname.controller;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import com.projname.dao.PrespDAOClass;
import com.projname.model.PrescriptionInfo;


@WebServlet("/CreatePrespServlet")
public class CreatePrespServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public CreatePrespServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		PrescriptionInfo pob=new PrescriptionInfo();
		pob.setDocId(request.getParameter("DocId"));
		pob.setPid(request.getParameter("Pid"));
		pob.setMname1(request.getParameter("Mname1"));
		pob.setMdose1(request.getParameter("Mdose1"));
		pob.setMdur1(request.getParameter("Mdur1"));
		pob.setMname2(request.getParameter("Mname2"));
		pob.setMdose2(request.getParameter("Mdose2"));
		pob.setMdur2(request.getParameter("Mdur2"));
		pob.setPtest1(request.getParameter("Ptest1"));
		pob.setPtest2(request.getParameter("Ptest2"));
		
		PrespDAOClass daobj=new PrespDAOClass();
		
		boolean f1=daobj.insertMedicineData(pob);
		boolean f2=daobj.insertPathologyData(pob);
		
		if(f1 && f2)
		{
			request.setAttribute("info", pob);
			request.setAttribute("success", "PRESCRIPTION");
			RequestDispatcher rd = request.getRequestDispatcher("Prescription.jsp");
			rd.forward(request, response);
			System.out.println("Inserted");
		}
		else
		{
			request.setAttribute("errmsg", "PRESCRIPTION NOT CREATED");
			RequestDispatcher rd = request.getRequestDispatcher("CreatePrescription.jsp");
			rd.forward(request, response);
			System.out.println("Not Inserted");
		}
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
