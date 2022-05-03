package com.acn.blog.controller;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.servlet.http.Part;

import com.acn.blog.beans.UserBean;
import com.acn.blog.service.UserService;
import com.acn.blog.utility.BlogUtility;
import com.acn.blog.utility.Factory;
import com.acn.blog.utility.Message;

/**
 * Servlet implementation class EditServlet
 */
@MultipartConfig
public class EditServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public EditServlet() {
		super();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		UserService service = Factory.getUserService();
		PrintWriter out = response.getWriter();
		try {
			// Fetch Edited Data
			String name = request.getParameter("name");
			String email = request.getParameter("email");
			String mobileno = request.getParameter("mobileno");
			String password = request.getParameter("password");
			String profileName = null;

			// Fetch profile pic data i.e image
			Part part = request.getPart("profilepic");
			if (part != null)
				profileName = part.getSubmittedFileName();

			// Get user data from session
			HttpSession currSession = request.getSession();
			UserBean currUser = (UserBean) currSession.getAttribute("currentuser");
			String oldProfileName = currUser.getProfile();

			// Update user with new data
			currUser.setEmail(email);
			currUser.setPassword(password);
			currUser.setName(name);
			currUser.setMobileno(mobileno);

			if (profileName.isEmpty())
				profileName = "default.png";
			profileName = currUser.getId() + "_pro_" + profileName;
			currUser.setProfile(profileName);
			response.setContentType("text/html");
			if (service.updateUser(currUser)) {
				String path = null;
				if (!oldProfileName.equals("default.png")) {
					path = request.getServletContext().getRealPath("/") + "profiles" + File.separator + oldProfileName;
					BlogUtility.deleteFile(path);
				}

				// Store profile picture
				path = request.getServletContext().getRealPath("/") + "profiles" + File.separator + profileName;
				InputStream is = part.getInputStream();
				BlogUtility.saveFile(is, path);

				currSession.setAttribute("currentuser", currUser);
				out.print("success");
			} else {
				out.print("error");
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
