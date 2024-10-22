Action()
{

	web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1729004222527\\\"\"},\"use_webpush\":true}", 
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

	lr_think_time(37);

	web_url("webtours", 
		"URL=http://localhost:1080/webtours", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("HomePage",LR_AUTO);

	lr_start_transaction("Login");

	web_add_auto_header("Priority", 
		"u=4");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_submit_form("login.pl", 
		"Snapshot=t11.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_start_transaction("Itinenary");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(19);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t12.inf", 
		LAST);

	lr_end_transaction("Itinenary",LR_AUTO);

	lr_start_transaction("CancelReservation");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(36);

	web_submit_form("itinerary.pl", 
		"Snapshot=t13.inf", 
		ITEMDATA, 
		"Name=1", "Value=<OFF>", ENDITEM, 
		"Name=2", "Value=<OFF>", ENDITEM, 
		"Name=3", "Value=<OFF>", ENDITEM, 
		"Name=4", "Value=on", ENDITEM, 
		"Name=5", "Value=<OFF>", ENDITEM, 
		"Name=6", "Value=<OFF>", ENDITEM, 
		"Name=7", "Value=<OFF>", ENDITEM, 
		"Name=8", "Value=<OFF>", ENDITEM, 
		"Name=9", "Value=<OFF>", ENDITEM, 
		"Name=10", "Value=<OFF>", ENDITEM, 
		LAST);

	lr_end_transaction("CancelReservation",LR_AUTO);

	lr_think_time(15);

	lr_start_transaction("SignOff");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t14.inf", 
		LAST);

	lr_end_transaction("SignOff",LR_AUTO);

	return 0;
}