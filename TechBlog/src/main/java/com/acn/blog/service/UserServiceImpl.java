package com.acn.blog.service;

import java.util.List;

import com.acn.blog.beans.UserBean;
import com.acn.blog.dao.UserDAO;
import com.acn.blog.utility.Factory;

public class UserServiceImpl implements UserService {

	private UserDAO userDao;

	public Integer insertUser(UserBean bean) throws Exception {
		userDao = Factory.getUserDAO();
		return userDao.insertUser(bean);
	}

	public List<UserBean> getAllUsers() throws Exception {

		return null;
	}

	public Boolean deleteUser(Integer userId) throws Exception {

		return null;
	}

	public Boolean updateUser(UserBean bean) throws Exception {

		return null;
	}

	public UserBean getUserByEmailAndPassword(String email, String password) throws Exception {
		userDao = Factory.getUserDAO();
		return userDao.getUserByEmailAndPassword(email, password);
	}

}
