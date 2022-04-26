package com.acn.todo.controller;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.acn.todo.service.NoteService;
import com.acn.todo.utility.Factory;

/**
 * Servlet implementation class DeleteServlet
 */
public class DeleteServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public DeleteServlet() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		Integer noteId = null;
		NoteService service = Factory.getNoteService();
		try {
			noteId = Integer.parseInt(request.getParameter("noteid").trim());
			service.deleteNote(noteId);

		} catch (Exception e) {
			e.printStackTrace();
		}
		response.sendRedirect("allnotes.jsp");
	}
}
