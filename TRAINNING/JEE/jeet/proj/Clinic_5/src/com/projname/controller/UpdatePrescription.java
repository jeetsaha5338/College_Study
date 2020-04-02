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
import javax.websocket.Session;

import com.projname.dao.PrespDAOClass;
import com.projname.model.PrescriptionInfo;

/**
 * Servlet implementation class UpdatePrescription
 */
@WebServlet("/UpdatePrescription")
public class UpdatePrescription extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UpdatePrescription() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PrescriptionInfo pob=new PrescriptionInfo();
		
		
		PrespDAOClass dbobj = new PrespDAOClass();
		pob.setMname1(request.getParameter("Mname1"));
		pob.setMdose1(request.getParameter("Mdose1"));
		pob.setMdur1(request.getParameter("Mdur1"));
		pob.setMname2(request.getParameter("Mname2"));
		pob.setMdose2(request.getParameter("Mdose2"));
		pob.setMdur2(request.getParameter("Mdur2"));
		pob.setPid(request.getParameter("Pid"));
			boolean f = dbobj.updateData(pob);
			if(f)
			{
				System.out.println("RECORD UPDATED");
				request.setAttribute("info", pob);
				RequestDispatcher rd = request.getRequestDispatcher("UpdatePrescription.jsp");
				rd.forward(request, response);
			}
				
			else
			{
				request.setAttribute("errmsg", "invalid1");
				RequestDispatcher rd = request.getRequestDispatcher("RequestedPrescription.jsp");
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
