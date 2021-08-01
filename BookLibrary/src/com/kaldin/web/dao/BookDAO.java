package com.kaldin.web.dao;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.kaldin.web.model.BookBean;

/*
 * Author		: Pranav Choudhary
 * Date			: 24 July 2021
 * Class		: BookDAO
 * Description	: Contains Data Access code for Books
 * 
 */

public class BookDAO {

	private static final String SELECT_A_BOOKS = "select * from books where bid = ?;";
	private static final String SELECT_ALL_BOOKS = "select * from books where uid = ?;";
	private static final String VIEW_AUTHOR = "select imgpath from books where bid = ?";
	private static final String EDIT_AUTHOR = "update books set imgpath = ? where bid = ?";
	private static final String INSERT_NEW_BOOK = "insert into books(uid, bname, bauthor, bcategory, bprice, bpages, imgpath, blang) values(?, ?, ?, ?, ?, ?, ?, ?);";
	private static final String DELETE_A_BOOK = "delete from books where bid = ?;";
	private static final String UPDATE_BOOK = "update books set bname = ?, bauthor = ?, bcategory = ?, bprice = ?, bpages = ?, blang = ? where bid = ?;";
	private GetConnection getCon;

	public BookDAO() {
		getCon = new GetConnection();
		getCon.getConnection();
	}

	// code to insert values into BOOKs database
	public void insertBook(BookBean book) {
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(INSERT_NEW_BOOK)) {
			// inserting book's id
			pst.setInt(1, book.getuId());

			// inserting book's name
			pst.setString(2, book.getbName());

			// inserting book's author
			pst.setString(3, book.getbAuthor());

			// inserting book's category
			pst.setString(4, book.getbCategory());

			// inserting book's price
			double price = book.getbPrice();
			if (price == -1) {
				pst.setDouble(5, -1);
			} else {
				pst.setDouble(5, price);
			}

			// inserting book's total number of pages
			int pages = book.getbPageCounts();
			if (pages == -1) {
				pst.setInt(6, -1);
			} else {
				pst.setInt(6, pages);
			}
			pst.setString(7, book.getImgName());
			pst.setString(8, book.getbLang());
			pst.executeUpdate();
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}
	}

	// code to fetch book's information
	public BookBean selectABooks(int bookid) throws IOException {
		BookBean book = null;
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(SELECT_A_BOOKS)) {
			pst.setInt(1, bookid);
			ResultSet rs = pst.executeQuery();
			// | bid | bname| bauthor | bcategory | bprice | bpages | imgpath | language
			if (rs.next()) {
				int bid = rs.getInt(1);
				int uid = 0;
				String name = rs.getString(3);
				String author = rs.getString(4);
				String category = rs.getString(5);
				double price = rs.getDouble(6);
				int pages = rs.getInt(7);
				String imgName = "";
				String lang = rs.getString(9);
				book = new BookBean(bid, uid, name, author, category, price, pages, imgName, lang);
			}
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}
		return book;
	}

	// code to fetch all Books information
	public List<BookBean> selectAllBooks(int userid) throws IOException {
		List<BookBean> books = new ArrayList<>();
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(SELECT_ALL_BOOKS)) {
			pst.setInt(1, userid);
			ResultSet rs = pst.executeQuery();
			// | bid | bname| bauthor | bcategory | bprice | bpages | imgpath | language
			while (rs.next()) {
				int bid = rs.getInt(1);
				int uid = 0;
				String name = rs.getString(3);
				String author = rs.getString(4);
				String category = rs.getString(5);
				double price = rs.getDouble(6);
				int pages = rs.getInt(7);
				String imgName = rs.getString(8);
				String lang = rs.getString(9);
				books.add(new BookBean(bid, uid, name, author, category, price, pages, imgName, lang));
			}
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}
		return books;
	}

	// code to fetch all Books information
	public String viewAuthor(int bid) throws IOException {
		String imagePath = null;
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(VIEW_AUTHOR)) {
			pst.setInt(1, bid);
			ResultSet rs = pst.executeQuery();
			if (rs.next()) {
				imagePath = rs.getString(1);
			}
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}
		return imagePath;
	}

	// code to edit authors image
	public void editAuthor(int bid, String imgpath) throws IOException {
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(EDIT_AUTHOR)) {
			pst.setInt(2, bid);
			pst.setString(1, imgpath);
			pst.executeUpdate();
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}
	}

	// code to delete a Book from database
	public boolean deleteABook(int bid) {
		boolean rowDeleted = false;
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(DELETE_A_BOOK)) {
			pst.setInt(1, bid);
			rowDeleted = pst.executeUpdate() > 0;
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}
		return rowDeleted;
	}

	// code to update Book information
	public boolean updateBook(BookBean book) {
		boolean rowUpdated = false;
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(UPDATE_BOOK)) {
			pst.setString(1, book.getbName());
			pst.setString(2, book.getbAuthor());
			pst.setString(3, book.getbCategory());
			pst.setDouble(4, book.getbPrice());
			pst.setInt(5, book.getbPageCounts());
			pst.setInt(7, book.getbId());
			pst.setString(6, book.getbLang());
			rowUpdated = pst.executeUpdate() > 0;
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}
		return rowUpdated;
	}
}
