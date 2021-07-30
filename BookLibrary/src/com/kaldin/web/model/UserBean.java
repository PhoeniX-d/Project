package com.kaldin.web.model;

public class UserBean {

	// User related fields
	int uId;			// user id
	String uName;		// user name
	String uPwd;		// user password
	String uEmail;		// user email
	long uMob;			// user mobile no

	// constructor to get User data
	public UserBean(int uId, String uName, String uPwd, String uEmail, long uMob) {
		super();
		this.uId = uId;
		this.uName = uName;
		this.uPwd = uPwd;
		this.uEmail = uEmail;
		this.uMob = uMob;
	}

	// various getters methods
	public int getuId() {
		return uId;
	}

	public String getuName() {
		return uName;
	}

	public String getuPwd() {
		return uPwd;
	}

	public String getuEmail() {
		return uEmail;
	}

	public long getuMob() {
		return uMob;
	}
}
