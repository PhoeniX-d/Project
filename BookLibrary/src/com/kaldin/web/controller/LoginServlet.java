package com.kaldin.web.controller;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.kaldin.web.dao.UserDAO;

@WebServlet("/loginServlet/*")
@MultipartConfig(fileSizeThreshold = 1024 * 1024 * 2, // 2MB
		maxFileSize = 1024 * 1024 * 10, // 10MB
		maxRequestSize = 1024 * 1024 * 50)
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private UserDAO userdao;
	private static final int USER_PASS = 2;
	private static final int USER = 1;

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
		if (submitType != null) {
			if (submitType.equals("Login")) {
				String uname = request.getParameter("username");
				String upwd = request.getParameter("password");
				int creds = userdao.check(uname, upwd);
				if (creds == USER_PASS) {
					HttpSession session = request.getSession();
					session.setAttribute("session_user", uname);
					session.setAttribute("session_upwd", upwd);
					session.setAttribute("session_uid", userdao.getId(uname));
					session.setAttribute("message", userdao.getName(uname));
					request.setAttribute("message", userdao.getName(uname));
					request.getRequestDispatcher("welcome.jsp").forward(request, response);
				}else if(creds == USER) {
					request.setAttribute("message", "Incorrect Password");
					request.getRequestDispatcher("login.jsp").forward(request, response);
				}	
				else {
					request.setAttribute("message", "User not found, Click Register To Add New User !!!");
					request.getRequestDispatcher("login.jsp").forward(request, response);
				}
			} else if (submitType.equals("Register")) {
				request.getRequestDispatcher("/users/addUser").forward(request, response);
			} else if (submitType.equals("Update")) {
				request.getRequestDispatcher("/users/updateUser").forward(request, response);
			} else if (submitType.equals("Delete")) {
				request.getRequestDispatcher("/users/deleteUser").forward(request, response);
			} else if (submitType.equals("Users")) {
				request.getRequestDispatcher("/users/listUsers").forward(request, response);
			} else if (submitType.equals("AddBook")) {
				request.getRequestDispatcher("/books/addBook").forward(request, response);
			} else if (submitType.equals("EditBook")) {
				request.getRequestDispatcher("/books/editBook").forward(request, response);
			} else if (submitType.equals("EditAuthor")) {
				request.getRequestDispatcher("/books/editAuthor").forward(request, response);
			}
		} else {
			String path = request.getPathInfo();
			request.getRequestDispatcher("/books" + path).forward(request, response);
		}
	}
}
