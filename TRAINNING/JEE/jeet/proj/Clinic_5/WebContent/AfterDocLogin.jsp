
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%! String doctor=""; %>
<%
   doctor=(String)session.getAttribute("demail");
%>
	<div align="center">
	<br/><br/><br/><br/><br/><br/>
	<a href="DoctorViewAppointment?doctor=<%=doctor%>">VIEW APPOINTMENT</a><br/><br/>
	
	<a href="DoctorDeleteAppointment.jsp">DELETE APPOINTMENT</a><br/><br/>
	
	<a href="CreatePrescription.jsp">CREATE PRESCRIPTION</a><br/><br/>
	
	<a href="DoctorViewPrescription.jsp">VIEW PRESCRIPTION</a><br/><br/><br/><br/>
	
	<a href="Home.jsp">GO TO HOME</a>
	
	</div>
</body>
</html>