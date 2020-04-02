<%@page import="com.projname.model.DoctorInfo"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>



	<h1 align="CENTER" style="color: navy; font-size: 100PX; font-family: serif;">
		AOT
	</h1>
	
	<h1 align="CENTER" style="color: black; font-family: fantasy;">
		ACADEMY OF TECHNOLOGY
	</h1>
	
	<hr color="RED" width="80%" size="5">
	
	<div align="center">
		<h1 style="color: navy;">AVAILABLE DOCTORS</h1>
	<table border="1">
		
		<tr>
			<td align="center">NAME</td>
			<td>&nbsp;</td>
			<td align="center">EMAIL</td>
			<td>&nbsp;</td>
			<td align="center">MOBILE NO.</td>
			<td >&nbsp;</td>
			<td align="center">QUALIFICATION</td>
			<td>&nbsp;</td>
			<td align="center">SPECIALISATION</td>
			<td>&nbsp;</td>
			<td align="center">EXPERIENCE</td>
			<td>&nbsp;</td>
			<td align="center">REGISTRATION NO.</td>
			<td>&nbsp;</td>
			<td align="center">FESS</td>
			<td>&nbsp;</td>
			<td align="center">TIME</td>
			<td>&nbsp;</td>
			<td align="center">NO.OF PATIENTS</td>
			
		</tr>
		
		
		<%
		ArrayList<DoctorInfo> obj=(ArrayList<DoctorInfo>)request.getAttribute("info");
		
		for (DoctorInfo ob :obj )
		{ 
			//if(ob.getEnable() == "true")
			//{
		%>
	
	<tr>
		<td align="center"> <%=ob.getDname() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getDemail() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getDmob() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getQual() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getDspec() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getExp() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getReg() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getDfees() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getDtime() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getDpno() %> </td>
	</tr>
		<%} %>
	</table>
	
	<br/>
	<br/>
	<br/>
		
	</div>
	<div align="center">
	
		Book An Appointment
		<br>
		<form action="PatientBookAppointment">
		<table>
			
			<tr>
				<td>Doctor Id</td>
				<td>&nbsp;</td>
				<td> <input type="email" placeholder="Enter E-mail id" name="Demail" required > </td>
			</tr>
			
			<tr>
				<td>Date</td>
				<td>&nbsp;</td>
				<td> <input type="Date" placeholder="Enter Date" name="Date" required > </td>
			</tr>
	<%
	  String email = (String)session.getAttribute("pemail");
	%>		
			<tr>
				<td>Pationt id</td>
				<td>&nbsp;</td>
				<td> <input type="email" name="Pemail" value=<%=email%> readonly="readonly" > </td>
			</tr>
		</table>
		
		<input type="submit" value="Book">
		</form>	
	</div>




</body>
</html>