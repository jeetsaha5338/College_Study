<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%@page import="java.util.ArrayList"%>
    <%@page import="com.projname.model.PrescriptionInfo"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
	<h1 style="color: navy;">PRESCRIPTION DETAILS</h1>
		
		
	<div align="center">
	<h1>UPDATED PRESCRIPTION</h1>
			<h1>MEDICINE DETAILS</h1>
			<table border="1">
				<tr>
					<th>Medicine Name 1</th>
					<td>&nbsp;</td>
					<th>Dosage 1</th>
					<td>&nbsp;</td>
					<th>Duration 1</th>
					<td>&nbsp;</td>
					<th>Medicine Name 2</th>
					<td>&nbsp;</td>
					<th>Dosage 2</th>
					<td>&nbsp;</td>
					<th>Duration 2</th>
					<td>&nbsp;</td>
					<th>Patient Id</th>
					<td>&nbsp;</td>
					<th>Doctor Id</th>
			</tr>
			<%
		
		PrescriptionInfo ob=(PrescriptionInfo)request.getAttribute("info");

		%>
		<tr>
			<td align="center"><%= ob.getMname1() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getMdose1() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getMdur1() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getMname2() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getMdose2() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getMdur2() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getPid() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getDocId() %></td>
		</tr>
	</table>
			
</body>
</html>





			