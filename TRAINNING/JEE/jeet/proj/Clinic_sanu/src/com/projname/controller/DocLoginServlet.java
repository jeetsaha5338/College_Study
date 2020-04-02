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

import com.projname.dao.DoctorDAOClass;
import com.projname.dao.PatientDAOClass;
import com.projname.model.DoctorInfo;
import com.projname.model.PatientInfo;

@WebServlet("/DocLoginServlet")
public class DocLoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DocLoginServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String Uname=request.getParameter("Demail");
		String Upass=request.getParameter("Dpass");
		
		//PrintWriter out= response.getWriter();//getWriter() creates the object of PrintWriter class
		
		DoctorDAOClass dbobj =new DoctorDAOClass();
		System.out.println(Uname +  "  "+Upass);
		
		DoctorInfo docobj = dbobj.LoginCheck(Uname,Upass);
		System.out.println(docobj.getEnable());
		if(docobj.getEnable().equalsIgnoreCase("invalid"))
		{
			//WRONG PASSWORD OR USERID
			request.setAttribute("errmsg", "WRONG PASSWORD OR USERID");
			RequestDispatcher rd = request.getRequestDispatcher("DocLogin.jsp");
			rd.forward(request, response);
		}
		else if(docobj.getEnable().equalsIgnoreCase("false"))
		{
			//Authorise not
			request.setAttribute("errmsg1", "Authorise not");
			RequestDispatcher rd = request.getRequestDispatcher("DocLogin.jsp");
			rd.forward(request, response);
		}
		else
		{
			HttpSession session = request.getSession(true);
			session.setAttribute("demail", docobj.getDemail());
			request.setAttribute("info", docobj);
			RequestDispatcher rd = request.getRequestDispatcher("AfterDocLogin.jsp");
			rd.forward(request, response);
			//VALID
		}
		//for each loop
		
				
			
}
		
		
			/*request.setAttribute("errmsg", "2");
			RequestDispatcher rd = request.getRequestDispatcher("login.jsp");// RequestDispatcher interface create connection b/w the servlet & jsp
			rd.forward(request, response);*/
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
