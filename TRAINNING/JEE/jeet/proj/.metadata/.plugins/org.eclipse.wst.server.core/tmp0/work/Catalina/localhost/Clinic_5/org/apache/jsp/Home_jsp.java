/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/8.0.37
 * Generated at: 2017-07-15 21:36:25 UTC
 * Note: The last modified time of this file was set to
 *       the last modified time of the source file after
 *       generation to assist with modification tracking.
 */
package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class Home_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent,
                 org.apache.jasper.runtime.JspSourceImports {

  private static final javax.servlet.jsp.JspFactory _jspxFactory =
          javax.servlet.jsp.JspFactory.getDefaultFactory();

  private static java.util.Map<java.lang.String,java.lang.Long> _jspx_dependants;

  private static final java.util.Set<java.lang.String> _jspx_imports_packages;

  private static final java.util.Set<java.lang.String> _jspx_imports_classes;

  static {
    _jspx_imports_packages = new java.util.HashSet<>();
    _jspx_imports_packages.add("javax.servlet");
    _jspx_imports_packages.add("javax.servlet.http");
    _jspx_imports_packages.add("javax.servlet.jsp");
    _jspx_imports_classes = null;
  }

  private volatile javax.el.ExpressionFactory _el_expressionfactory;
  private volatile org.apache.tomcat.InstanceManager _jsp_instancemanager;

  public java.util.Map<java.lang.String,java.lang.Long> getDependants() {
    return _jspx_dependants;
  }

  public java.util.Set<java.lang.String> getPackageImports() {
    return _jspx_imports_packages;
  }

  public java.util.Set<java.lang.String> getClassImports() {
    return _jspx_imports_classes;
  }

  public javax.el.ExpressionFactory _jsp_getExpressionFactory() {
    if (_el_expressionfactory == null) {
      synchronized (this) {
        if (_el_expressionfactory == null) {
          _el_expressionfactory = _jspxFactory.getJspApplicationContext(getServletConfig().getServletContext()).getExpressionFactory();
        }
      }
    }
    return _el_expressionfactory;
  }

  public org.apache.tomcat.InstanceManager _jsp_getInstanceManager() {
    if (_jsp_instancemanager == null) {
      synchronized (this) {
        if (_jsp_instancemanager == null) {
          _jsp_instancemanager = org.apache.jasper.runtime.InstanceManagerFactory.getInstanceManager(getServletConfig());
        }
      }
    }
    return _jsp_instancemanager;
  }

  public void _jspInit() {
  }

  public void _jspDestroy() {
  }

  public void _jspService(final javax.servlet.http.HttpServletRequest request, final javax.servlet.http.HttpServletResponse response)
        throws java.io.IOException, javax.servlet.ServletException {

final java.lang.String _jspx_method = request.getMethod();
if (!"GET".equals(_jspx_method) && !"POST".equals(_jspx_method) && !"HEAD".equals(_jspx_method) && !javax.servlet.DispatcherType.ERROR.equals(request.getDispatcherType())) {
response.sendError(HttpServletResponse.SC_METHOD_NOT_ALLOWED, "JSPs only permit GET POST or HEAD");
return;
}

    final javax.servlet.jsp.PageContext pageContext;
    javax.servlet.http.HttpSession session = null;
    final javax.servlet.ServletContext application;
    final javax.servlet.ServletConfig config;
    javax.servlet.jsp.JspWriter out = null;
    final java.lang.Object page = this;
    javax.servlet.jsp.JspWriter _jspx_out = null;
    javax.servlet.jsp.PageContext _jspx_page_context = null;


    try {
      response.setContentType("text/html; charset=ISO-8859-1");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;

      out.write("\r\n");
      out.write("\r\n");
      out.write("<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">\r\n");
      out.write("<html>\r\n");
      out.write("<head>\r\n");
      out.write("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=ISO-8859-1\">\r\n");
      out.write("<title>AOT PORTAL</title>\r\n");
      out.write("</head>\r\n");
      out.write("<body style=\"background-color: white;\">\r\n");
      out.write("\t<h1 align=\"CENTER\" style=\"color: navy; font-size: 100PX; font-family: serif;\">\r\n");
      out.write("\t\tAOT\r\n");
      out.write("\t</h1>\r\n");
      out.write("\t\r\n");
      out.write("\t<h1 align=\"CENTER\" style=\"color: black; font-family: fantasy;\">\r\n");
      out.write("\t\tACADEMY OF TECHNOLOGY\r\n");
      out.write("\t</h1>\r\n");
      out.write("\t\r\n");
      out.write("\t<hr color=\"RED\" width=\"80%\" size=\"5\">\r\n");
      out.write("\t<BR/>\r\n");
      out.write("\r\n");
      out.write("\t<p align=\"CENTER\">\r\n");
      out.write("\t\t<marquee behavior=\"alternate\" style=\"color: green;\">WELCOME AOTIANS WELCOME AOTIANS WELCOME AOTIANS WELCOME AOTIANS WELCOME AOTIANS WELCOME AOTIANS WELCOME AOTIANS</marquee>\r\n");
      out.write("\t\t<br/>\r\n");
      out.write("\t\t<B>AOT WELCOMES ALL THE UNDER GRADUATE STUDENTS</B> \r\n");
      out.write("\t\t<BR/>\r\n");
      out.write("\t\t<BR/>\r\n");
      out.write("\t\t<i>THIS IS THE AOT PORTAL. STUDENTS MUST REGISTER TO THE PORTAL TO STAY UPDATED ABOUT THE LATEST NEWS REGARDING ACADEMICS AND OTHER IMPORTANT ANNOUNCEMENTS. ALL STUDENTS ARE REQUSTED TO KEEP THEIR DATABASE INFORMATIONS UPDATED.</i>\r\n");
      out.write("\t</p>\r\n");
      out.write("\t\r\n");
      out.write("\t<div align=\"center\">\t\t\r\n");
      out.write("\t\t<b style=\"color: navy;\">BEST WISHES FOR YOUR BRIGHT FUTURE.</b>\r\n");
      out.write("\t</div>\r\n");
      out.write("\r\n");
      out.write("\t<BR/>\r\n");
      out.write("\t\r\n");
      out.write("\t&nbsp; &nbsp; &nbsp;\r\n");
      out.write("\t<b>ENGINEERING COURSES AVAILABLE:</b>\r\n");
      out.write("\t\r\n");
      out.write("\t<ul style=\"color: red;\">\r\n");
      out.write("\t\t<li>IT</li>\r\n");
      out.write("\t\t<li>CSE</li>\r\n");
      out.write("\t\t<li>EE</li>\r\n");
      out.write("\t\t<li>ECE</li>\r\n");
      out.write("\t\t<li>ME</li>\r\n");
      out.write("\t\t<li>AEIE</li>\r\n");
      out.write("\t</ul>\r\n");
      out.write("\t<BR/>\r\n");
      out.write("\t<BR/>\r\n");
      out.write("\t\r\n");
      out.write("\t&nbsp; &nbsp; &nbsp;\t\r\n");
      out.write("\tGET YOURSELF REGISTERED\r\n");
      out.write("\t &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;\r\n");
      out.write("\tLOGIN TO ADMIN PORTAL\r\n");
      out.write("\t&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; \r\n");
      out.write("\tLOGIN TO STUDENT PORTAL\r\n");
      out.write("\t\r\n");
      out.write("\t\r\n");
      out.write("\t<br/>\r\n");
      out.write("\t\r\n");
      out.write("\t&nbsp; &nbsp; &nbsp;\r\n");
      out.write("\t<a href=\"DocLogin.jsp\">GO TO DOCTOR LOGIN PAGE</a>\r\n");
      out.write("\t\r\n");
      out.write("\t&nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;\r\n");
      out.write("\t<a href=\"AdminLogin.jsp\">GO TO ADMIN LOGIN PAGE</a>\r\n");
      out.write("\r\n");
      out.write("\t&nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;\r\n");
      out.write("\t<a href=\"PatientLogin.jsp\">GO TO PATIENT LOGIN PAGE</a>\r\n");
      out.write("\t\r\n");
      out.write("</body>\r\n");
      out.write("</html>");
    } catch (java.lang.Throwable t) {
      if (!(t instanceof javax.servlet.jsp.SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          try {
            if (response.isCommitted()) {
              out.flush();
            } else {
              out.clearBuffer();
            }
          } catch (java.io.IOException e) {}
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
