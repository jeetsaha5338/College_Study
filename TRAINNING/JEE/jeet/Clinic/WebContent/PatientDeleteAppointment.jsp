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
	<%
		if(request.getAttribute("errmsg")=="0")
		{
			out.println("Record Deleted");
		}
		if(request.getAttribute("errmsg")=="1")
		{
			out.println("Record NOT Deleted");
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
		 <a href="PatientAfterLogin.jsp">GO TO PATIENT HOME</a>
</div>
</body>
</html>