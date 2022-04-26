package com.acn.todo.utility;

import com.acn.todo.dao.NoteDAO;
import com.acn.todo.dao.NoteDAOImpl;
import com.acn.todo.service.NoteService;
import com.acn.todo.service.NoteServiceImpl;

public class Factory {

	public static NoteService getNoteService() {
		return new NoteServiceImpl();
	}

	public static NoteDAO getNoteDAO() {
		return new NoteDAOImpl();
	}
}