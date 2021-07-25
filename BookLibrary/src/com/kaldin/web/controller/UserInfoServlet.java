package com.kaldin.web.controller;

import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.kaldin.web.dao.UserDAO;
import com.kaldin.web.model.UserBean;

/*
 * Author		: Pranav Choudhary
 * Date			: 24 July 2021
 * Class		: UsersInfoServlet
 * Description	: Contains code to fetch users information
 * 
 */

@WebServlet("/")
public class UserInfoServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private UserDAO userDAO;

	public UserInfoServlet() {
		userDAO = new UserDAO();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String action = request.getServletPath();
		System.out.println(action);
		try {
			switch (action) {

			case "/new":
				showNewForm(request, response);
				break;
			case "/insert":
				insertUser(request, response);
				break;
			case "/delete":
				deleteUser(request, response);
				break;
			case "/edit":
				showEditForm(request, response);
				break;
			case "/update":
				updateUser(request, response);
				break;
			default:
				listUser(request, response);
				break;

			}
		} catch (SQLException e) {
			throw new ServletException(e);
		}
	}
	
	private void insertUser(HttpServletRequest request, HttpServletResponse response) throws SQLException, IOException{
		int uid = userDAO.generateUID();
		String uname = request.getParameter("name");
		String upwd = request.getParameter("upwd");
		String uemail = request.getParameter("email");
		long umob = Long.parseLong(request.getParameter("mob"));
		UserBean user = new UserBean(uid, uname, upwd, uemail, umob);
		userDAO.insertUser(user);
		response.sendRedirect("list");
	}
	
	private void listUser(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		List<UserBean> listUser = userDAO.selectAllUsers();
		request.setAttribute("listUser", listUser);
		RequestDispatcher dispatcher = request.getRequestDispatcher("users-list.jsp");
		dispatcher.forward(request, response);
	}

	private void showNewForm(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		RequestDispatcher dispatcher = request.getRequestDispatcher("user-form.jsp");
		dispatcher.forward(request, response);
	}

	private void showEditForm(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, ServletException, IOException {
		String userEmail = request.getParameter("email");
		UserBean existingUser = userDAO.selectUser(userEmail);
		RequestDispatcher dispatcher = request.getRequestDispatcher("user-form.jsp");
		request.setAttribute("user", existingUser);
		dispatcher.forward(request, response);
	}
	
	private void updateUser(HttpServletRequest request, HttpServletResponse response) 
			throws SQLException, IOException {
		String uname = request.getParameter("name");
		String upwd = request.getParameter("upwd");
		String userEmail = request.getParameter("email");
		int uid = userDAO.getId(userEmail);
		long umob = Long.parseLong(request.getParameter("mob"));
		UserBean user = new UserBean(uid, uname, upwd, userEmail, umob);
		userDAO.updateUser(user);
		response.sendRedirect("list");
	}

	private void deleteUser(HttpServletRequest request, HttpServletResponse response) 
			throws SQLException, IOException {
		String userEmail = request.getParameter("email");
		userDAO.deleteAUser(userEmail);
		response.sendRedirect("list");
	}
}
