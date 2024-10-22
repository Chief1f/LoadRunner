Action()
{

	web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1729104972347\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	/*Connection ID 0 received buffer WebSocketReceive0*/

	lr_start_transaction("HomePage");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Priority", 
		"u=0, i");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Sec-GPC", 
		"1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(16);

	web_url("webtours", 
		"URL=http://localhost:1080/webtours", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("HomePage",LR_AUTO);

	lr_start_transaction("Login");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Priority", 
		"u=4");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(12);

	web_submit_form("login.pl", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_start_transaction("FlightsPage");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(17);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t9.inf", 
		LAST);

	lr_end_transaction("FlightsPage",LR_AUTO);

	lr_start_transaction("FindFlight");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(15);

	web_submit_form("reservations.pl", 
		"Snapshot=t10.inf", 
		ITEMDATA, 
		"Name=depart", "Value=London", ENDITEM, 
		"Name=departDate", "Value=10/18/2024", ENDITEM, 
		"Name=arrive", "Value=Los Angeles", ENDITEM, 
		"Name=returnDate", "Value=10/19/2024", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		LAST);

	lr_end_transaction("FindFlight",LR_AUTO);

	lr_think_time(14);

	lr_start_transaction("ChooseFlight");

	web_submit_form("reservations.pl_2", 
		"Snapshot=t11.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=232;731;10/18/2024", ENDITEM, 
		"Name=reserveFlights.x", "Value=43", ENDITEM, 
		"Name=reserveFlights.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("ChooseFlight",LR_AUTO);

	lr_start_transaction("Itinerary");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	lr_think_time(15);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t12.inf", 
		LAST);

	lr_end_transaction("Itinerary",LR_AUTO);

	lr_start_transaction("SignOff");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(13);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t13.inf", 
		LAST);

	lr_end_transaction("SignOff",LR_AUTO);

	return 0;
}