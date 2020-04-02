package com.projname.p1;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/AddServ")
public class AddServ extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public AddServ() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		//response.getWriter().append("Served at: ").append(request.getContextPath());
		int fno=Integer.parseInt(request.getParameter("fno"));//system defined object "request", "getParameter()" is used to take i/p from client
		int sno=Integer.parseInt(request.getParameter("sno"));// name written in html must same as the parameter i.e. case sensetive
		
		System.out.println("SUM IS :" +(fno+sno));
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
