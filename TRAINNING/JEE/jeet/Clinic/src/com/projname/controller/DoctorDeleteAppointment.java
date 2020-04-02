package com.projname.controller;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.websocket.Session;

import com.projname.dao.DoctorDAOClass;
import com.projname.dao.PatientBookAppointmentDAOClass;
import com.projname.model.DoctorInfo;
import com.projname.model.PatientAppointment;

@WebServlet("/DoctorDeleteAppointment")
public class DoctorDeleteAppointment extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public DoctorDeleteAppointment() {
        super();
        // TODO Auto-generated constructor stub
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String Pemail=request.getParameter("Pemail");
		String Date=request.getParameter("Date");
		String Demail = request.getParameter("doctor");
		//PrintWriter out= response.getWriter();//getWriter() creates the object of PrintWriter class
		System.out.println(Pemail);
		System.out.println(Demail);
		System.out.println(Date);
		PatientBookAppointmentDAOClass dbobj =new PatientBookAppointmentDAOClass();
		ArrayList<PatientAppointment> docList = dbobj.fetchAllRecord();
		//for each loop
		for(PatientAppointment ob : docList)
		{
			if(Demail.equals(ob.getDemail()) && Date.equals(ob.getDate()) && Pemail.equals(ob.getPemail()))
			{
				
				PatientBookAppointmentDAOClass daobj=new PatientBookAppointmentDAOClass();
				
				boolean f=daobj.deleteData(ob);
				
				if(f)
				{
					request.setAttribute("errmsg", "0");
					RequestDispatcher rd = request.getRequestDispatcher("DoctorDeleteAppointment.jsp");
					rd.forward(request, response);
				}
				else
				{
					request.setAttribute("errmsg", "1");
					RequestDispatcher rd = request.getRequestDispatcher("DoctorDeleteAppointment.jsp");
					rd.forward(request, response);
				}	
			}
				
		}
//		request.setAttribute("errmsg", "2");
	//	RequestDispatcher rd = request.getRequestDispatcher("UserDelete.jsp");// RequestDispatcher interface create connection b/w the servlet & jsp
		//rd.forward(request, response);
		
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}

//?patient=<%=patient%>,Demail=<%=Demail%>,Date=<%=Date%>
