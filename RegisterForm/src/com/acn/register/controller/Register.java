package com.acn.register.controller;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;

import com.acn.register.bean.UserBean;
import com.acn.register.service.UserService;
import com.acn.register.utility.Factory;

/**
 * Servlet implementation class Register
 */

@MultipartConfig
@WebServlet("/Register")
public class Register extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public Register() {
		super();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		UserService service = Factory.getUserService();
		PrintWriter out = response.getWriter();
		try {

			Thread.sleep(1000);

			String name = request.getParameter("username");
			String password = request.getParameter("password");
			String email = request.getParameter("email");
			Part part = request.getPart("image");
			String fileName = part.getSubmittedFileName();
			UserBean user = new UserBean();
			user.setName(name);
			user.setPassword(password);
			user.setEmail(email);
			user.setImage(fileName);
			
			// File writing to folder
			Integer id = service.addUser(user);
			InputStream is = part.getInputStream();
			byte[] data = new byte[is.available()];
			is.read(data);
			String path = request.getRealPath("/") + "img" + File.separator + fileName;
			FileOutputStream fos = new FileOutputStream(path);
			out.print(path);
			fos.write(data);
			fos.close();
			out.print("pass");
		} catch (Exception e) {
			out.print("fail");
			out.close();
			e.printStackTrace();
		}
	}

}
