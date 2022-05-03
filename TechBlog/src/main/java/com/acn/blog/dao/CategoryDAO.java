package com.acn.blog.dao;

import java.util.List;

import com.acn.blog.beans.CategoryBean;

public interface CategoryDAO {

	public List<CategoryBean> getAllCategories() throws Exception;
}
