package com.projname.controller;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.projname.dao.DoctorDAOClass;
import com.projname.model.DoctorInfo;

/**
 * Servlet implementation class UpdateDoc
 */
@WebServlet("/UpdateDoc")
public class UpdateDoc extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UpdateDoc() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		DoctorInfo dob=new DoctorInfo();
		
		DoctorDAOClass dobj=new DoctorDAOClass();
		
		dob.setDemail(request.getParameter("Demail"));
		dob.setDfees(request.getParameter("Dfees"));
		dob.setDmob(request.getParameter("Dmob"));
		dob.setDpno(request.getParameter("Dpno"));
		dob.setDspec(request.getParameter("Dspec"));
		dob.setDtime(request.getParameter("Dtime"));
		dob.setExp(request.getParameter("Exp"));
		dob.setQual(request.getParameter("Qual"));
		dob.setDpass(request.getParameter("Dpass"));
		
		boolean f = dobj.updateData(dob);
		if(f)
		{
			System.out.println("RECORD UPDATED");
			request.setAttribute("info", dob);
			RequestDispatcher rd = request.getRequestDispatcher("UpdatedDocProfile.jsp");
			rd.forward(request, response);
		}
			
		else
		{
			request.setAttribute("errmsg", "invalid1");
			RequestDispatcher rd = request.getRequestDispatcher("UpdateDocInfo.jsp");
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
