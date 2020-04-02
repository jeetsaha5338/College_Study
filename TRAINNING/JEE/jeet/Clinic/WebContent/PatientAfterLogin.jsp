<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%! String patient=""; %>
<%
   patient=(String)session.getAttribute("pemail");
%>

	<div align="center">
	<a href="SearchDoc.jsp">SEARCH DOCTOR</a><br/><br/>
	
	
	<a href="PatientViewPrescription.jsp">VIEW PRESCRIPTION</a><br/><br/>
	
	
	
	<a href="PatientViewTest.jsp">VIEW TESTS</a><br/><br/>
	
	
	
	<a href="PatientViewAppointment?patient=<%=patient%>">VIEW APPOINTMENT</a><br/><br/>
	
	
	
	<a href="PatientDeleteAppointment.jsp">DELETE APPOINTMENT</a><br/><br/><br/><br/>
	
	<a href="Home.jsp">GO TO HOME</a>
	</div>
</body>
</html>








