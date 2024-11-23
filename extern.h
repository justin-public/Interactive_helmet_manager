#ifndef _EXTERN_H
#define _EXTERN_H

#include "ofMain.h"

extern string serialString, partString, partString1;
extern float readTime;
extern int rfid_event, rfid_event1;
extern int rfid_stage_cnt;
extern int start_hour, start_minute, end_hour, end_minute, load_start_hour, load_start_minute, minus_end_hour, minus_end_hour1, minus_end_minute, minus_end_minute1;
extern string time_event;
extern int rfid_status;
extern int setting_event;
extern int config_event, config_event1;
extern int csv_file_init;
extern string operation_mode;
extern bool music_play_mode;
extern int play_line;
extern int timer, timer_csv;
extern string music_name[10];

extern string devicestatus[31];
extern string batterystatus[31];
extern int rfidcolortag[62];
extern int Batterycolor[62];
extern int blackoff[30];
extern int minutesum[30];
extern int ref_time[30];
extern int Batterycolor[62];
extern int init_stage;

extern string str, str1, str2, str3, str4, str5;
extern string tmp;
extern string settingdata[11];
extern string config_line[6];
extern string rfid_cmd[3];
extern int off_event, off_event1;
extern int on_event, on_event1;
extern int data_event , data_event1;
extern int rfid_event, rfid_event1;

extern int event_packet;
extern int event_flag, event_flag1;
extern string line1, line2, line3, line4, line5, line6, line7, line8, line9;

extern int play_stop;
extern int time_reset;
extern int rfid_cmd_event,rfid_cmd_event1, rfid_cmd_event2;

extern int usertime;

/*
class EXTERNV {
	public:
		string serialString, partString, partString1;
		float readTime;
		int rfid_event, rfid_event1;
		int rfid_stage_cnt;
	
	private:
};
*/
#endif
