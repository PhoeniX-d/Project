package com.kaldin.web.controller;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/logout")
public class LogoutServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		System.out.println(request.getParameter("uname"));
		HttpSession session = request.getSession();
		session.removeAttribute("session_user");
		session.removeAttribute("session_upwd");
		session.removeAttribute("message");
		session.invalidate();
		response.sendRedirect("login.jsp");
	}

}
