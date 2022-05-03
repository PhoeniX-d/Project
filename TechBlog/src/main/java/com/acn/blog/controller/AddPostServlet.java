package com.acn.blog.controller;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.servlet.http.Part;

import com.acn.blog.beans.PostBean;
import com.acn.blog.beans.UserBean;
import com.acn.blog.service.PostService;
import com.acn.blog.utility.BlogUtility;
import com.acn.blog.utility.Factory;

/**
 * Servlet implementation class AddPost
 */
@MultipartConfig
public class AddPostServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public AddPostServlet() {
		super();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		PostService service = Factory.getPostService();
		PrintWriter out = response.getWriter();
		try {
			Integer cid = Integer.parseInt(request.getParameter("cid"));
			String title = request.getParameter("title");
			String content = request.getParameter("content");
			String code = request.getParameter("code");
			String picName = null;
			Part part = request.getPart("pic");
			picName = part.getSubmittedFileName();

			// Getting current user Id
			HttpSession currSession = request.getSession();
			UserBean currUser = (UserBean) currSession.getAttribute("currentuser");

			PostBean postBean = new PostBean();
			postBean.setUid(currUser.getId());
			postBean.setTitle(title);
			picName = currUser.getId() + "_blogpic_" + title + "_" + picName;
			postBean.setPic(picName);
			postBean.setContent(content);
			postBean.setCode(code);
			postBean.setCid(cid);

			Integer postId = service.addPost(postBean);
			response.setContentType("text/html");
			if (postId != null) {
				out.print("success");

				String path = request.getServletContext().getRealPath("/") + "blogpics" + File.separator + picName;
				BlogUtility.saveFile(part.getInputStream(), path);
			} else {
				out.print("error");
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
