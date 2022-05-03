package com.acn.blog.utility;

import com.acn.blog.dao.CategoryDAO;
import com.acn.blog.dao.CategoryDAOImpl;
import com.acn.blog.dao.CommentDAO;
import com.acn.blog.dao.CommentDAOImpl;
import com.acn.blog.dao.LikeDAO;
import com.acn.blog.dao.LikeDAOImpl;
import com.acn.blog.dao.PostDAO;
import com.acn.blog.dao.PostDAOImpl;
import com.acn.blog.dao.UserDAO;
import com.acn.blog.dao.UserDAOImpl;
import com.acn.blog.service.CategoryService;
import com.acn.blog.service.CategoryServiceImpl;
import com.acn.blog.service.CommentService;
import com.acn.blog.service.CommentServiceImpl;
import com.acn.blog.service.LikeService;
import com.acn.blog.service.LikeServiceImpl;
import com.acn.blog.service.PostService;
import com.acn.blog.service.PostServiceImpl;
import com.acn.blog.service.UserService;
import com.acn.blog.service.UserServiceImpl;

public class Factory {

	public static UserService getUserService() {
		return new UserServiceImpl();
	}

	public static UserDAO getUserDAO() {
		return new UserDAOImpl();
	}

	public static CategoryService getCategoryService() {
		return new CategoryServiceImpl();
	}

	public static CategoryDAO getCategoryDAO() {
		return new CategoryDAOImpl();
	}

	public static PostService getPostService() {
		return new PostServiceImpl();
	}

	public static PostDAO getPostDAO() {
		return new PostDAOImpl();
	}

	public static LikeService getLikeService() {
		return new LikeServiceImpl();
	}

	public static LikeDAO getLikeDAO() {
		return new LikeDAOImpl();
	}

	public static CommentService getCommentService() {
		return new CommentServiceImpl();
	}

	public static CommentDAO getCommentDAO() {
		return new CommentDAOImpl();
	}
}