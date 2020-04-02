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

<div align="center">

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
		 <a href="PatientAfterLogin.jsp">GO TO PATIENT HOME</a>
		 </div>
</body>
</html>