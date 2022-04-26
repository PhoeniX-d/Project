package com.acn.blog.dao;

import java.util.List;

import com.acn.blog.beans.UserBean;

public interface UserDAO {

	// INSERT
	Integer insertUser(UserBean bean) throws Exception;

	// SELECT
	List<UserBean> getAllUsers() throws Exception;

	// DELETE
	Boolean deleteUser(Integer userId) throws Exception;
	
	// UPDATE
	Boolean updateUser(UserBean bean) throws Exception;
	
	// GET USER BY EMAIL & PASSWORD
	UserBean getUserByEmailAndPassword(String email, String password) throws Exception;
}
