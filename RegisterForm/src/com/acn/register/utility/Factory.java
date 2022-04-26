package com.acn.register.utility;

import com.acn.register.dao.UserDAO;
import com.acn.register.dao.UserDAOImpl;
import com.acn.register.service.UserService;
import com.acn.register.service.UserServiceImpl;

public class Factory {

	public static UserService getUserService() {
		return new UserServiceImpl();
	}

	public static UserDAO getUserDAO() {
		return new UserDAOImpl();
	}
}