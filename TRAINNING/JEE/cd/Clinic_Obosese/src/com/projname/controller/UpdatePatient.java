package com.projname.controller;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.projname.dao.DoctorDAOClass;
import com.projname.dao.PatientDAOClass;
import com.projname.model.DoctorInfo;
import com.projname.model.PatientInfo;

/**
 * Servlet implementation class UpdatePatient
 */
@WebServlet("/UpdatePatient")
public class UpdatePatient extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UpdatePatient() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PatientInfo dob=new PatientInfo();
		
		PatientDAOClass dobj=new PatientDAOClass();
		
		dob.setPemail(request.getParameter("Pemail"));
		dob.setPmob(request.getParameter("Pmob"));
		dob.setPpass(request.getParameter("Ppass"));
		dob.setAge(request.getParameter("Age"));
		dob.setGender(request.getParameter("gender"));
		boolean f = dobj.updateData(dob);
		if(f)
		{
			System.out.println("RECORD UPDATED");
			request.setAttribute("info", dob);
			RequestDispatcher rd = request.getRequestDispatcher("UpdatedPatientProfile.jsp");
			rd.forward(request, response);
		}
			
		else
		{
			request.setAttribute("errmsg", "invalid1");
			RequestDispatcher rd = request.getRequestDispatcher("UpdatePatientInfo.jsp");
			rd.forward(request, response);
			System.out.println("RECORD NOT UPDATED");
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
