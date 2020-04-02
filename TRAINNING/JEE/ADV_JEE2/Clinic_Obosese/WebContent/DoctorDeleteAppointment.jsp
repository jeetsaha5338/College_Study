<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body style="background-color: silver;">
<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
	<hr color="blue" width="100%" size="3">
	</br>
	<div align=center style=" font-size: 35PX; font-family:monospace;">DELETE APPOINTMENT
	</div><br/><br/>

<%! String doctor=""; %>
<%
   doctor=(String)session.getAttribute("demail");
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
	<form action="DoctorDeleteAppointment">
		
		<table>
			<tr>
				<td>Patient ID</td>
				<td>&nbsp;</td>
				<td> <input type="email" placeholder="Enter patient E-MAIL" name="Pemail" required> </td>
			</tr>
			<tr>
				<td>Enter Doctor ID</td>
				<td>&nbsp;</td>
				<td> <input type="email" name="doctor" value=<%=doctor %> readonly="readonly"> </td>
			</tr>
			
			<tr>
				<td>Enter Date</td>
				<td>&nbsp;</td>
				<td> <input type="date" name="Date" required> </td>
			</tr>
		</table>
		
		<input type="submit" value="Delete Appointment">
		<br/>	<br/>	<br/>
		
		<a href="AfterDocLogin.jsp">GO TO DOCTOR HOME</a>
	</form>

</div>
</body>
</html>