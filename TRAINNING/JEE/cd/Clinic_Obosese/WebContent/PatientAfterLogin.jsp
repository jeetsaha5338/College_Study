<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Patient_After_Login</title>
</head>
<body style="background-color: silver;">
<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
	<hr color="blue" width="100%" size="3">
	<div align="center">
<%! String patient=""; %>
<%
   patient=(String)session.getAttribute("pemail");
	
	if(request.getAttribute("success")!=null)
	{
		out.print(request.getAttribute("success"));
	}
%>
	</div>
	<div align="center">
	<BR/>
	<BR/>
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	<a href="SearchDoc.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
	TO SERACH DOCTOR
	<BR/>
	<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	<a href="PatientViewPrep?patient=<%=patient%>">VIEW PRESCRIPTION</a>&nbsp;&nbsp;&nbsp;
	TO VIEW PRESCRIPTION
	<br/>
	<BR/>
	<a href="PatientViewTest?patient=<%=patient%>">VIEW TESTS</a>&nbsp;&nbsp;&nbsp;
	TO VIEW TESTS
	<BR/>
	<BR/>
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	<a href="PatientViewAppointment?patient=<%=patient%>">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
	TO VIEW APPOINTMENT
	<BR/>
	<BR/>
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	<a href="PatientDeleteAppointment.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
	TO DELETE APPOINTMENT
	<br/>
	<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	<a href="UpdatePatientInfo.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
	TO UPDATE PROFILE<br/><br/><br/>
	
	<a href="Logout.jsp">CLIKC HERE</a>
	Logout
	
</body>
</html>

















