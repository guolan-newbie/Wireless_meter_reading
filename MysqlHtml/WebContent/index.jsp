<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<title>水表数据</title>
	<meta charset="utf-8">
	<style type="text/css">
		body{
			margin: 0;
			padding: 0;
			background-image: url("2.jpg");
			width: 100%;
			font-size:34px;
			font-style: bold;
		}
		li {
			list-style: none;
			margin: 20px auto;
		}
		
	</style>
	<script src="./jQuery.js"></script>
<!-- <script src="http://code.jquery.com/jquery-2.1.1.min.js"></script> -->
</head>
<body>
	<div style="text-align:center;">
		<p>水表的数据</p>
		
		<form action="DataServlet" method="post" id="formId">
		<select name="dataId" onchange="updateData(this.options[this.options.selectedIndex].value)">
		  <option value ="1">第一次查询</option>
		  <option value ="2">第二次查询</option>
		  <option value="3">第三次查询</option>
		  <option value="4">第四次查询</option>
		  <option value="5">第五次查询</option>
		</select>
			<ul>
				<li><label for="positivetotal">正向总量<input type="text" name="positivetotal" id="positivetotal" value="未知"></label></li>
				<li><label for="negativetotal">负向总量<input type="text" name="negativetotal" id="negativetotal" value="未知"></label></li>
				<li><label for="instantvalue">瞬时流量<input type="text" name="instantvalue" id="instantvalue" value="未知"></label></li>
				<li><label for="voltage">电压<input type="text" name="voltage" id="voltage" value="未知"></label></li>
				<li><label for="time">抄表时间<input type="text" name="time" id="time" value="未知"></label></li>
				<li><label for="data">上传数据<input type="text" name="data" id="data" value="未知"></label></li>
				<li><label for="watchno">水表编号<input type="text" name="watchno" id="watchno" value="未知"></label></li>
			</ul>
			
		</form>
	</div>
	<script type="text/javascript">
	$().ready(function() {
		jQuery.alertWindow("读取中.......");
 		$.ajax({
			type : "get",
			async : true, //同步请求
			url : "DataServlet",
			data : {},
			cache : false,
			dataType : "json",
			success : function(data) {
				$("#positivetotal").val(data.zheng);
				$("#negativetotal").val(data.fan);
				$("#instantvalue").val(data.shun);
				$("#voltage").val(data.ya);
				$("#time").val(data.time);
				$("#data").val(data.dataa);
				$("#watchno").val(data.biaohao);
			}
 		}); 
 		
 		
 	});
	
	//更改
	function updateData(dataId){
		jQuery.alertWindow("读取中.......");
		//alert(dataId);
		$.ajax({
			type : "post",
			async : true, //同步请求
			url : "DataServlet?dataId="+dataId,
			data : dataId,
			cache : false,
			dataType : "json",
			success : function(data) {
				console.log(data);
				$("#positivetotal").val(data.zheng);
				$("#negativetotal").val(data.fan);
				$("#instantvalue").val(data.shun);
				$("#voltage").val(data.ya);
				$("#time").val(data.time);
				$("#data").val(data.dataa);
				$("#watchno").val(data.biaohao);
			}
 		});
 		
	}
	
	
	 jQuery.extend({
		   	alertWindow:function(e,n){var e=e,r;n===undefined?r="#00a8b7":r=n;
		   	if($("body").find(".alertWindow1").length===0){
		   		var i='<div class="alertWindow1" style="width: 100%;height: 200%; background:rgba(0,0,0,0.5);position: fixed; left:0px; top: 0px; z-index: 9999;"><div  style="width: 460px; height: 370px;background: #FFF;margin: 100px auto;border: 2px solid #CFCFCF;">'+'<div  style="width: inherit;height: 20px;">'+'<div class="alertWindowCloseButton1" style="float: right; width: 10px; height: 30px;margin-right:5px;font-family:\'microsoft yahei\';color:'+r+';cursor: pointer;"></div>'+"</div>"+'<div id="successImg" class="alertWindowTitle" style="margin-top:10px;text-align:center;font-family:\'Verdana, Geneva, Arial, Helvetica, sans-serif\';font-size: 40px;font-weight: normal;color: '+r+';">'+"</div>"+'<div class="alertWindowContent" style="width:360px;height: 40px;text-align:center;font-size: 18px;color: #7F7F7F;margin-top:10px;">'+e+"</div>"+"</div>"+"</div>";
		   		$("body").append(i);
		   		var s=$(".alertWindow1");
		   		//2秒后自动关闭窗口
		   		setTimeout(function(){s.hide()},1000);
		   	}
		   	else {$(".alertWindowContent").text(e),$(".alertWindow1").show(),setTimeout(function(){$(".alertWindow1").hide()},1000);}
		   	}
		}) 
	</script>
</body>
</html>