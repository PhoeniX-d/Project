package com.acn.todo.controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.acn.todo.bean.NoteBean;
import com.acn.todo.service.NoteService;
import com.acn.todo.utility.Factory;

/**
 * Servlet implementation class SaveNoteServlet
 */
public class SaveNoteServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public SaveNoteServlet() {
		super();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		NoteService service = Factory.getNoteService();
		Integer noteId = null;
		try {
			String title = request.getParameter("title");
			String content = request.getParameter("content");
			NoteBean note = new NoteBean();
			note.setTitle(title);
			note.setContent(content);
			note.setAddedDate(new Date());
			noteId = service.addNote(note);
			PrintWriter out = response.getWriter();
			response.setContentType("text/html");
			out.print("<h1 style='text-align:center;'>Note added successfully with note id : " + noteId + "</h1>");
			out.print("<h1 style='text-align:center;'><a href='allnotes.jsp'>View All Notes</a></h1>");

		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
