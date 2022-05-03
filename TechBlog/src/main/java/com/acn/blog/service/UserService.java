package com.acn.blog.service;

import java.util.List;

import com.acn.blog.beans.UserBean;

public interface UserService {

	// INSERT
	Integer insertUser(UserBean userBean) throws Exception;

	// SELECT
	List<UserBean> getAllUsers() throws Exception;

	// DELETE
	Boolean deleteUser(Integer userId) throws Exception;

	// UPDATE
	Boolean updateUser(UserBean userBean) throws Exception;

	// GET USER BY EMAIL & PASSWORD
	UserBean getUserByEmailAndPassword(String email, String password) throws Exception;

	// GET USER BY ID
	UserBean getUserById(Integer uid) throws Exception;
}
