<%@page import="com.projname.model.PatientAppointment"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Patient_View_Appointment</title>
</head>
<body style="background-color: silver;">
<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
<hr color="blue" width="100%" size="3">
	

<br/><br/><br/><br/><br/>
	<div align="center">
	
		<table border="1">
			<tr>
				<td>&nbsp;&nbsp;  Patient ID  &nbsp;&nbsp;</td>
				<td>&nbsp;</td>
				<td>&nbsp;&nbsp;  Appointment Date  &nbsp;&nbsp;</td>
				<td>&nbsp;</td>
				<td>&nbsp;&nbsp;  Doctor's ID  &nbsp;&nbsp;</td>
			</tr>
			
			<%
				ArrayList<PatientAppointment> obj=(ArrayList<PatientAppointment>)request.getAttribute("info");
			
				for (PatientAppointment ob :obj )
				{
			
			%>
			<tr>
				<td align="center"> <%=ob.getPemail() %> </td>
				<td>&nbsp;</td>
				<td align="center"> <%=ob.getDemail() %> </td>
				<td>&nbsp;</td>
				<td align="center"> <%=ob.getDate() %> </td>
			</tr>
			<%} %>
		</table>
		<br/><br/><br/><br/><br/>
		 <a href="PatientAfterLogin.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
		 TO GO PATIENT HOME
	</div>

</body>
</html>