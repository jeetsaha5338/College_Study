package com.projname.controller;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.projname.dao.PatientBookAppointmentDAOClass;
import com.projname.model.PatientAppointment;


@WebServlet("/DoctorViewAppointment")
public class DoctorViewAppointment extends HttpServlet {
	private static final long serialVersionUID = 1L;
   
    public DoctorViewAppointment() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String email;
		email = request.getParameter("doctor");
		//PrintWriter out= response.getWriter();//getWriter() creates the object of PrintWriter class
		PatientBookAppointmentDAOClass dbobj =new PatientBookAppointmentDAOClass();
		ArrayList<PatientAppointment> docList = dbobj.viewRecordDoctor(email);
		//ArrayList<PatientAppointment> dobj = new ArrayList<PatientAppointment>();
		//int flag=0;
		
		//for each loop
				/*for(PatientAppointment ob :docList)
				{
					if(Uname.equalsIgnoreCase(ob.getDname()))
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
				}*/
				request.setAttribute("info", docList);
				RequestDispatcher rd = request.getRequestDispatcher("DoctorViewAppointment.jsp");// RequestDispatcher interface create connection b/w the servlet & jsp
				rd.forward(request, response);

	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
