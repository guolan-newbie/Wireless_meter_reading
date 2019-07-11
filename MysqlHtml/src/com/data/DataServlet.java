package com.data;


import java.io.IOException;
import java.io.PrintWriter;
import java.sql.ResultSet;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.gson.Gson;

/**
 * Servlet implementation class DataServlet
 */
@WebServlet("/DataServlet")
public class DataServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DataServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		Connection con = null;
		Statement stmt = null;
		ResultSet rs = null;
		String dataId=request.getParameter("dataId");
		
		System.out.println("dataID"+dataId);
		if (dataId == null) {
			dataId ="1";
		}
		
		try{
			System.out.println("try:"+dataId);
			//加载驱动程序
			Class.forName("com.mysql.jdbc.Driver");
			//建立与数据库的连接
			con = DriverManager.getConnection(
					//"jdbc:mysql://127.0.0.1:3306/jsp4?useUnicode=true&characterEncoding=utf8","root","");
			"jdbc:mysql://127.0.0.1:3306/mysqlhtml","root","root");
			//查询所有数据SQL
			String sql = "select * from tb_data where dataId = "+ dataId;
			System.out.println(sql);
			//创建语句对象,用于执行SQL语句
			stmt = con.createStatement();
			//执行查询得到结果集
			rs = stmt.executeQuery(sql);
			//处理结果集
			Datas datas = new Datas();
			while(rs.next()){
				System.out.println(rs.getString(2));
				//分别得到当前行的第n列
				datas.setDataId(rs.getString(1));
				datas.setZheng(rs.getString(2));
				datas.setFan(rs.getString(3));
				datas.setShun(rs.getString(4));
				datas.setYa(rs.getString(5));
				datas.setTime(rs.getString(6));
				datas.setDataa(rs.getString(7));
				datas.setBiaohao(rs.getString(8));
				response.setContentType("application/json;charset=utf-8");
				response.getWriter().write(new Gson().toJson(datas));
				response.getWriter().flush();
				response.getWriter().close();
				System.out.println(new Gson().toJson(datas));
			}
			/*
			 * System.out.println(new Gson().toJson(datas)); PrintWriter out =
			 * response.getWriter(); out.print(new Gson().toJson(datas)); out.close();
			 */
		}catch(Exception e){
			e.printStackTrace();
		}finally{
			if(rs!=null){
				try{
					rs.close();
				}catch(Exception e){}
			}
			if(stmt!=null){
				try{
					stmt.close();
				}catch(Exception e){}
			}
			if(con!=null){
				try{
					con.close();
				}catch(Exception e){}
			}
		}
		
		//response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
