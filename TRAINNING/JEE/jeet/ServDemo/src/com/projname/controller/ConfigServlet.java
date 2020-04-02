package com.projname.controller;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class ConfigServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
   
    public ConfigServlet() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		//response.getWriter().append("Served at: ").append(request.getContextPath());
		PrintWriter pw= response.getWriter();
		
		ServletConfig sconfig = getServletConfig();
		
		String s1 = sconfig.getInitParameter("userid");
		String s2 = sconfig.getInitParameter("pass");
		
		pw.println("Userb ID is:"+s1+" "+"And Password is:"+s2);
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
