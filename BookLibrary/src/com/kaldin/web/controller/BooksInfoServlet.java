package com.kaldin.web.controller;

import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.kaldin.web.dao.BookDAO;
import com.kaldin.web.model.BookBean;

/*
 * Author		: Pranav Choudhary
 * Date			: 24 July 2021
 * Class		: BooksInfoServlet
 * Description	: Contains code to fetch Books information
 * 
 */

@WebServlet("/book/*")
public class BooksInfoServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private BookDAO bookDAO;

	public BooksInfoServlet() {
		bookDAO = new BookDAO();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doProcess(request, response);
	}
	
	private void doProcess(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String action = request.getPathInfo();
		System.out.println(action);
		try {
			switch (action) {

			case "/new":
				showNewForm(request, response);
				break;
			case "/insert":
				System.out.println("Inside Insert");
				insertBook(request, response);
				break;
			case "/delete":
				deleteBook(request, response);
				break;
			case "/edit":
				showEditForm(request, response);
				break;
			case "/update":
				updateBook(request, response);
				break;
			default:
				listBook(request, response);
				break;

			}
		} catch (SQLException e) {
			throw new ServletException(e);
		}
	}

	private void insertBook(HttpServletRequest request, HttpServletResponse response) throws SQLException, IOException {
		int bid = bookDAO.generateBID();
		String bname = request.getParameter("bname");
		String bauthor = request.getParameter("bauthor");
		String bcategory = request.getParameter("bcategory");
		double bprice = Double.parseDouble(request.getParameter("bprice"));
		int bpages = Integer.parseInt(request.getParameter("bpages"));
		BookBean Book = new BookBean(bid, bname, bauthor, bcategory, bprice, bpages);
		bookDAO.insertBook(Book);
		response.sendRedirect("list");
	}

	private void listBook(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		List<BookBean> listBooks = bookDAO.selectAllBooks();
		request.setAttribute("listBooks", listBooks);
		RequestDispatcher dispatcher = request.getRequestDispatcher("/books-list.jsp");
		dispatcher.forward(request, response);
	}

	private void showNewForm(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		RequestDispatcher dispatcher = request.getRequestDispatcher("/book-form.jsp");
		dispatcher.forward(request, response);
	}

	private void showEditForm(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, ServletException, IOException {
		String BookEmail = request.getParameter("email");
		BookBean existingBook = bookDAO.selectBook(BookEmail);
		RequestDispatcher dispatcher = request.getRequestDispatcher("/book-form.jsp");
		request.setAttribute("Book", existingBook);
		dispatcher.forward(request, response);
	}

	private void updateBook(HttpServletRequest request, HttpServletResponse response) throws SQLException, IOException {
		String bname = request.getParameter("bname");
		int bid = bookDAO.getId(bname);
		String bauthor = request.getParameter("bauthor");
		String bcategory = request.getParameter("bcategory");
		double bprice = Double.parseDouble(request.getParameter("bprice"));
		int bpages = Integer.parseInt(request.getParameter("bpages"));
		BookBean Book = new BookBean(bid, bname, bauthor, bcategory, bprice, bpages);
		bookDAO.updateBook(Book);
		response.sendRedirect("list");
	}

	private void deleteBook(HttpServletRequest request, HttpServletResponse response) throws SQLException, IOException {
		String bookName = request.getParameter("bname");
		System.out.println(bookName);
		bookDAO.deleteABook(bookName);
		response.sendRedirect("list");
	}
}
