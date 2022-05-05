package com.acn.blog.controller;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.acn.blog.beans.LikeBean;
import com.acn.blog.service.LikeService;
import com.acn.blog.utility.Factory;

/**
 * Servlet implementation class LikeServlet
 */
public class LikeServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public LikeServlet() {
		super();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		LikeService likeService = Factory.getLikeService();
		PrintWriter out = response.getWriter();
		try {
			String operation = request.getParameter("operation");
			Integer uid = Integer.parseInt(request.getParameter("userid"));
			Integer pid = Integer.parseInt(request.getParameter("postid"));
			if (operation.equals("like")) {
				if (likeService.isPostAlreadyLikedByUser(pid, uid) != true) {
					LikeBean likeBean = new LikeBean();
					likeBean.setPostId(pid);
					likeBean.setUserId(uid);
					Integer likeId = likeService.addLikes(likeBean);
					if (likeId != null) {
						out.print("success");
					}
				} else {
					likeService.deleteLike(pid, uid);
					out.print("error");
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
