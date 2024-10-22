Action()
{

	web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1727341031559\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	/*Connection ID 0 received buffer WebSocketReceive0*/

	lr_start_transaction("HomePage");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Priority", 
		"u=0, i");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-GPC", 
		"1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(22);

	web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("HomePage",LR_AUTO);

	lr_start_transaction("SignUp");

	web_add_auto_header("Priority", 
		"u=4");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	lr_think_time(14);

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t2.inf", 
		LAST);

	lr_end_transaction("SignUp",LR_AUTO);

	lr_start_transaction("FillTheRegistrationForm");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(19);

	web_submit_form("login.pl", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=username", "Value=abub", ENDITEM, 
		"Name=password", "Value=abub", ENDITEM, 
		"Name=passwordConfirm", "Value=abub", ENDITEM, 
		"Name=firstName", "Value=abub", ENDITEM, 
		"Name=lastName", "Value=abub", ENDITEM, 
		"Name=address1", "Value=abub", ENDITEM, 
		"Name=address2", "Value=abub", ENDITEM, 
		"Name=register.x", "Value=59", ENDITEM, 
		"Name=register.y", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("FillTheRegistrationForm",LR_AUTO);

	lr_start_transaction("Continue");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	lr_think_time(11);

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t4.inf", 
		LAST);

	lr_end_transaction("Continue",LR_AUTO);

	lr_start_transaction("SignOff");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(17);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t5.inf", 
		LAST);

	lr_end_transaction("SignOff",LR_AUTO);

	return 0;
}