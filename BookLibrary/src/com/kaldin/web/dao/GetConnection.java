package com.kaldin.web.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class GetConnection {

	private String jdbcURL = "jdbc:mysql://localhost:3306/booklib";
	private String jdbcUsername = "root";
	private String jdbcPassword = "";
	private Connection con = null;

	// Get connection reference
	protected Connection getConnection() {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			con = DriverManager.getConnection(jdbcURL, jdbcUsername, jdbcPassword);
		} catch (SQLException sqle) {
			printSQLException(sqle);
		} catch (ClassNotFoundException cnf) {
			cnf.printStackTrace();
		}
		return con;
	}

	protected void closeConnection() {
		try {
			con.close();
		} catch (SQLException e) {
			printSQLException(e);
		}
	}

	// Generic method to display error
	public static void printSQLException(SQLException ex) {
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
