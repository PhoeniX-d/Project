package com.acn.blog.service;

import java.util.List;

import com.acn.blog.beans.CategoryBean;

public interface CategoryService {
	public List<CategoryBean> getAllCategories() throws Exception;
}
