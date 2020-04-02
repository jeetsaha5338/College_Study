<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%@page import="java.util.ArrayList"%>
    <%@page import="com.projname.model.PrescriptionInfo"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Patient_View_Prescription</title>
</head>
<body style="background-color: silver;">

<div align="center">
<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
	
	<hr color="blue" width="100%" size="3">
	<BR/>
<h1>MEDICINE DETAILS</h1>
	<table border="1">
		<tr>
					<th>MEDICINE 1</th>
					<td>&nbsp;</td>
					<th>DOSE</th>
					<td>&nbsp;</td>
					<th>DURATION</th>
					<td>&nbsp;</td>
					<td>&nbsp;</td>
					<th>MEDICINE 2</th>
					<td>&nbsp;</td>
					<th>DOSE</th>
					<td>&nbsp;</td>
					<th>DURATION</th>
					<td>&nbsp;</td>
					<td>&nbsp;</td>
					<th>Doctor Id</th>
			</tr>
			<%ArrayList<PrescriptionInfo> obj=(ArrayList<PrescriptionInfo>)request.getAttribute("info");
		
		for (PrescriptionInfo ob1 :obj )
		{ 
		%>
		<tr>
			<td align="center"><%= ob1.getMname1() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob1.getMdose1() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob1.getMdur1() %></td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td align="center"><%= ob1.getMname1() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob1.getMdose1() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob1.getMdur1() %></td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td align="center"><%= ob1.getDocId() %></td>
		</tr>
		<%} %>
		</table>


<br/><br/><br/><br/><br/>
		 <a href="PatientAfterLogin.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
		 TO GO PATIENT HOME
		 </div>
</body>
</html>