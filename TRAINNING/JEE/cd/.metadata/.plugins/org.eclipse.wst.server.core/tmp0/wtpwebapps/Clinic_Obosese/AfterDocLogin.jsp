
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>After_doc_login</title>
</head>
<body style="background-color: silver;">
<h1 align="CENTER" style="color: blue; font-size: 75PX; font-family: monospace;">
		RECUPERATION CLINIC
	</h1>
		
	<hr color="green" width="100%" size="5">
	
<div align="center">
<marquee behavior="alternate" style="color: black;">For Doctors Use Only!!! For Doctors Use Only!!!</marquee>
<br/>	<br/><br/>	<br/>	
	<%! String doctor=""; %>
<%
   doctor=(String)session.getAttribute("demail");
%>
	
	<a href="DoctorViewAppointment?doctor=<%=doctor%>">VIEW APPOINTMENT</a><br/><br/>
	
	<a href="DoctorDeleteAppointment.jsp">DELETE APPOINTMENT</a><br/><br/>
	
	<a href="CreatePrescription.jsp">CREATE PRESCRIPTION</a><br/><br/>
	
	<a href="DoctorViewPrescription.jsp">VIEW PRESCRIPTION</a><br/><br/>

	<a href="UpdateDocInfo.jsp">UPDATE PROFILE</a><br/><br/><br/><br/>
	
	<a href="Logout.jsp">CLIKC HERE</a>
	Logout
	
</div>	
	
</body>
</html>