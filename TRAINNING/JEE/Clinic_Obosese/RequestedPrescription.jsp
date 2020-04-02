<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%@page import="java.util.ArrayList"%>
    <%@page import="com.projname.model.PrescriptionInfo"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Requested_Prescription</title>
</head>
<body style="background-color: silver;">

	<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
		
	<hr color="blue" width="100%" size="3">
	<BR/>
	
	<div align="center">
		<h1 style="color: navy;">PRESCRIPTION DETAILS</h1>
		<div align="center"><h1>MEDICINE DETAILS</h1><h3>
		(UPDATE THE MEDICINES IF REQUIRED)</h3></div>
		<form action="UpdatePrescription">
		<table >
		<%
		String email = (String)session.getAttribute("pid");
		%>
			<tr>
			<td>Patient. Id.</td>
			<td>&nbsp;</td>
			<td><input type="email" value="<%=email %>" name="Pid" readonly="readonly"></td>
			</tr>
			</table>
	<table border="1">
	<%
	 		String med1 = (String)session.getAttribute("med1");
			String med2 = (String)session.getAttribute("med2");
			String dos1 = (String)session.getAttribute("dos1");
			String dos2 = (String)session.getAttribute("dos2");
			String dur1 = (String)session.getAttribute("dur1");
			String dur2 = (String)session.getAttribute("dur2");
			%>
			
			<tr>
					<th>Medicine Name</th>
					<td>&nbsp;</td>
					<th>Dosage</th>
					<td>&nbsp;</td>
					<th>Duration</th>
					
				</tr>
				<tr>
					<td> <input type="text" value=<%=med1%> name="Mname1" ></td>
					<td>&nbsp;</td>
					<td> <input type="number" value=<%=dos1%> name="Mdose1" ></td>
					<td>&nbsp;</td>
					<td> <input type="number" value=<%=dur1%> name="Mdur1" ></td>
				</tr>
				<tr>
					<td> <input type="text" value=<%=med2%> name="Mname2" ></td>
					<td>&nbsp;</td>
					<td> <input type="number" value=<%=dos2%> name="Mdose2" ></td>
					<td>&nbsp;</td>
					<td> <input type="number" value=<%=dur2%> name="Mdur2" ></td>
				</tr>
		
	</table>
	<h1>PATHOLOGY DETAILS</h1>
	<table border="1">
		<tr>
					<th>Test 1</th>
					<td>&nbsp;</td>
					<th>Test 2</th>
					<td>&nbsp;</td>
					<th>Patient Id</th>
					<td>&nbsp;</td>
					<th>Doctor Id</th>
			</tr>
			<%ArrayList<PrescriptionInfo> obj1=(ArrayList<PrescriptionInfo>)request.getAttribute("info1");
		
		for (PrescriptionInfo ob1 :obj1 )
		{ 
		%>
		<tr>
			<td align="center"><%= ob1.getPtest1() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob1.getPtest2() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob1.getPid() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob1.getDocId() %></td>
		</tr>
		<%} %>
		</table>
		<br/>
		<br/>
		<input type="submit" value="UPDATE">
		</form>
	<a href="AfterDocLogin.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
	TO GO DOCTOR HOME
	</div>
</body>
</html>