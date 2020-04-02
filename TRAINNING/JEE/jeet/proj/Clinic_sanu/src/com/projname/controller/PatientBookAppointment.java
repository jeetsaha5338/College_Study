package com.projname.controller;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.projname.dao.PatientBookAppointmentDAOClass;
import com.projname.model.PatientAppointment;

@WebServlet("/PatientBookAppointment")
public class PatientBookAppointment extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public PatientBookAppointment() {
        super();
        // TODO Auto-generated constructor stub
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		PatientAppointment sobj = new PatientAppointment();
		
		sobj.setDemail(request.getParameter("Demail"));
		sobj.setDate(request.getParameter("Date"));
		sobj.setPemail(request.getParameter("Pemail"));
		
		PatientBookAppointmentDAOClass daobj = new PatientBookAppointmentDAOClass();
		
		boolean f=daobj.insertData(sobj);
		if(f)
		{
			//request.setAttribute("info", sobj);
			//request.setAttribute("success", "RECORD INSERTED");
			//RequestDispatcher rd = request.getRequestDispatcher("Display.jsp");
			//rd.forward(request, response);
		System.out.println("RECORD INSERTED");
		}
		else
		{
			//request.setAttribute("errmsg", "RECORD NOT INSERTED");
			//RequestDispatcher rd = request.getRequestDispatcher("RegPage.jsp");
			//rd.forward(request, response);
		System.out.println("RECORD NOT INSERTED");
		}

	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
