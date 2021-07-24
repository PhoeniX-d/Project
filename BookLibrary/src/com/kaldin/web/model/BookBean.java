package com.kaldin.web.model;

public class BookBean {

	// Book related fields
	int bId;
	String bName;
	String bAuthor;
	String bCategory;
	double bPrice;
	int bPageCounts;

	// constructors
	public BookBean(int bId, String bName, String bAuthor, String bCategory, double bPrice, int bPageCounts) {
		super();
		this.bId = bId;
		this.bName = bName;
		this.bAuthor = bAuthor;
		this.bCategory = bCategory;
		this.bPrice = bPrice;
		this.bPageCounts = bPageCounts;
	}

	// various getters and setters methods
	public int getbId() {
		return bId;
	}

	public void setbId(int bId) {
		this.bId = bId;
	}

	public String getbName() {
		return bName;
	}

	public void setbName(String bName) {
		this.bName = bName;
	}

	public String getbAuthor() {
		return bAuthor;
	}

	public void setbAuthor(String bAuthor) {
		this.bAuthor = bAuthor;
	}

	public String getbCategory() {
		return bCategory;
	}

	public void setbCategory(String bCategory) {
		this.bCategory = bCategory;
	}

	public double getbPrice() {
		return bPrice;
	}

	public void setbPrice(double bPrice) {
		this.bPrice = bPrice;
	}

	public int getbPageCounts() {
		return bPageCounts;
	}

	public void setbPageCounts(int bPageCounts) {
		this.bPageCounts = bPageCounts;
	}
}
