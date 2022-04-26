package com.acn.register.service;

import com.acn.register.bean.UserBean;
import com.acn.register.dao.UserDAO;
import com.acn.register.utility.Factory;

public class UserServiceImpl implements UserService {

	private UserDAO noteDao;

	public Integer addUser(UserBean user) throws Exception {
		noteDao = Factory.getUserDAO();
		return noteDao.addUser(user);
	}

	// public List<UserBean> getNotes() throws Exception {
	// noteDao = Factory.getNoteDAO();
	// return noteDao.getUsers();
	// }
	//
	// public void deleteNote(Integer noteId) throws Exception {
	// noteDao = Factory.getNoteDAO();
	// noteDao.deleteUser(noteId);
	// }
	//
	// public void updateNote(UserBean note) throws Exception {
	// noteDao = Factory.getNoteDAO();
	// noteDao.updateUser(note);
	// }
	//
	// public UserBean getNoteById(Integer noteId) throws Exception {
	// noteDao = Factory.getNoteDAO();
	// return noteDao.getUserById(noteId);
	// }
}
