package com.kaldin.web.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import com.kaldin.web.model.BookBean;

/*
 * Author		: Pranav Choudhary
 * Date			: 24 July 2021
 * Class		: BookDAO
 * Description	: Contains Data Access code for Books
 * 
 */

public class BookDAO {

	private static final String SELECT_A_BOOK = "select * from books where bid = ?;";
	private static final String SELECT_ALL_BOOKS = "select * from books;";
	private static final String INSERT_NEW_BOOK = "insert into books values(?, ?, ?, ?, ?, ?);";
	private static final String DELETE_A_BOOK = "delete from books where bid = ?;";
	private static final String GET_ID = "select bid from books where bname = ?;";
	private static final String UPDATE_BOOK = "update books set bname = ?, bauthor = ?, bcategory = ?, bprice = ?, bpages = ? where bid = ?;";
	private GetConnection getCon;

	public BookDAO() {
		getCon = new GetConnection();
		getCon.getConnection();
	}

	public int generateBID() {
		// To generate random unique book id
		Random random = new Random();
		String bid = String.format("%05d", random.nextInt(100000));
		return Integer.parseInt(bid);
	}

	// code to get Id from database using book name
	public int getId(String bookName) {
		int bid = 0;
		// try with resources
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(GET_ID)) {
			pst.setString(1, bookName);
			ResultSet rs = pst.executeQuery();
			if (rs.next())
				bid = rs.getInt(1);
			rs.close();
			return bid;
		} catch (SQLException e) {
			printSQLException(e);
		}
		return bid;
	}

	// code to insert values into BOOKs database
	public void insertBook(BookBean book) {
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(INSERT_NEW_BOOK)) {
			// inserting book's id
			pst.setInt(1, generateBID());

			// inserting book's name
			pst.setString(2, book.getbName());

			// inserting book's author
			pst.setString(3, book.getbAuthor());

			// inserting book's category
			pst.setString(4, book.getbCategory());

			// inserting book's price
			pst.setDouble(5, book.getbPrice());

			// inserting book's total number of pages
			pst.setInt(6, book.getbPageCounts());

			pst.executeUpdate();
		} catch (SQLException e) {
			printSQLException(e);
		}
	}

	// code to fetch values of a particular BOOK from database
	public BookBean selectBook(String bookName) {
		BookBean book = null;
		int bid = getId(bookName);
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(SELECT_A_BOOK)) {
			pst.setInt(1, bid);
			ResultSet rs = pst.executeQuery();

			// | bid | bname| bauthor | bcategory | bprice | bpages |
			if (rs.next()) {
				bid = rs.getInt(1);
				String name = rs.getString(2);
				String author = rs.getString(3);
				String category = rs.getString(4);
				double price = rs.getDouble(5);
				int pages = rs.getInt(6);
				book = new BookBean(bid, name, author, category, price, pages);
			}
		} catch (SQLException e) {
			printSQLException(e);
		}
		return book;
	}

	// code to fetch all Books information
	public List<BookBean> selectAllBooks() {
		List<BookBean> books = new ArrayList<>();
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(SELECT_ALL_BOOKS)) {
			ResultSet rs = pst.executeQuery();
			// | bid | bname| bauthor | bcategory | bprice | bpages |
			while (rs.next()) {
				int bid = rs.getInt(1);
				String name = rs.getString(2);
				String author = rs.getString(3);
				String category = rs.getString(4);
				double price = rs.getDouble(5);
				int pages = rs.getInt(6);
				books.add(new BookBean(bid, name, author, category, price, pages));
			}
		} catch (SQLException e) {
			printSQLException(e);
		}
		return books;
	}

	// code to delete a Book from database
	public boolean deleteABook(String bookName) {
		int bid = getId(bookName);
		boolean rowDeleted = false;
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(DELETE_A_BOOK)) {
			pst.setInt(1, bid);
			rowDeleted = pst.executeUpdate() > 0;
		} catch (SQLException e) {
			printSQLException(e);
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
			pst.setInt(5, book.getbId());
			rowUpdated = pst.executeUpdate() > 0;
		} catch (SQLException e) {
			printSQLException(e);
		}
		return rowUpdated;
	}

	private void printSQLException(SQLException ex) {
		for (Throwable e : ex) {
			if (e instanceof SQLException) {
				e.printStackTrace(System.err);
				System.err.println("SQLState: " + ((SQLException) e).getSQLState());
				System.err.println("Error Code: " + ((SQLException) e).getErrorCode());
				System.err.println("Message: " + e.getMessage());
				Throwable t = ex.getCause();
				while (t != null) {
					System.out.println("Cause: " + t);
					t = t.getCause();
				}
			}
		}
	}
}
