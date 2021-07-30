package com.kaldin.web.controller;

import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.kaldin.web.dao.UserDAO;
import com.kaldin.web.model.UserBean;

/*
 * Author		: Pranav Choudhary
 * Date			: 24 July 2021
 * Class		: UsersInfoServlet
 * Description	: Contains code to fetch users information
 * 
 */

@WebServlet("/users/*")
public class UserInfoServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private UserDAO userDAO;
	private ServletContext context;

	public UserInfoServlet() {
		userDAO = new UserDAO();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String action = request.getPathInfo();
		context = getServletContext();

		try {
			switch (action) {
			case "/addUser":
				insertUser(request, response);
				break;
			case "/deleteUser":
				deleteUser(request, response);
				break;
			case "/updateUser":
				updateUser(request, response);
				break;
			case "/listUsers":
				listUser(request, response);
				break;
			}
		} catch (SQLException e) {
			throw new ServletException(e);
		}
	}

	private void insertUser(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		String uname = request.getParameter("uname");
		String upwd = request.getParameter("upwd");
		String uemail = request.getParameter("uemail");
		String mob = request.getParameter("umob");
		long umob = -1;
		if (!mob.isEmpty()) {
			try {
				umob = Long.parseLong(mob);
			} catch (NumberFormatException n) {
				n.printStackTrace();
			}
		}
		UserBean user = new UserBean(0, uname, upwd, uemail, umob);
		userDAO.insertUser(user);
		context.getRequestDispatcher("/logout").forward(request, response);
	}

	private void listUser(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		List<UserBean> listUsers = userDAO.selectAllUsers();
		request.setAttribute("listUsers", listUsers);
		context.getRequestDispatcher("/userslist.jsp").forward(request, response);
	}

	private void updateUser(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		String uname = request.getParameter("uname");
		String upwd = request.getParameter("upwd");
		String userEmail = request.getParameter("uemail");
		int uid = userDAO.getId(userEmail);
		long umob = Long.parseLong(request.getParameter("umob"));
		UserBean user = new UserBean(uid, uname, upwd, userEmail, umob);
		userDAO.updateUser(user);
		HttpSession session = request.getSession();
		session.setAttribute("seesion_user", uname);
		context.getRequestDispatcher("/welcome.jsp").forward(request, response);
	}

	private void deleteUser(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		String userEmail = (String) request.getSession().getAttribute("session_user");
		userDAO.deleteAUser(userEmail);
		context.getRequestDispatcher("/logout").forward(request, response);
	}
}
