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
import com.projname.dao.PatientBookAppointmentDAOClass;
import com.projname.model.DoctorInfo;
import com.projname.model.PatientAppointment;

@WebServlet("/TotalFees")
public class TotalFees extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public TotalFees() {
        super();
        // TODO Auto-generated constructor stub
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		PatientBookAppointmentDAOClass dbobj = new PatientBookAppointmentDAOClass();
		ArrayList<PatientAppointment> ob = dbobj.fetchAllRecord();
		int fees = 0;
		
		for(PatientAppointment pobj : ob)
		{
			DoctorDAOClass doc = new DoctorDAOClass();
			fees = fees + doc.findFees(pobj);
		}
		//System.out.println("Total --> " + fees);
		request.setAttribute("info", fees);
		RequestDispatcher rd = request.getRequestDispatcher("TotalFees.jsp");
		rd.forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
