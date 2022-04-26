package com.acn.blog.utility;

import com.acn.blog.dao.UserDAO;
import com.acn.blog.dao.UserDAOImpl;
import com.acn.blog.service.UserService;
import com.acn.blog.service.UserServiceImpl;

public class Factory {

	public static UserService getUserService() {
		return new UserServiceImpl();
	}

	public static UserDAO getUserDAO() {
		return new UserDAOImpl();
	}
}