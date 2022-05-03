package com.acn.blog.beans;

import java.sql.Timestamp;

public class CommentBean {

	private Integer cid;
	private Integer cpostId;
	private Integer cuserId;
	private String comments;
	private Timestamp timeStamp;

	public Integer getCid() {
		return cid;
	}

	public void setCid(Integer cid) {
		this.cid = cid;
	}

	public Integer getCpostId() {
		return cpostId;
	}

	public void setCpostId(Integer cpostId) {
		this.cpostId = cpostId;
	}

	public Integer getCuserId() {
		return cuserId;
	}

	public void setCuserId(Integer cuserId) {
		this.cuserId = cuserId;
	}

	public String getComments() {
		return comments;
	}

	public void setComments(String comments) {
		this.comments = comments;
	}

	public Timestamp getTimeStamp() {
		return timeStamp;
	}

	public void setTimeStamp(Timestamp timeStamp) {
		this.timeStamp = timeStamp;
	}

	public CommentBean() {
		super();
	}

}
