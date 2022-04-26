package com.acn.todo.controller;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.acn.todo.bean.NoteBean;
import com.acn.todo.service.NoteService;
import com.acn.todo.utility.Factory;

/**
 * Servlet implementation class UpdateServlet
 */
public class UpdateServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public UpdateServlet() {
		super();

	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		Integer noteId = null;
		String title = null;
		String content = null;
		try {
			noteId = Integer.parseInt(request.getParameter("noteid").trim());
			title = request.getParameter("title");
			content = request.getParameter("content");
			NoteBean note = new NoteBean();
			note.setId(noteId);
			note.setTitle(title);
			note.setContent(content);
			NoteService service = Factory.getNoteService();
			service.updateNote(note);
			response.sendRedirect("allnotes.jsp");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
