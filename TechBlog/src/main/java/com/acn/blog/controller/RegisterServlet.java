package com.acn.blog.controller;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.acn.blog.beans.UserBean;
import com.acn.blog.service.UserService;
import com.acn.blog.utility.Factory;

/**
 * Servlet implementation class RegisterServlet
 */
@MultipartConfig
public class RegisterServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public RegisterServlet() {
		super();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		UserService service = Factory.getUserService();
		try (PrintWriter out = response.getWriter();) {

			String terms = request.getParameter("terms");
			if (terms != null) {

				// Fetch values from jsps
				String name = request.getParameter("username");
				Character gender = request.getParameter("gender").toUpperCase().charAt(0);
				String email = request.getParameter("email");
				String password = request.getParameter("password");
				String mobileno = request.getParameter("mobileno");

				// Populate bean values
				UserBean userBean = new UserBean();
				userBean.setName(name);
				userBean.setGender(gender);
				userBean.setEmail(email);
				userBean.setPassword(password);
				userBean.setMobileno(mobileno);

				// Insert values into database
				Integer userId = service.insertUser(userBean);

				response.setContentType("text/html");
				out.print("Success");
			} else {
				response.setContentType("text/html");
				out.print("Agree Terms & Conditions");
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
