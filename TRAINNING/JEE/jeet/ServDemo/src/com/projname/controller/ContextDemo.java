package com.projname.controller;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class ContextDemo extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public ContextDemo() {
        super();
       
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		//response.getWriter().append("Served at: ").append(request.getContextPath());
		response.setContentType("text/html");
		
		PrintWriter out = response.getWriter();
		
		ServletContext context = getServletContext();
		
		context.setAttribute("STOCKINFO", "500");
		
		String s1=context.getInitParameter("n1");
		String s2=context.getInitParameter("n2");
		
		out.println("Userb ID is:"+s1+" "+"And Password is:"+s2);
		out.print("<br/>");
		out.println("<a href= ServletContextDemo.jsp>CLICK ME</a>");
		
		out.close();
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
