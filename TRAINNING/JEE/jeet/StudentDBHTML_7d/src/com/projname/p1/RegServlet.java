package com.projname.p1;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/RegServlet")
public class RegServlet extends HttpServlet {
	//String Hobby="";
		private static final long serialVersionUID = 1L;
       
    
    public RegServlet() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String Stname=request.getParameter("Stname");
		String Stemail=request.getParameter("Stemail");
		String Stdob=request.getParameter("Stdob");
		String Stpass=request.getParameter("Stpass");
		String Stcountry=request.getParameter("Stcountry");
		String Hobby[]=request.getParameterValues("hobby");
		String Gender[]=request.getParameterValues("gender");
		int Stmob=Integer.parseInt(request.getParameter("Stmob"));
		
	
		System.out.println("NAME :" +Stname);
		System.out.println("EMAIL :" +Stemail);
		System.out.println("MOB. NO. :" +Stmob);
		System.out.println("DOB :" +Stdob);
		System.out.println("PASSWORD :" +Stpass);
		System.out.print("GENDER :");
		for(String value:Gender)
		{
			System.out.println(value);
		}
		System.out.print("HOBBY :");
		for(String value:Hobby)
		{
			System.out.println(value);
		}
		System.out.println("COUNTRY :" +Stcountry);
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}
}
