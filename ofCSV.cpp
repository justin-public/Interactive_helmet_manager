/*
backup data #1
*/

#include "ofCSV.h"

int rfid_event, rfid_event1;
int rfid_stage_cnt;
int start_hour, start_minute, end_hour, end_minute, load_start_hour, load_start_minute, minus_end_hour, minus_end_hour1, minus_end_minute, minus_end_minute1;
string line1, line2, line3, line4, line5, line6, line7, line8, line9;
//string music01_name, music02_name, music03_name, music04_name, music05_name, music06_name, music07_name, music08_name, music09_name, music00_name;
string time_event;
int rfid_status;
int setting_event;
int off_event, off_event1;
int on_event, on_event1;
int blackoff[30];
int minutesum[30];
int ref_time[30];
int timer, timer_csv;

int event_flag, event_flag1;
int rfid_cmd_event, rfid_cmd_event1, rfid_cmd_event2;

string music_name[10];

string on = "on";
string off = "off";

string settingdata[11];
string config_line[6];
string rfid_cmd[3];

void CSV::setup()
{
	ofSetLogLevel("ofxCsv", OF_LOG_VERBOSE);
	csv.load("Superpump_manager.csv");
}

void CSV::update()
{
	if (csv_file_init == 1)
	{
		for (int i = 0; i <= 9; i++) {
			music_name[i] = csv[21 + i][4];
		}
		time_event = csv[34][4];
		csv_file_init = 0;
	}
	if (serialString.length() > 0)
	{
		for (int i = 0; i < csv.getNumRows(); i++) {
			for (int j = 0; j < csv.getNumCols(i); j++) {
				if (partString.compare(csv[i][j]) == 0) {
					//std::cout << csv[i][j + 2] << endl;
					rfid_event = 1;
					if (rfid_event == 1) {
						rfid_stage_cnt++;
						if (rfid_stage_cnt == 1 && csv[i][j + 2] == "")
						{
							start_hour = ofGetHours();
							start_minute = ofGetMinutes();
							csv[i][j + 2] = "TRUE";                                // 출고 상태 확인  
							csv[i][j + 3] = ofToString(start_hour);
							csv[i][j + 4] = ofToString(start_minute);

							row.addString(csv[i][j + 2]);

							row.addString(csv[i][j + 3]);         // 출고 시간
							row.addString(csv[i][j + 4]);         // 출고 분    

							rfid_status = ofToInt(csv[i][j + 7]);
							csv.save("Superpump_manager.csv");
							rfid_stage_cnt = 0;
							rfid_event = 0;
							rfid_event1 = 1;
						}
						if (rfid_stage_cnt == 1 && csv[i][j + 2] == "TRUE")
						{
							end_hour = ofGetHours();
							end_minute = ofGetMinutes();

							load_start_hour = ofToInt(csv[i][j + 3]);
							load_start_minute = ofToInt(csv[i][j + 4]);

							minus_end_hour = end_hour - load_start_hour;          // 미래의 시간 - 과거의 시간       
							minus_end_minute = end_minute - load_start_minute;    // 미래의 분 - 과거의 분

							if (minus_end_minute < 0) {
								minus_end_hour -= 1;
								minus_end_minute = 60 - load_start_minute + end_minute;
							}

							csv[i][j + 2] = "";                             // 입고 상태 확인  
							csv[i][j + 5] = ofToString(end_hour);
							csv[i][j + 6] = ofToString(end_minute);
							csv[i][j + 9] = ofToString(minus_end_minute);

							row.addString(csv[i][j + 2]);

							row.addString(csv[i][j + 5]);         // 입고 시간
							row.addString(csv[i][j + 6]);         // 입고 분 

							row.addString(csv[i][j + 9]);

							rfid_status = ofToInt(csv[i][j + 8]);
							csv.save("Superpump_manager.csv");
							rfid_stage_cnt = 0;
							rfid_event = 0;
							rfid_event1 = 1;
						}
					}
					if (rfid_event1 == 1)
					{
						/*---Device Battery #1---*/
						if (rfid_status == 1)blackoff[0] = 1;
						if (rfid_status == 2) {
							minutesum[0] += ofToInt(csv[i][j + 9]);          // battery time sum
							csv[i][j + 10] = ofToString(minutesum[0]);       // user time..     
							ref_time[0] = ofToInt(csv[i][j + 11]);

							if (minutesum[0] < ref_time[0]) {
								Batterycolor[0] = 0; Batterycolor[1] = 250;
								batterystatus[0] = csv[i][j + 10];
							}
							if (minutesum[0] >= ref_time[0]) {
								Batterycolor[0] = 250; Batterycolor[1] = 0;
								batterystatus[0] = "Battery Charge Please..";
							}
							blackoff[0] = 2;
							csv.save("Superpump_manager.csv");
						}
						/*-----------------------*/
						/*---Device Battery #2---*/
						if (rfid_status == 3)blackoff[1] = 1;               // <----
						if (rfid_status == 4) {
							minutesum[1] += ofToInt(csv[i][j + 9]);
							csv[i][j + 10] = ofToString(minutesum[1]);
							ref_time[1] = ofToInt(csv[i][j + 11]);

							if (minutesum[1] < ref_time[1]) {
								Batterycolor[2] = 0; Batterycolor[3] = 250;
								batterystatus[1] = csv[i][j + 10];
							}
							if (minutesum[1] >= ref_time[1]) {
								Batterycolor[2] = 250; Batterycolor[3] = 0;
								batterystatus[1] = "Battery Charge Please..";
							}
							blackoff[1] = 2;                             // <----
							csv.save("Superpump_manager.csv");
						}
						/*-----------------------*/
						rfid_event1 = 0;
					}
				}
			}
		}
	}
	/*
	if (rfid_cmd_event == 1)
	{
		std::cout << "event .." << endl;
		for (int i = 0; i < csv.getNumRows(); i++)
		{
			for (int j = 0; j < csv.getNumCols(i); j++) {
				if (str1.compare(csv[i][j]) == 0)
				{
					std::cout << "event .." << endl;
				}
			}
		}
		rfid_cmd_event = 0;
	}
	*/
#if 1
	if (data_event == 1)
	{
		//std::cout<<"csv data: " << str1 << " : " << str2 << " : " << str3 <<" : "<< str4 <<endl;
		for (int i = 0; i < csv.getNumRows(); i++)
		{
			for (int j = 0; j < csv.getNumCols(i); j++) {
				// 서버를 껐다가 켰을 경우 헬멧의 입출고 상태를 알아내기 위해 정보를 로드함
				// 13.56MHz 에 RFID를 헤더로한 프레임 전송
				if (str2.compare(csv[i][j]) == 0) {
					setting_event = 1;
					if (setting_event == 1)
					{
						for (int csvindex = 0; csvindex <= 11; csvindex++) {
							settingdata[csvindex] = csv[i][j + csvindex];                 // 배터리 상태 와 사용 시간을 로드
						}
						if (settingdata[2] == "TRUE")rfid_status = ofToInt(csv[i][j + 7]);
						if (settingdata[2] == "") rfid_status = ofToInt(csv[i][j + 8]);
						setting_event = 0;
					}
				}
				// 입고 상태 에서 헬멧의 전원을 껐다가 켰을경우 해당 rfid 데이터 클리어
				if (rfid_status % 2 == 0 && (str4.compare(off) == 0)) {
					if (str2.compare(csv[i][j]) == 0)
					{
						std::cout << "memory clear" << endl;
						
						if(rfid_status == 2)minutesum[0] = 0;
						if(rfid_status == 4)minutesum[1] = 0;
						
						csv[i][1] = "";
						csv[i][2] = "";  
						csv[i][3] = "";
						csv[i][4] = "";
						csv[i][5] = "";
						csv[i][6] = "";
						csv[i][9] = "";
						csv[i][10] = ofToString(minutesum[0]);

						row.addString(csv[i][1]);
						row.addString(csv[i][2]);
						row.addString(csv[i][3]);
						row.addString(csv[i][4]);
						row.addString(csv[i][5]);
						row.addString(csv[i][6]);
						row.addString(csv[i][9]);
						row.addString(csv[i][10]);

						minus_end_minute1 = 0;
						csv.save("Superpump_manager.csv");
					}
				}

				if (str1.compare(csv[i][j]) == 0 && (str4.compare(off) == 0))       // config
				{
					off_event = 1;
					if (off_event == 1)
					{
						for (int csvindex1 = 0; csvindex1 <= 6; csvindex1++) {
							config_line[csvindex1] = csv[i][j + csvindex1];
						}
						off_event = 0;
						off_event1 = 1;
					}
				}
				if (str1.compare(csv[i][j]) == 0 && (str4.compare(on) == 0))    // standby , active
				{
					on_event = 1;
					if (on_event == 1) {
						for (int csvindex1 = 0; csvindex1 <= 6; csvindex1++) {
							config_line[csvindex1] = csv[i][j + csvindex1];
						}
						on_event = 0;
						on_event1 = 1;
					}
				}
#if 1
				if (str1.compare(csv[i][j]) == 0)   // rx01
				{
					rfid_cmd_event = 1;
					if (rfid_cmd_event == 1) {
						for (int rfidcmdindex = 0; rfidcmdindex <= 3; rfidcmdindex++) {
							rfid_cmd[rfidcmdindex] = csv[i][j + rfidcmdindex];
						}
						rfid_cmd_event = 0;
						rfid_cmd_event1 = 1;
					}
				}
#endif
			}
		}
		data_event = 0;
	}
	if (event_packet == 1)
	{
		for (int i = 0; i < csv.getNumRows(); i++)
		{
			for (int j = 0; j < csv.getNumCols(i); j++) {
				string Button = "B_1";
				if (Button.compare(csv[i][j]) == 0) {
					event_flag = 1;
					if (event_flag == 1) {
						line5 = Button;
						line6 = csv[i][j + 1];	// led pattern
						line7 = csv[i][j + 2];	// play time
						line8 = csv[i][j + 3];	// sound id
						line9 = csv[i][j + 4];  // Music
						event_flag1 = 1;
						event_flag = 0;
					}
				}
			}
		}
		myMp3.load(line9);
		myMp3.play();
		play_line = 1;
		event_packet = 0;
	}
	if (event_packet == 2)
	{
		for (int i = 0; i < csv.getNumRows(); i++)
		{
			for (int j = 0; j < csv.getNumCols(i); j++) {
				string Button = "B_2";
				if (Button.compare(csv[i][j]) == 0) {
					event_flag = 1;
					if (event_flag == 1) {
						line5 = Button;
						line6 = csv[i][j + 1];	// led pattern
						line7 = csv[i][j + 2];	// play time
						line8 = csv[i][j + 3];	// sound id
						line9 = csv[i][j + 4];  // Music
						event_flag1 = 1;
						event_flag = 0;
					}
				}
			}
		}
		myMp3.load(line9);
		myMp3.play();
		play_line = 2;
		event_packet = 0;
	}
	if (event_packet == 3)
	{
		for (int i = 0; i < csv.getNumRows(); i++)
		{
			for (int j = 0; j < csv.getNumCols(i); j++) {
				string Button = "B_3";
				if (Button.compare(csv[i][j]) == 0) {
					event_flag = 1;
					if (event_flag == 1) {
						line5 = Button;
						line6 = csv[i][j + 1];	// led pattern
						line7 = csv[i][j + 2];	// play time
						line8 = csv[i][j + 3];	// sound id
						line9 = csv[i][j + 4];  // Music
						event_flag1 = 1;
						event_flag = 0;
					}
				}
			}
		}
		myMp3.load(line9);
		myMp3.play();
		play_line = 3;
		event_packet = 0;
	}
	if (event_packet == 4)
	{
		for (int i = 0; i < csv.getNumRows(); i++)
		{
			for (int j = 0; j < csv.getNumCols(i); j++) {
				string Button = "B_4";
				if (Button.compare(csv[i][j]) == 0) {
					event_flag = 1;
					if (event_flag == 1) {
						line5 = Button;
						line6 = csv[i][j + 1];	// led pattern
						line7 = csv[i][j + 2];	// play time
						line8 = csv[i][j + 3];	// sound id
						line9 = csv[i][j + 4];  // Music
						event_flag1 = 1;
						event_flag = 0;
					}
				}
			}
		}
		myMp3.load(line9);
		myMp3.play();
		play_line = 4;
		event_packet = 0;
	}
	if (event_packet == 5)
	{
		for (int i = 0; i < csv.getNumRows(); i++)
		{
			for (int j = 0; j < csv.getNumCols(i); j++) {
				string Button = "B_5";
				if (Button.compare(csv[i][j]) == 0) {
					event_flag = 1;
					if (event_flag == 1) {
						line5 = Button;
						line6 = csv[i][j + 1];	// led pattern
						line7 = csv[i][j + 2];	// play time
						line8 = csv[i][j + 3];	// sound id
						line9 = csv[i][j + 4];  // Music
						event_flag1 = 1;
						event_flag = 0;
					}
				}
			}
		}
		myMp3.load(line9);
		myMp3.play();
		play_line = 5;
		event_packet = 0;
	}
	if (event_packet == 6)
	{
		for (int i = 0; i < csv.getNumRows(); i++)
		{
			for (int j = 0; j < csv.getNumCols(i); j++) {
				string Button = "B_6";
				if (Button.compare(csv[i][j]) == 0) {
					event_flag = 1;
					if (event_flag == 1) {
						line5 = Button;
						line6 = csv[i][j + 1];	// led pattern
						line7 = csv[i][j + 2];	// play time
						line8 = csv[i][j + 3];	// sound id
						line9 = csv[i][j + 4];  // Music
						event_flag1 = 1;
						event_flag = 0;
					}
				}
			}
		}
		myMp3.load(line9);
		myMp3.play();
		play_line = 6;
		event_packet = 0;
	}
	if (event_packet == 7)
	{
		for (int i = 0; i < csv.getNumRows(); i++)
		{
			for (int j = 0; j < csv.getNumCols(i); j++) {
				string Button = "B_7";
				if (Button.compare(csv[i][j]) == 0) {
					event_flag = 1;
					if (event_flag == 1) {
						line5 = Button;
						line6 = csv[i][j + 1];	// led pattern
						line7 = csv[i][j + 2];	// play time
						line8 = csv[i][j + 3];	// sound id
						line9 = csv[i][j + 4];  // Music
						event_flag1 = 1;
						event_flag = 0;
					}
				}
			}
		}
		myMp3.load(line9);
		myMp3.play();
		play_line = 7;
		event_packet = 0;
	}
	if (event_packet == 8)
	{
		for (int i = 0; i < csv.getNumRows(); i++)
		{
			for (int j = 0; j < csv.getNumCols(i); j++) {
				string Button = "B_8";
				if (Button.compare(csv[i][j]) == 0) {
					event_flag = 1;
					if (event_flag == 1) {
						line5 = Button;
						line6 = csv[i][j + 1];	// led pattern
						line7 = csv[i][j + 2];	// play time
						line8 = csv[i][j + 3];	// sound id
						line9 = csv[i][j + 4];  // Music
						event_flag1 = 1;
						event_flag = 0;
					}
				}
			}
		}
		myMp3.load(line9);
		myMp3.play();
		play_line = 8;
		event_packet = 0;
	}
	if (event_packet == 9)
	{
		for (int i = 0; i < csv.getNumRows(); i++)
		{
			for (int j = 0; j < csv.getNumCols(i); j++) {
				string Button = "B_9";
				if (Button.compare(csv[i][j]) == 0) {
					event_flag = 1;
					if (event_flag == 1) {
						line5 = Button;
						line6 = csv[i][j + 1];	// led pattern
						line7 = csv[i][j + 2];	// play time
						line8 = csv[i][j + 3];	// sound id
						line9 = csv[i][j + 4];  // Music
						event_flag1 = 1;
						event_flag = 0;
					}
				}
			}
		}
		myMp3.load(line9);
		myMp3.play();
		play_line = 9;
		event_packet = 0;
	}
	if (event_packet == 10)
	{
		for (int i = 0; i < csv.getNumRows(); i++)
		{
			for (int j = 0; j < csv.getNumCols(i); j++) {
				string Button = "B_0";
				if (Button.compare(csv[i][j]) == 0) {
					event_flag = 1;
					if (event_flag == 1) {
						line5 = Button;
						line6 = csv[i][j + 1];	// led pattern
						line7 = csv[i][j + 2];	// play time
						line8 = csv[i][j + 3];	// sound id
						line9 = csv[i][j + 4];  // Music
						event_flag1 = 1;
						event_flag = 0;
					}
				}
			}
		}
		myMp3.load(line9);
		myMp3.play();
		play_line = 10;
		event_packet = 0;
	}
	if (play_stop == 1) {
		myMp3.stop();
		play_stop = 0;
	}
#endif	
}

void CSV::draw()
{

}

void CSV::keyReleased(int key)
{
	if (key == '1')if (operation_mode == "manual")event_packet = 1;
	if (key == '2')if (operation_mode == "manual")event_packet = 2;
	if (key == '3')if (operation_mode == "manual")event_packet = 3;
	if (key == '4')if (operation_mode == "manual")event_packet = 4;
	if (key == '5')if (operation_mode == "manual")event_packet = 5;
	if (key == '6')if (operation_mode == "manual")event_packet = 6;
	if (key == '7')if (operation_mode == "manual")event_packet = 7;
	if (key == '8')if (operation_mode == "manual")event_packet = 8;
	if (key == '9')if (operation_mode == "manual")event_packet = 9;
	if (key == '0')if (operation_mode == "manual")event_packet = 10;
}