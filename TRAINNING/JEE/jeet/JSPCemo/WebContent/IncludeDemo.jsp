<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

<h1>THIS OUR INCLUDE DEMO PAGE</h1>
<jsp:include page="DynamicInclude.jsp"></jsp:include>

<%! String s1; %>
	<%
		s1= request.getParameter("t1");
		if(s1 != null && s1.length() >0)
		{
		%>
			<%@include file="StatisPage.jsp" %>
		<%
			}
		%>
</body>
</html>