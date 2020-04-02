<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Delete_Patient_Appointment</title>
</head>
<body style="background-color: silver;">
    <h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
	<hr color="blue" width="100%" size="3">
	<BR/>

<%! String patient=""; %>
<%
   patient=(String)session.getAttribute("pemail");
%>

<div align="center">
	<%
		if(request.getAttribute("errmsg")=="0")
		{
			out.println("Record Deleted");
			request.setAttribute("errmsg", "5");
		}
		if(request.getAttribute("errmsg")=="1")
		{
			out.println("Record NOT Deleted");
			request.setAttribute("errmsg", "5");
		}
		if(request.getAttribute("errmsg")=="2")
		{
			out.println("Record NOT Found");
			request.setAttribute("errmsg", "5");
		}
		//out.println(patient);
	%>
	<form action="PatientDeleteAppointment">
		
		<table>
			<tr>
				<td>Patient ID</td>
				<td>&nbsp;</td>
				<td> <input type="email" name="patient" value=<%=patient %> readonly="readonly"> </td>
			</tr>
			<tr>
				<td>Enter Doctor ID</td>
				<td>&nbsp;</td>
				<td> <input type="email" name="Demail" required> </td>
			</tr>
			
			<tr>
				<td>Enter Date</td>
				<td>&nbsp;</td>
				<td> <input type="date" name="Date" required> </td>
			</tr>
		</table>
		
		<input type="submit" value="Delete Appointment">
		
	</form>
<br/><br/><br/><br/><br/>
		 <a href="PatientAfterLogin.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
		 TO GO PATIENT HOME
</div>
</body>
</html>