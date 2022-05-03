package com.acn.blog.controller;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.acn.blog.beans.CommentBean;
import com.acn.blog.service.CommentService;
import com.acn.blog.utility.Factory;

/**
 * Servlet implementation class CommentServlet
 */
public class CommentServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public CommentServlet() {
		super();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		CommentService commentService = Factory.getCommentService();
		PrintWriter out = response.getWriter();
		try {
			System.out.println("IINSSIDDEE COMMENT SERRVELETT");
			String operation = request.getParameter("operation");
			Integer uid = Integer.parseInt(request.getParameter("userid"));
			Integer pid = Integer.parseInt(request.getParameter("postid"));
			String comments = request.getParameter("comments");
			if (operation.equals("comment")) {
				CommentBean commentBean = new CommentBean();
				commentBean.setCpostId(pid);
				commentBean.setCuserId(uid);
				commentBean.setComments(comments);
				Integer likeId = commentService.addComments(commentBean);
				if (likeId != null) {
					out.print("success");
				} else {
					out.print("error");
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
