Action()
{
 int rnd1, rnd2, rnd3, rnd4;
 int NumberOfCities = 10;
 int NumberOfSeats = 3;
 int NumberOfTypes = 3;
 char Cities[10][20] = {"Denver", "Frankfurt", "London","Los Angeles","Paris","Portland","San Francisco","Seattle","Sydney","Zurich"};
 char seatPrefs[3][20] = {"Aisle", "Window", "None"};
 char seatTypes[3][20] = {"First", "Business", "Coach"};
 
 
 
	web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1727193748380\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	/*Connection ID 0 received buffer WebSocketReceive0*/
	
	lr_start_transaction("UC03_TicketBooking");
	
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
		"URL=http://localhost:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
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
		"Snapshot=t2.inf", 
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

	
//////////////FlightsPage//////////////		

	lr_start_transaction("FlightsPage");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	
	

	rnd1 = (rand() % NumberOfCities) + 1;
	
do {
        rnd2 = (rand() % NumberOfCities) + 1;
    } while (rnd1 == rnd2);

	rnd3 = (rand() % NumberOfSeats) + 1;
	rnd4 = (rand() % NumberOfTypes) + 1;
	
	lr_save_string(Cities[rnd1-1],"depart");
	lr_save_string(Cities[rnd2-1],"arrive");
	lr_save_string(seatPrefs[rnd3 - 1],"seatPref");
	lr_save_string(seatTypes[rnd4 - 1],"seatType");
	
	
	web_reg_find("Text=User has returned to the search page.  Since user has already logged on",LAST);
	
	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_end_transaction("FlightsPage",LR_AUTO);
	
	lr_think_time(5);
	
	
	//////////////FindFlight//////////////

	lr_start_transaction("FindFlight");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	

	web_reg_save_param_ex("ParamName=outboundFlight","LB=name=\"outboundFlight\" value=\"","RB=\" checked","Ordinal=1",LAST);
		
	web_reg_find("Text=Flight Selections",LAST);
	web_reg_find("Text=Flight departing from <B>{depart}</B> to <B>{arrive}</B>",LAST);
	
	
	web_submit_form("reservations.pl",
		"Snapshot=t4.inf",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={depart}", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value={arrive}", ENDITEM,
		"Name=returnDate", "Value={returnDate}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
	  //"Name=roundtrip", "Value=", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=findFlights.x", "Value=61", ENDITEM,
		"Name=findFlights.y", "Value=10", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		LAST);

	lr_end_transaction("FindFlight",LR_AUTO);

	lr_think_time(5);

	
//////////////ChooseFlight//////////////			
	
	lr_start_transaction("ChooseFlight");

	web_reg_find("Text=Flight Reservation",LAST);
	web_reg_find("Text={FirstName}",LAST);
	web_reg_find("Text={LastName}",LAST);
	
	web_submit_form("reservations.pl", 
		"Snapshot=t5.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
	  //"Name=returnFlight", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=reserveFlights.x", "Value=45", ENDITEM, 
		"Name=reserveFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("ChooseFlight",LR_AUTO);
	
	lr_think_time(5);

	
//////////////FillThePaymentDetails//////////////		
	
	lr_start_transaction("FillThePaymentDetails");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	

	    web_reg_find("Text=Reservation Made!",LAST);

		web_reg_find("Text=leaves {depart}  for {arrive}",LAST);
		
		web_reg_find("Text={FirstName}{LastName}'s Flight Invoice",LAST);
	
	web_submit_form("reservations.pl", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={StreetAdress}", ENDITEM, 
		"Name=address2", "Value={CityStateZip}", ENDITEM, 
		"Name=pass1", "Value={FirstName} {LastName}", ENDITEM, 
		"Name=creditCard", "Value=4634636", ENDITEM, 
		"Name=expDate", "Value=23", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=24", ENDITEM,
		"Name=buyFlights.y", "Value=7", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	lr_end_transaction("FillThePaymentDetails",LR_AUTO);
	
	lr_think_time(5);

	
//////////////SignOff//////////////		
	
	lr_start_transaction("SignOff");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	

	web_reg_find("Text=Welcome to the Web Tours site.",LAST);
	
	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t7.inf", 
		LAST);

	lr_end_transaction("SignOff",LR_AUTO);
	
	lr_end_transaction("UC03_TicketBooking",LR_AUTO);

	return 0;
}
