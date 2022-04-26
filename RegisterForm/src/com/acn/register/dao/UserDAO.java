package com.acn.register.dao;

import java.util.List;

import com.acn.register.bean.UserBean;

public interface UserDAO {
	public Integer addUser(UserBean User) throws Exception;

//	public List<UserBean> getUsers() throws Exception;
//	
//	public void deleteUser(Integer UserId)throws Exception;
//	
//	public void updateUser(UserBean UserBean)throws Exception;
//	
//	public UserBean getUserById(Integer UserId) throws Exception;
}
