package com.kaldin.web.dao;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.Properties;
import com.mysql.cj.jdbc.*;

public class GetConnection {

	private Connection con = null;

	// Get connection reference
	protected Connection getConnection() {
		if (con == null) {
			Properties p = new Properties();
			InputStream is;
			try {
				is = this.getClass().getResourceAsStream("/resources/db.properties");
				p.load(is);
				MysqlConnectionPoolDataSource ds = new MysqlConnectionPoolDataSource();
				ds.setURL(p.getProperty("MysqlURL"));
				ds.setUser(p.getProperty("MysqlUser"));
				ds.setPassword(p.getProperty("MysqlPwd"));
				Class.forName("com.mysql.cj.jdbc.Driver");
				con = ds.getConnection();
			} catch (IOException io) {
				io.printStackTrace();
			} catch (SQLException sqle) {
				printSQLException(sqle);
			} catch (ClassNotFoundException cnf) {
				cnf.printStackTrace();
			}
		}
		return con;
	}

	protected void finalize() {
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
