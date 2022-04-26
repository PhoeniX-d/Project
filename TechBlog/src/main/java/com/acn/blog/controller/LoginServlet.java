package com.acn.blog.controller;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.acn.blog.beans.UserBean;
import com.acn.blog.service.UserService;
import com.acn.blog.utility.Factory;
import com.acn.blog.utility.Message;

/**
 * Servlet implementation class LoginServlet
 */
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public LoginServlet() {
		super();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		UserService service = Factory.getUserService();
		try (PrintWriter out = response.getWriter()) {
			String email = request.getParameter("email");
			String password = request.getParameter("password");
			UserBean userBean = service.getUserByEmailAndPassword(email, password);
			if (userBean != null) {
				HttpSession session = request.getSession();
				session.setAttribute("currentuser", userBean);
				response.sendRedirect("profile.jsp");
			} else {
				Message msg = new Message("Invalid Email or Password", "error", "alert-danger");
				HttpSession session = request.getSession();
				session.setAttribute("msg", msg);
				response.sendRedirect("login.jsp");
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
