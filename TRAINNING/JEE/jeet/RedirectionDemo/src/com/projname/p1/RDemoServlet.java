package com.projname.p1;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/RDemoServlet")
public class RDemoServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public RDemoServlet() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		//response.getWriter().append("Served at: ").append(request.getContextPath());
		String s1 = request.getParameter("t1");
		if(s1.equals("abc"))
		{
			response.sendError(response.SC_CONFLICT);
		}
		else
			//System.out.println("valid");
			response.sendRedirect("SecondServlet?key=JEET&key1=SAHA");
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
