package com.acn.todo.service;

import java.util.List;

import com.acn.todo.bean.NoteBean;
import com.acn.todo.dao.NoteDAO;
import com.acn.todo.utility.Factory;

public class NoteServiceImpl implements NoteService {

	private NoteDAO noteDao;

	public Integer addNote(NoteBean note) throws Exception {
		noteDao = Factory.getNoteDAO();
		return noteDao.addNote(note);
	}

	public List<NoteBean> getNotes() throws Exception {
		noteDao = Factory.getNoteDAO();
		return noteDao.getNotes();
	}

	public void deleteNote(Integer noteId) throws Exception {
		noteDao = Factory.getNoteDAO();
		noteDao.deleteNote(noteId);
	}

	public void updateNote(NoteBean note) throws Exception {
		noteDao = Factory.getNoteDAO();
		noteDao.updateNote(note);
	}

	public NoteBean getNoteById(Integer noteId) throws Exception {
		noteDao = Factory.getNoteDAO();
		return noteDao.getNoteById(noteId);
	}
}
