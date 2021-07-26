package com.kaldin.web.controller;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.kaldin.web.dao.UserDAO;

@WebServlet("/loginServlet")
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private UserDAO userdao;

	public LoginServlet() {
		userdao = new UserDAO();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doProcess(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

	private void doProcess(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String submitType = request.getParameter("submit");
		if (submitType.equals("Login")) {
			String uname = request.getParameter("username");
			String upwd = request.getParameter("password");
			System.out.println(uname);
			System.out.println(upwd);
			if (userdao.check(uname, upwd)) {
				HttpSession session = request.getSession();
				session.setAttribute("session_user", uname);
				session.setAttribute("session_upwd", upwd);
				session.setAttribute("message", userdao.getName(uname));
				request.setAttribute("message", userdao.getName(uname));
				request.getRequestDispatcher("welcome.jsp").forward(request, response);
			} else {
				System.out.println("Failure");
				request.setAttribute("message", "User not found, Click Register To Add New User !!!");
				request.getRequestDispatcher("login.jsp").forward(request, response);
			}
		}
		else if (submitType.equals("Register")) {
			request.getRequestDispatcher("/users/addUser").forward(request, response);	
		}
		else if(submitType.equals("Update")) {
			request.getRequestDispatcher("/users/updateUser").forward(request, response);	
		}
		else if(submitType.equals("Delete")) {
			request.getRequestDispatcher("/users/deleteUser").forward(request, response);	
		}
	}
}
