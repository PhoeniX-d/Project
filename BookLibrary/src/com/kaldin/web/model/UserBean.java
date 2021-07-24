package com.kaldin.web.model;

public class UserBean {

	// User related fields
	int uId;
	String uName;
	String uPwd;
	String uEmail;
	long uMob;

	// constructor to get User data
	public UserBean(int uId, String uName, String uPwd, String uEmail, long uMob) {
		super();
		this.uId = uId;
		this.uName = uName;
		this.uPwd = uPwd;
		this.uEmail = uEmail;
		this.uMob = uMob;
	}

	// various getters and setters methods
	public int getuId() {
		return uId;
	}

	public void setuId(int uId) {
		this.uId = uId;
	}

	public String getuName() {
		return uName;
	}

	public void setuName(String uName) {
		this.uName = uName;
	}

	public String getuPwd() {
		return uPwd;
	}

	public void setuPwd(String uPwd) {
		this.uPwd = uPwd;
	}

	public String getuEmail() {
		return uEmail;
	}

	public void setuEmail(String uEmail) {
		this.uEmail = uEmail;
	}

	public long getuMob() {
		return uMob;
	}

	public void setuMob(long uMob) {
		this.uMob = uMob;
	}
}
