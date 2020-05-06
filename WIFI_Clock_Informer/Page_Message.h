const char PAGE_Message[] PROGMEM =  R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/"  class="btn btn--m btn--blue"><</a>&nbsp;&nbsp;<strong>Send a message</strong>
<hr>
	<form action="" method="post">
		<table border="0"  cellspacing="0" cellpadding="3" >
			<tr>
				<td align="center">Enter your message</td>
			</tr>
			<tr>
				<tdtd align="center"><input id="message" name="message" size="32" value=""></td>
			
			<tr>
				<td colspan="2" align="center"><input type="submit" style="width:150px" class="btn btn--m btn--blue" value="Save"></td>
			</tr>
		</table>
	</form>
<br>
<script>
	window.onload = function ()
	{
		load("style.css","css", function() 
		{
			load("microajax.js","js", function() 
			{
					setValues("/admin/message");
			});
		});
	}
	function load(e,t,n){
		if("js"==t){
			var a=document.createElement("script");
			a.src=e,a.type="text/javascript", a.async=!1, a.onload=function(){n()}, document.getElementsByTagName("head")[0].appendChild(a)
		}
		else if("css"==t){
			var a=document.createElement("link");
			a.href=e, a.rel="stylesheet", a.type="text/css", a.async=!1, a.onload=function(){n()}, document.getElementsByTagName("head")[0].appendChild(a)
		}
	}
</script>
)=====";


// Functions for this Page
void send_message_value_html()
{
	String values ="";
	values += "message|" + (String) config.message + "|div\n";
	server.send ( 200, "text/plain", values);
	Serial.println(__FUNCTION__); 
	
}

void send_message_html()
{
	if (server.args() > 0 )  // Save Settings
	{	
		String temp = "";
		for ( uint8_t i = 0; i < server.args(); i++ ) {
			if (server.argName(i) == "message") config.message = urldecode(server.arg(i)); 
		}

		WriteConfig();
		firstStart = true;
	}
	server.send_P ( 200, "text/html", PAGE_Message ); 
	Serial.println(__FUNCTION__); 
}

void send_message_configuration_values_html()
{
	String values ="";
	values += "message|" +  (String)  config.message +  "|input\n";

	server.send ( 200, "text/plain", values);
	Serial.println(__FUNCTION__); 
	AdminTimeOutCounter=0;
}
