package com.acn.blog.service;

import java.util.List;

import com.acn.blog.beans.CategoryBean;
import com.acn.blog.dao.CategoryDAO;
import com.acn.blog.utility.Factory;

public class CategoryServiceImpl implements CategoryService {

	private CategoryDAO categoryDao;

	@Override
	public List<CategoryBean> getAllCategories() throws Exception {
		categoryDao = Factory.getCategoryDAO();
		return categoryDao.getAllCategories();
	}

}
