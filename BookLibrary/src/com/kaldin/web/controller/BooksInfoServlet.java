package com.kaldin.web.controller;

import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.sql.SQLException;
import java.util.Base64;
import java.util.List;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;

import com.kaldin.web.dao.BookDAO;
import com.kaldin.web.model.BookBean;

/*
 * Author		: Pranav Choudhary
 * Date			: 24 July 2021
 * Class		: BooksInfoServlet
 * Description	: Contains code to fetch Books information
 * 
 */

@WebServlet("/books/*")
@MultipartConfig(fileSizeThreshold = 1024 * 1024 * 2, // 2MB
		maxFileSize = 1024 * 1024 * 10, // 10MB
		maxRequestSize = 1024 * 1024 * 50)
public class BooksInfoServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private BookDAO bookDAO;
	private ServletContext context;
	public static final String UPLOAD_DIR = "C:/Users/Dell/Desktop/Eclipse Workspaces/JEE_EclipseWorkspace/Assignments/authors/";

	public BooksInfoServlet() {
		bookDAO = new BookDAO();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		context = getServletContext();
		doProcess(request, response);
	}

	private void doProcess(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String action = request.getPathInfo();
		try {
			switch (action) {
			case "/viewAuthor":
				viewBook(request, response);
				break;
			case "/editAuthor":
				editAuthor(request, response);
				break;
			case "/addBook":
				insertBook(request, response);
				break;
			case "/deleteBook":
				deleteBook(request, response);
				break;
			case "/editBook":
				editBook(request, response);
				break;
			case "/listBooks":
				listBooks(request, response);
				break;
			}
		} catch (SQLException e) {
			throw new ServletException(e);
		}
	}

	private void insertBook(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		String bname = request.getParameter("bname");
		int userid = getUserId(request);
		bname = request.getParameter("bname");
		String bauthor = request.getParameter("bauthor");
		String bcategory = request.getParameter("bcategory");
		String price = request.getParameter("bprice");
		double bprice = -1;
		if (!price.isEmpty()) {
			try {
				bprice = Double.parseDouble(price);
			} catch (NumberFormatException n) {
				n.printStackTrace();
			}
		}
		String pages = request.getParameter("bpages");
		int bpages = -1;
		if (!pages.isEmpty()) {
			try {
				bpages = Integer.parseInt(pages);
			} catch (NumberFormatException n) {
				n.printStackTrace();
			}
		}
		String imgName = getImagePath(request);
		BookBean book = new BookBean(0, userid, bname, bauthor, bcategory, bprice, bpages, imgName);
		bookDAO.insertBook(book);
		response.sendRedirect("./loginServlet/listBooks");
	}

	private void listBooks(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		int userid = getUserId(request);
		List<BookBean> listBooks = bookDAO.selectAllBooks(userid);
		request.setAttribute("listBooks", listBooks);
		context.getRequestDispatcher("/bookslist.jsp").forward(request, response);
	}

	private void viewBook(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		int bid = 0;
		try {
			bid = Integer.parseInt(request.getParameter("bid"));
		} catch (NumberFormatException n) {
			n.printStackTrace();
		}
		String imgName = bookDAO.viewAuthor(bid);
		String imgPath = getEncodedImage(imgName);
		request.setAttribute("imgPath", imgPath);
		context.getRequestDispatcher("/viewbook.jsp").forward(request, response);
	}

	private void editBook(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		int userid = 0, bid = 0;
		try {
			userid = (Integer) request.getSession().getAttribute("session_uid");
			bid = Integer.parseInt(request.getParameter("bid"));
		} catch (NumberFormatException n) {
			n.printStackTrace();
		}
		String bname = request.getParameter("bname");
		String bauthor = request.getParameter("bauthor");
		String bcategory = request.getParameter("bcategory");
		double bprice = Double.parseDouble(request.getParameter("bprice"));
		int bpages = Integer.parseInt(request.getParameter("bpages"));
		BookBean book = new BookBean(bid, userid, bname, bauthor, bcategory, bprice, bpages, null);
		bookDAO.updateBook(book);
		response.sendRedirect("./loginServlet/listBooks");
	}

	private void editAuthor(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		int bid = 0;
		try {
			bid = Integer.parseInt(request.getParameter("bid"));
		} catch (NumberFormatException n) {
			n.printStackTrace();
		}
		String imgName = getImagePath(request);
		if (imgName != null) {
			bookDAO.editAuthor(bid, imgName);
		}
		response.sendRedirect("listBooks");
	}

	private void deleteBook(HttpServletRequest request, HttpServletResponse response)
			throws SQLException, IOException, ServletException {
		int bid = Integer.parseInt(request.getParameter("bid"));
		bookDAO.deleteABook(bid);
		response.sendRedirect("listBooks");
	}

	private String getEncodedImage(String fileName) throws IOException, ServletException {
		FileInputStream inputstream = null;
		String base64Image = null;
		if (fileName != null) {
			inputstream = new FileInputStream(UPLOAD_DIR + fileName);
			ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
			byte[] buffer = new byte[2048];
			int bytesRead = -1;
			while ((bytesRead = inputstream.read(buffer)) != -1) {
				outputStream.write(buffer, 0, bytesRead);
			}
			byte[] imageBytes = outputStream.toByteArray();
			base64Image = Base64.getEncoder().encodeToString(imageBytes);
			inputstream.close();
			outputStream.close();
		}
		return base64Image;
	}

	private String getImagePath(HttpServletRequest request) throws IOException, ServletException {
		Part part = request.getPart("bauthorimg");//
		String actualFileName = extractFileName(part), fileName = null;
		if (actualFileName != null) {
			fileName = (String) request.getSession().getAttribute("message") + getUserId(request)
					+ extractFileName(part);// file name
			String savePath = UPLOAD_DIR + fileName;
			InputStream is = part.getInputStream();
			Files.copy(is, Paths.get(savePath), StandardCopyOption.REPLACE_EXISTING);
		}
		return fileName;
	}

	private String extractFileName(Part part) {// Get file name
		String contentDisp = part.getHeader("content-disposition");
		String[] items = contentDisp.split(";");
		for (String s : items) {
			if (s.trim().startsWith("filename")) {
				return s.substring(s.indexOf("=") + 2, s.length() - 1);
			}
		}
		return "";
	}

	// get user id from session object
	private int getUserId(HttpServletRequest request) {
		int userid = 0;
		try {
			userid = (Integer) request.getSession().getAttribute("session_uid");
		} catch (NumberFormatException n) {
			n.printStackTrace();
		}
		return userid;
	}
}
