




Action()
{
 
	int i;
 
 
 char userName[6] = "";
 char password[6] = "";
 char firstName[6] = "";
 char lastName[6] = "";
 char address1[6] = "";
 char address2[6] = "";
 
 char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
 for(i = 0; i < 5; i++)  {
        int key = rand() % (int)(sizeof(charset) - 1);
        userName[i] = charset[key];
    }
  //  userName[5] = '\0';

for(i = 0; i < 5; i++)  {
        int key = rand() % (int)(sizeof(charset) - 1);
        password[i] = charset[key];
    }
 //   password[5] = '\0';

for(i = 0; i < 5; i++)  {
        int key = rand() % (int)(sizeof(charset) - 1);
        firstName[i] = charset[key];
    }
//    firstName[5] = '\0';

for(i = 0; i < 5; i++)  {
        int key = rand() % (int)(sizeof(charset) - 1);
        lastName[i] = charset[key];
    }
 //   lastName[5] = '\0';

for(i = 0; i < 5; i++)  {
        int key = rand() % (int)(sizeof(charset) - 1);
        address1[i] = charset[key];
    }
 //   address1[5] = '\0';

for(i = 0; i < 5; i++)  {
        int key = rand() % (int)(sizeof(charset) - 1);
        address2[i] = charset[key];
    }
  //  address2[5] = '\0';    

 

 lr_save_string(userName,"userName");
 lr_save_string(password,"password");
 lr_save_string(password,"confirm");
 lr_save_string(firstName,"firstName");
 lr_save_string(lastName,"lastName");
 lr_save_string(address1,"address1");
 lr_save_string(address2,"address2");
	
	web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1727341031559\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	/*Connection ID 0 received buffer WebSocketReceive0*/
	
	lr_start_transaction("UC06_Registration");
	
	
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
	
	
//////////////SignUp//////////////	

	lr_start_transaction("SignUp");

	web_add_auto_header("Priority", 
		"u=4");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	
	
    web_reg_find("Text=First time registering? Please complete the form below.",LAST);

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t2.inf", 
		LAST);

	lr_end_transaction("SignUp",LR_AUTO);
	
	lr_think_time(5);
	
	
//////////////FillTheRegistrationForm//////////////	


	lr_start_transaction("FillTheRegistrationForm");
	
	

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	
	
	web_reg_find("Text=Thank you, <b>{userName}</b>, for registering and welcome to the Web Tours family.",LAST);

	web_submit_form("login.pl", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=username", "Value={userName}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=passwordConfirm", "Value={confirm}", ENDITEM, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={address1}", ENDITEM, 
		"Name=address2", "Value={address2}", ENDITEM, 
		"Name=register.x", "Value=59", ENDITEM, 
		"Name=register.y", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("FillTheRegistrationForm",LR_AUTO);
	
	lr_think_time(5);
	

//////////////Continue//////////////		

	lr_start_transaction("Continue");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	
	
    web_reg_find("Text=Welcome, <b>{userName}</b>, to the Web Tours reservation pages.",LAST);

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t4.inf", 
		LAST);

	lr_end_transaction("Continue",LR_AUTO);
	
	lr_think_time(5);
	
	
//////////////SignOff//////////////	

	lr_start_transaction("SignOff");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t5.inf", 
		LAST);

	lr_end_transaction("SignOff",LR_AUTO);
	
	lr_end_transaction("UC06_Registration",LR_AUTO);

	return 0;
}

