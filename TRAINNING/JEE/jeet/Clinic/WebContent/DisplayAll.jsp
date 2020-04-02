<%@page import="com.projname.model.DoctorInfo"%>
<%@page import="com.projname.dao.DoctorDAOClass"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>STUDENT DATABASES</title>
</head>
<body>
	
	<h1 align="CENTER" style="color: navy; font-size: 100PX; font-family: serif;">
		AOT
	</h1>
	
	<h1 align="CENTER" style="color: black; font-family: fantasy;">
		ACADEMY OF TECHNOLOGY
	</h1>
	
	<hr color="RED" width="80%" size="5">
	<BR/>
	
	<div align="center">
		<h1 style="color: navy;">DOCTOR DETAILS</h1>
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
			<td>&nbsp;</td>
			<td align="center">ENABLE</td>
		</tr>
		
		
		<%DoctorDAOClass dbobj =new DoctorDAOClass();
	
		ArrayList<DoctorInfo> docList = dbobj.fetchAllRecord();
			for (DoctorInfo ob :docList )
			{ 
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
			<td>&nbsp;</td>
			<td align="center"> <%=ob.getEnable() %> </td>
		</tr>
		<%} %>
	</table>
	
		<br/>
		<br/>
		&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;ADMIN HOME
	
	
	 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
	DELETE DOCTOR DETAILS
	
	<br/>
	
	<a href="AdminAfterLogin.jsp">GO TO ADMIN HOME</a>
	  
	
	  &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
	<a href="UserDelete.jsp">INPUT DOCTOR ID</a>
	<div style="color: red; font-weight: bold;">
		 	<%
		 		if(request.getAttribute("errmsg")=="1")
		 		{
		 			out.println("No Doctors Found");
		 			request.setAttribute("errmsg", null);
		 		}
		 		else if(request.getAttribute("done")=="1")
		 		{
		 			out.println("Doctor Enabled");
		 			request.setAttribute("done", null);
		 		}
		 		else if(request.getAttribute("done")=="2")
		 		{
		 			out.println("Doctor Disabled");
		 			request.setAttribute("done", null);
		 		}
		 	%>
		 	
		</div>	
	</div>
	<div align="left">
		<br>
		<br>
		
		Enable Doctor
		<form action="Enable">
		<table>
			<tr>
				<td>Doctor Email</td>
				<td>&nbsp;</td>
				<td> <input type="email" placeholder="Enter Email" name="Enab" required> </td>
			</tr>
		</table>
		<input type="submit" value="Enable">
		</form>
	</div>
	
	<div align="right">
		Disable Doctor
		<form action="Disable">
		<table>
			<tr>
				<td>Doctor Email</td>
				<td>&nbsp;</td>
				<td> <input type="email" placeholder="Enter Email" name="Disab" required> </td>
			</tr>
		</table>
		<input type="submit" value="Disable">
		</form>
	</div>
	
	
	
	
</body>
</html>