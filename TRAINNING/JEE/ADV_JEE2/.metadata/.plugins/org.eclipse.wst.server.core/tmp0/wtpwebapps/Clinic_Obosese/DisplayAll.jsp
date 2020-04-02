<%@page import="com.projname.model.DoctorInfo"%>
<%@page import="com.projname.dao.DoctorDAOClass"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Doctor DATABASES</title>
</head>
<body style="background-color: silver;">
	
	<h1 align="CENTER" style="color:NAVY; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>	
	<hr color="GREN" width="100%" size="3">
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
		&nbsp; &nbsp; &nbsp; &nbsp; 
		<a href="AdminAfterLogin.jsp">CLICK HERE</a>&nbsp; &nbsp; &nbsp;TO GO ADMIN HOME
		<BR/><BR/>
		&nbsp; &nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp;
		<a href="UserDelete.jsp">CLICK HERE</a> &nbsp; &nbsp; &nbsp;TO DELETE DOCTOR RECORD
	
	<br/>

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