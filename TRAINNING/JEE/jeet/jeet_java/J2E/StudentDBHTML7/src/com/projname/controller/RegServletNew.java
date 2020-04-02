package com.projname.controller;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.projname.dao.DAOClass;
import com.projname.model.StudentPersonalInfo;


@WebServlet("/RegServletNew")
public class RegServletNew extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    String hobby1;
    String hobby2;
    String hobby;
    public RegServletNew() {
        super();
        
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		StudentPersonalInfo sobj=new StudentPersonalInfo();
		String Stname=request.getParameter("Stname");
		sobj.setStname(Stname);
		
		sobj.setStemail(request.getParameter("Stemail"));
		sobj.setStmob(request.getParameter("Stmob"));
		sobj.setStdob(request.getParameter("Stdob"));
		sobj.setStpass(request.getParameter("Stpass"));
		sobj.setGender(request.getParameter("gender"));
		sobj.setHobby1(request.getParameter("hobby1"));
		sobj.setHobby2(request.getParameter("hobby2"));
		sobj.setStcountry(request.getParameter("Stcountry"));
		
		
		if(sobj.getHobby1()!=null && sobj.getHobby2()!=null)
		{
			this.hobby1=sobj.getHobby1();
			this.hobby2=sobj.getHobby2();
			hobby=this.hobby1+","+this.hobby2;
			sobj.setHobby(hobby);
		}
		else if(sobj.getHobby1()!=null)
		{
			this.hobby1=sobj.getHobby1();
			hobby=this.hobby1;
			sobj.setHobby(hobby);
		}	
		else if(sobj.getHobby2()!=null)
		{
			this.hobby2=sobj.getHobby2();
			hobby=this.hobby2;
			sobj.setHobby(hobby);
		}
		
		DAOClass daobj=new DAOClass();
		
		boolean f=daobj.insertData(sobj);
		if(f)
		{
			request.setAttribute("info", sobj);
			request.setAttribute("success", "RECORD INSERTED");
			RequestDispatcher rd = request.getRequestDispatcher("Display.jsp");
			rd.forward(request, response);
		}//System.out.println("RECORD INSERTED");
		else
		{
			request.setAttribute("errmsg", "RECORD NOT INSERTED");
			RequestDispatcher rd = request.getRequestDispatcher("RegPage.jsp");
			rd.forward(request, response);
		}	//System.out.println("RECORD NOT INSERTED");
		
		
		
		
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
