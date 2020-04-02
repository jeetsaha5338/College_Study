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



@WebServlet("/DoctorRegServlet")
public class DoctorRegServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public DoctorRegServlet() {
        super();
      
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		DoctorInfo sobj=new DoctorInfo();
		sobj.setDname(request.getParameter("Dname"));
		sobj.setDemail(request.getParameter("Demail"));
		sobj.setDfees(request.getParameter("Dfees"));
		sobj.setDmob(request.getParameter("Dmob"));
		sobj.setDpno(request.getParameter("Dpno"));
		sobj.setDspec(request.getParameter("Dspec"));
		sobj.setDtime(request.getParameter("Dtime"));
		sobj.setExp(request.getParameter("Exp"));
		sobj.setQual(request.getParameter("Qual"));
		sobj.setReg(request.getParameter("Reg"));
		sobj.setDpass(request.getParameter("Dpass"));
		sobj.setEnable("false");
		
		
		DoctorDAOClass daobj=new DoctorDAOClass();
		
		boolean f=daobj.insertData(sobj);
		if(f)
		{
			//request.setAttribute("info", sobj);
			//request.setAttribute("success", "RECORD INSERTED");
			RequestDispatcher rd = request.getRequestDispatcher("DocLogin.jsp");
			rd.forward(request, response);
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
