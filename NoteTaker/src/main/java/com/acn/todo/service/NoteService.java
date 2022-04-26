package com.acn.todo.service;

import java.util.List;

import com.acn.todo.bean.NoteBean;

public interface NoteService {
	public Integer addNote(NoteBean note) throws Exception;

	public List<NoteBean> getNotes() throws Exception;

	public void deleteNote(Integer noteId) throws Exception;

	public void updateNote(NoteBean noteBean) throws Exception;

	public NoteBean getNoteById(Integer noteId) throws Exception;
}
