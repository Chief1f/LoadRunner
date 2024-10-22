Action()
{

	web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1729004222527\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	/*Connection ID 0 received buffer WebSocketReceive0*/
	
	lr_start_transaction("UC05_ReservationCancel");
	
	
//////////////HomePage//////////////

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

	
	
	web_reg_save_param_ex("ParamName=userSession","LB=name=\"userSession\" value=\"","RB=\"/>",LAST);

	web_reg_find("Text=A Session ID has been created",LAST);

	web_url("webtours", 
		"URL=http://localhost:1080/webtours", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("HomePage",LR_AUTO);
	
	lr_think_time(5);
	
	
//////////////Login//////////////
	
	lr_start_transaction("Login");

	web_add_auto_header("Priority", 
		"u=4");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");
	
	
	
	web_reg_find("Text=User password was correct",LAST);
	
	web_reg_find("Text=Welcome, <b>{userName}</b>, to the Web Tours reservation pages.",LAST);

	web_submit_form("login.pl", 
		"Snapshot=t11.inf", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={userName}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=login.x", "Value=51", ENDITEM,
		"Name=login.y", "Value=10", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);
	
	lr_think_time(5);
	
	
//////////////Itinerary//////////////	

	lr_start_transaction("Itinerary");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");


	
	web_reg_find("Text=User wants the intineraries.  Since user has already logged on",LAST);
	
	web_reg_save_param_ex("ParamName=flightID","LB=name=\"flightID\" value=\"","RB=\"","Ordinal=1",LAST);
	
	web_reg_find("Text={firstName} {lastName}",LAST);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t12.inf", 
		LAST);

	lr_end_transaction("Itinerary",LR_AUTO);
	
	lr_think_time(5);
	
	
//////////////CancelReservation//////////////	

	lr_start_transaction("CancelReservation");

	web_add_header("Origin", 
		"http://localhost:1080");



	web_submit_form("itinerary.pl", 
		"Snapshot=t13.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value={flightID}", ENDITEM,
        "Name=removeFlights.x", "Value=29", ENDITEM,
        "Name=removeFlights.y", "Value=7", ENDITEM,
        "Name=.cgifields", "Value=1", ENDITEM, 
		LAST);

	lr_end_transaction("CancelReservation",LR_AUTO);
	
	lr_think_time(5);
	
	
//////////////SignOff//////////////	

	lr_start_transaction("SignOff");
	
	web_reg_find("Text=Welcome to the Web Tours site.",LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t4.inf", 
		LAST);

	lr_end_transaction("SignOff",LR_AUTO);

	
	lr_end_transaction("UC05_ReservationCancel",LR_AUTO);

	return 0;
}