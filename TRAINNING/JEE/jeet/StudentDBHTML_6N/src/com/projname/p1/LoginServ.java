package com.projname.p1;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/LoginServ")
public class LoginServ extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	RegServlet ob=new RegServlet();
    public LoginServ() {
        super();
        
    }

		protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
			String Uname=request.getParameter("Uname");
			String Upass=request.getParameter("Upass");
			if(Uname.equalsIgnoreCase("admin"))
			{
				if(Upass.equalsIgnoreCase("admin"))
					System.out.println("LOGIN SUCCESSFUL");
				else
					System.out.println("INVALID USERNAME OR PASSWORD");
			}
			else 
				System.out.println("INVALID USERNAME OR PASSWORD");
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
