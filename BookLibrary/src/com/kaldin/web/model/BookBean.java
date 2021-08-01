package com.kaldin.web.model;

public class BookBean {

	// Book related fields
	int bId; // book id
	int uId; // user id
	String bName; // book name
	String bAuthor; // author name
	String bCategory; // book category
	double bPrice; // book price
	int bPageCounts; // books total pages
	String imgName; // name of image
	String bLang; // language of book

	// parameterized constructors
	public BookBean(int bId, int uId, String bName, String bAuthor, String bCategory, double bPrice, int bPageCounts,
			String imgName, String bLang) {
		super();
		this.bId = bId;
		this.uId = uId;
		this.bName = bName;
		this.bAuthor = bAuthor;
		this.bCategory = bCategory;
		this.bPrice = bPrice;
		this.bPageCounts = bPageCounts;
		this.imgName = imgName;
		this.bLang = bLang;
	}

	public String getImgName() {
		return imgName;
	}

	public void setImgName(String imgName) {
		this.imgName = imgName;
	}

	// various getters methods
	public int getbId() {
		return bId;
	}

	public int getuId() {
		return uId;
	}

	public String getbName() {
		return bName;
	}

	public String getbAuthor() {
		return bAuthor;
	}

	public String getbCategory() {
		return bCategory;
	}

	public double getbPrice() {
		return bPrice;
	}

	public int getbPageCounts() {
		return bPageCounts;
	}

	public String getbLang() {
		return bLang;
	}
}
