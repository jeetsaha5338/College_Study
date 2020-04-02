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
import com.projname.model.DoctorInfo;

@WebServlet("/Enable")
public class Enable extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public Enable() {
        super();
        // TODO Auto-generated constructor stub
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		
		String Uname=request.getParameter("Enab");
		
		//PrintWriter out= response.getWriter();//getWriter() creates the object of PrintWriter class
		
		DoctorDAOClass dbobj =new DoctorDAOClass();
		ArrayList<DoctorInfo> patList = dbobj.fetchAllRecord();
		//for each loop
		for(DoctorInfo ob :patList)
		{
				if(Uname.equals(ob.getDemail()))
				{
					DoctorDAOClass daobj=new DoctorDAOClass();
				
					daobj.enableDoctor(ob);
					request.setAttribute("done", "1");
					RequestDispatcher rd = request.getRequestDispatcher("DisplayAll.jsp");
					rd.forward(request, response);
				}
				//Update Code
					//out.println("LOGIN SUCCESSFUL");//prints the output to clients browser by the PrintWriter class
				
					
				//out.println("INVALID USERNAME OR PASSWORD");
		}
		request.setAttribute("errmsg", "1");
		RequestDispatcher rd = request.getRequestDispatcher("DisplayAll.jsp");
		rd.forward(request, response);
		
			/*request.setAttribute("errmsg", "2");
			RequestDispatcher rd = request.getRequestDispatcher("login.jsp");// RequestDispatcher interface create connection b/w the servlet & jsp
			rd.forward(request, response);*/

	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
