#include "Network.h"

string str, str1, str2, str3, str4, str5;
string tmp;
int data_event, data_event1;
int play_line;

vector<string> split(string str, char delimiter)
{
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter))
	{
		internal.push_back(temp);
	}
	return internal;
}

void NETWORK::setup(){
	ofxTCPSettings settings(8000);    // PC Server
	TCP.setup(settings);
	TCP.setMessageDelimiter("\n");
}

void NETWORK::update(){
	for (unsigned int i = 0; i < (unsigned int)TCP.getLastID(); i++)
	{
#if 1
		if (operation_mode == "auto") {
			events.start();
			music_play_mode = true;

			string timer_f = ofToString(events.getCurrentTime());
			timer = ofToInt(timer_f);
			timer_csv = ofToInt(time_event) * 60;
			if (timer == timer_csv)event_packet = 1;
			if (timer == timer_csv * 2)event_packet = 2;
			if (timer == timer_csv * 3)event_packet = 3;
			if (timer == timer_csv * 4)event_packet = 4;
			if (timer == timer_csv * 5)event_packet = 5;
			if (timer == timer_csv * 6)event_packet = 6;
			if (timer == timer_csv * 7)event_packet = 7;
			if (timer == timer_csv * 8)event_packet = 8;
			if (timer == timer_csv * 9)event_packet = 9;
			if (timer == timer_csv * 10)event_packet = 10;
		}
		if (operation_mode == "manual")music_play_mode = false;
		if (time_reset == 1) {
			events.reset();
			timer = 0;
		}
#endif		
		string port = ofToString(TCP.getClientPort(i));
		int port_num = ofToInt(port);
		string ip = TCP.getClientIP(i);
		const char* ipaddress = ip.c_str();
		string info = "client " + ofToString(i) + " -connected from " + ip + " on port: " + port;

		if (!TCP.isClientConnected(i)) {
			continue;
		}
		if (i >= storeText.size()) {
			storeText.push_back(string());
		}
		do {
			str = tmp;
			tmp = TCP.receive(i);
		} while (tmp != "");
		//std::cout << "csv data: " << str << endl;
		if (str.length() > 0)
		{
			//std::cout << "csv data: " << str << endl;
			storeText[i] = str;
			vector<string> line_vector = split(str, ';');
			for (int i = 0; i < line_vector.size(); ++i) {
				str1 = line_vector[0];                       // CONFIG
				str2 = line_vector[1];                       // RFID
				if(str1.compare("Config")==0)str3 = line_vector[2];						// UHF RFID
				if(str1.compare("Config")==0)str4 = line_vector[3];                       // OFF / ON
			}
			data_event = 1;
		}
#if 1
		if (str.length() <= 0)
		{
			if ((off_event1 == 1) && (rfid_status % 2 == 0))    // standby  
			{
				for (int i = 0; i < TCP.getLastID(); i++)
				{
					if (TCP.isClientConnected(i)) {
						//std::cout <<"standby :"<< config_line[0] << " : " << config_line[1] << " : " << config_line[2] << " : " << config_line[3] << ":" << config_line[4] << endl;
						TCP.send(i, config_line[0] + ";" + config_line[1] + ";" + "off" + ";" + config_line[3] + ";" + config_line[4] + "\n");
					}
				}
				off_event1 = 0;
			}
			if ((off_event1 == 1) && (rfid_status % 2 == 1))      // active
			{
				for (int i = 0; i < TCP.getLastID(); i++)
				{
					if (TCP.isClientConnected(i)) {
						//std::cout <<"active :" <<config_line[0] << " : " << config_line[1] << " : " << config_line[2] << " : " << config_line[3] << ":" << config_line[4] << endl;
						TCP.send(i, config_line[0] + ";" + config_line[1] + ";" + config_line[2] + ";" + config_line[3] + ";" + config_line[4] + "\n");
						//TCP.send(i, config_line[0] + ";" + config_line[1] + ";" + config_line[2] + ";" + config_line[3] + ";" + config_line[4] +";"+"active"+ "\n");
					}
				}
				off_event1 = 0;
			}
			if ((on_event1 == 1) && (rfid_status % 2 == 0))
			{
				for (int i = 0; i < TCP.getLastID(); i++)
				{
					if (TCP.isClientConnected(i)) {
						//std::cout <<"standby :"<< config_line[0] << " : " << config_line[1] << " : " << config_line[2] << " : " << config_line[3] << ":" << config_line[4] << endl;
						TCP.send(i, config_line[0] + ";" + config_line[1] + ";" + "off" + ";" + config_line[3] + ";" + config_line[4] + "\n");
					}
				}
				on_event1 = 0;
			}
			if ((on_event1 == 1) && (rfid_status % 2 == 1)) {
				for (int i = 0; i < TCP.getLastID(); i++)
				{
					if (TCP.isClientConnected(i)) {
						//std::cout <<"standby :"<< config_line[0] << " : " << config_line[1] << " : " << config_line[2] << " : " << config_line[3] << ":" << config_line[4] << endl;
						TCP.send(i, config_line[0] + ";" + config_line[1] + ";" + config_line[2] + ";" + config_line[3] + ";" + config_line[4] + "\n");
					}
				}
				on_event1 = 0;
			}
			if (event_flag1 == 1) {
				for (int i = 0; i < TCP.getLastID(); i++){
					if (TCP.isClientConnected(i)) {
						TCP.send(i, line5 + ";" + line6 + ";" + line7 + ";" + line8 + ";" + line9 + "\n");    
					}
				}
				//play_line = 1;                   // 디스플레이 라인이 변하는 구간
				event_flag1 = 0;
			}
			///*
			if (rfid_cmd_event1 == 1){
				for (int i = 0; i < TCP.getLastID(); i++) {
					if (TCP.isClientConnected(i)) {
						TCP.send(i, rfid_cmd[0] + ";" + str2 + ";" + rfid_cmd[1] + ";" + rfid_cmd[2] + "\n");
					}
				}
				rfid_cmd_event1 = 0;
			}
			//*/
			/*------Device 0------*/
			if (blackoff[0] == 1) {
				string on_led = "on";
				for (int i = 0; i < TCP.getLastID(); i++) {
					if (TCP.isClientConnected(i)) {
						TCP.send(i, on_led + ";" + "406654" + "\n");    //
					}
				}
				blackoff[0] = 0;
			}
			if (blackoff[0] == 2) {
				string off_led = "off";
				for (int i = 0; i < TCP.getLastID(); i++) {
					if (TCP.isClientConnected(i)) {
						TCP.send(i, off_led + ";" + "406654" + "\n");    //
					}
				}
				blackoff[0] = 0;
			}
			/*--------------------*/
			/*------Device 1------*/
			if (blackoff[1] == 1) {
				string on_led = "on";
				for (int i = 0; i < TCP.getLastID(); i++) {
					if (TCP.isClientConnected(i)) {
						TCP.send(i, on_led + ";" + "10a164" + "\n");    //
					}
				}
				blackoff[1] = 0;
			}
			if (blackoff[1] == 2) {
				string off_led = "off";
				for (int i = 0; i < TCP.getLastID(); i++) {
					if (TCP.isClientConnected(i)) {
						TCP.send(i, off_led + ";" + "10a164" + "\n");    //
					}
				}
				blackoff[1] = 0;
			}
			/*--------------------*/
		}
#endif
	}
}

void NETWORK::draw()
{

}