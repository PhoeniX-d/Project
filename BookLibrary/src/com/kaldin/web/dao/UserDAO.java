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

	private static final String SELECT_ALL_USERS = "select * from users;";
	private static final String INSERT_NEW_USER = "insert into users(uname, upwd, uemail, umob) values(?, ?, ?, ?);";
	private static final String DELETE_A_USER = "delete from users where uid = ?;";
	private static final String DELETE_A_USER_BOOKS = "delete from books where uid = ?;";
	private static final String GET_ID = "select uid from users where uemail = ?;";
	private static final String GET_NAME = "select uname from users where uemail = ?;";
	private static final String UPDATE_USER = "update users set uname = ?, upwd = ?, uemail = ?, umob = ? where uid = ?;";
	private static final String CHECK_CREDS1 = "select * from users where uemail = ? and upwd = ?;";
	private static final String CHECK_CREDS2 = "select * from users where uemail = ?;";
	private GetConnection getCon;

	public UserDAO() {
		getCon = new GetConnection();
		getCon.getConnection();
	}

	// code to validate user credentials
	public int check(String uemail, String upwd) {
		int ret = 0;
		Connection con = getCon.getConnection();
		try (PreparedStatement pst = con.prepareStatement(CHECK_CREDS1)) {
			pst.setString(1, uemail);
			pst.setString(2, upwd);
			ResultSet rs = pst.executeQuery();
			if (rs.next()) {
				ret = 2;
			}
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}

		if (ret == 0) {
			try (PreparedStatement pst = con.prepareStatement(CHECK_CREDS2)) {
				pst.setString(1, uemail);
				ResultSet rs = pst.executeQuery();
				if (rs.next()) {
					ret = 1;
				}
			} catch (SQLException e) {
				GetConnection.printSQLException(e);
			}
		}
		return ret;
	}

	// code to get Id from database using uemail
	public int getId(String userEmail) {
		int uid = 0;
		Connection con = getCon.getConnection();
		// try with resources
		try (PreparedStatement pst = con.prepareStatement(GET_ID)) {
			pst.setString(1, userEmail);
			ResultSet rs = pst.executeQuery();
			if (rs.next())
				uid = rs.getInt(1);
			rs.close();
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}
		return uid;
	}

	// code to get user name from database to greet
	public String getName(String userEmail) {
		String userName = null;
		Connection con = getCon.getConnection();
		try (PreparedStatement pst = con.prepareStatement(GET_NAME)) {
			pst.setString(1, userEmail);
			ResultSet rs = pst.executeQuery();
			if (rs.next())
				userName = rs.getString(1);
			rs.close();
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}
		return userName;
	}

	// code to insert values into users database
	public void insertUser(UserBean user) {
		Connection con = getCon.getConnection();
		try (PreparedStatement pst = con.prepareStatement(INSERT_NEW_USER)) {
			// inserting user name
			pst.setString(1, user.getuName());

			// inserting user password
			pst.setString(2, user.getuPwd());

			// inserting user email id
			pst.setString(3, user.getuEmail());

			// inserting user mobile number
			long mobile = user.getuMob();
			if (mobile == -1) {
				pst.setLong(4, -1L);
			} else {
				pst.setLong(4, mobile);
			}
			pst.executeUpdate();
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}
	}

	// code to fetch all users information
	public List<UserBean> selectAllUsers() {
		List<UserBean> users = new ArrayList<>();
		Connection con = getCon.getConnection();
		try (PreparedStatement pst = con.prepareStatement(SELECT_ALL_USERS)) {
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
			GetConnection.printSQLException(e);
		}
		return users;
	}

	// code to delete a user from database
	public void deleteAUser(String userEmail) {
		int uid = getId(userEmail);
		Connection con = getCon.getConnection();
		try (PreparedStatement pst = con.prepareStatement(DELETE_A_USER);
				PreparedStatement pst1 = con.prepareStatement(DELETE_A_USER_BOOKS)) {
			pst1.setInt(1, uid);
			pst.setInt(1, uid);
			pst.executeUpdate();
			pst1.executeUpdate();
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}
	}

	// code to update user information
	public boolean updateUser(UserBean user) {
		boolean rowUpdated = false;
		Connection con = getCon.getConnection();

		try (PreparedStatement pst = con.prepareStatement(UPDATE_USER)) {
			pst.setString(1, user.getuName());
			pst.setString(2, user.getuPwd());
			pst.setString(3, user.getuEmail());
			pst.setLong(4, user.getuMob());
			pst.setInt(5, user.getuId());
			rowUpdated = pst.executeUpdate() > 0;
		} catch (SQLException e) {
			GetConnection.printSQLException(e);
		}
		return rowUpdated;
	}
}
