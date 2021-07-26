package com.kaldin.web.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import com.kaldin.web.model.UserBean;

/*
 * Author		: Pranav Choudhary
 * Date			: 24 July 2021
 * Class		: UserDAO
 * Description	: Contains Data Access code for Users
 * 
 */

public class UserDAO {

	private static final String SELECT_A_USER = "select * from users where uid = ?;";
	private static final String SELECT_ALL_USERS = "select * from users;";
	private static final String INSERT_NEW_USER = "insert into users values(?, ?, ?, ?, ?);";
	private static final String DELETE_A_USER = "delete from users where uid = ?;";
	private static final String GET_ID = "select uid from users where uemail = ?;";
	private static final String GET_NAME = "select uname from users where uemail = ?;";
	private static final String UPDATE_USER = "update users set uname = ?, upwd = ?, uemail = ?, umob = ? where uid = ?;";
	private static final String CHECK_CREDS = "select * from users where uemail = ? and upwd = ?;";
	private GetConnection getCon;

	public UserDAO() {
		getCon = new GetConnection();
		getCon.getConnection();
	}
	
	// code to validate user credentials
	public boolean check(String uemail, String upwd) {
		try(Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(CHECK_CREDS)) {
			pst.setString(1, uemail);
			pst.setString(2, upwd);
			ResultSet rs = pst.executeQuery();
			if(rs.next()) {
				return true;
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return false;
	}

	public int generateUID() {
		// To generate random unique user id
		Random random = new Random();
		String uid = String.format("%04d", random.nextInt(10000));
		return Integer.parseInt(uid);
	}

	// code to get Id from database using uemail
	public int getId(String userEmail) {
		int uid = 0;
		// try with resources
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(GET_ID)) {
			pst.setString(1, userEmail);
			System.out.println(pst);
			ResultSet rs = pst.executeQuery();
			if (rs.next())
				uid = rs.getInt(1);
			rs.close();
		} catch (SQLException e) {
			printSQLException(e);
		}
		return uid;
	}
	
	// code to get user name from database to greet
	public String getName(String userEmail) {
		String userName = null;
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(GET_NAME)) {
			pst.setString(1, userEmail);
			System.out.println(pst);
			ResultSet rs = pst.executeQuery();
			if (rs.next())
				userName = rs.getString(1);
			rs.close();
		} catch (SQLException e) {
			printSQLException(e);
		}
		return userName;
	}
	
	// code to insert values into users database
	public void insertUser(UserBean user) {
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(INSERT_NEW_USER)) {
			// inserting user id
			pst.setInt(1, user.getuId());

			// inserting user name
			pst.setString(2, user.getuName());

			// inserting user password
			pst.setString(3, user.getuPwd());

			// inserting user email id
			pst.setString(4, user.getuEmail());

			// inserting user mobile number
			pst.setLong(5, user.getuMob());

			pst.executeUpdate();
		} catch (SQLException e) {
			printSQLException(e);
		}
	}

	// code to fetch values of a particular user from database
	public UserBean selectUser(String userEmail) {
		UserBean user = null;
		int uid = getId(userEmail);
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(SELECT_A_USER)) {
			pst.setInt(1, uid);
			ResultSet rs = pst.executeQuery();

			// uid | uname | upwd | uemail | umob
			if (rs.next()) {
				uid = rs.getInt(1);
				String name = rs.getString(2);
				String pwd = rs.getString(3);
				String email = rs.getString(4);
				long mob = rs.getLong(5);
				user = new UserBean(uid, name, pwd, email, mob);
			}
		} catch (SQLException e) {
			printSQLException(e);
		}
		return user;
	}

	// code to fetch all users information
	public List<UserBean> selectAllUsers() {
		List<UserBean> users = new ArrayList<>();
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(SELECT_ALL_USERS)) {
			ResultSet rs = pst.executeQuery();

			// uid | uname | upwd | uemail | umob
			while (rs.next()) {
				int uid = rs.getInt(1);
				String name = rs.getString(2);
				String pwd = rs.getString(3);
				String email = rs.getString(4);
				long mob = rs.getLong(5);
				users.add(new UserBean(uid, name, pwd, email, mob));
			}
		} catch (SQLException e) {
			printSQLException(e);
		}
		return users;
	}

	// code to delete a user from database
	public boolean deleteAUser(String userEmail) {
		int uid = getId(userEmail);
		System.out.println(uid);
		boolean rowDeleted = false;
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(DELETE_A_USER)) {
			pst.setInt(1, uid);
			rowDeleted = pst.executeUpdate() > 0;
		} catch (SQLException e) {
			printSQLException(e);
		}
		return rowDeleted;
	}

	// code to update user information
	public boolean updateUser(UserBean user) {
		boolean rowUpdated = false;
		try (Connection con = getCon.getConnection(); PreparedStatement pst = con.prepareStatement(UPDATE_USER)) {
			pst.setString(1, user.getuName());
			pst.setString(2, user.getuPwd());
			pst.setString(3, user.getuEmail());
			pst.setLong(4, user.getuMob());
			pst.setInt(5, user.getuId());
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
