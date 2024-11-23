/*
production : nines.co.ltd
writer     : justin
Date       : 2021.12.08
titile     : superpump management Ver3.0 
*/

#include "ofApp.h"
#include "ofThread.h"


string devicestatus[31];
string batterystatus[31];
int rfidcolortag[62];
int Batterycolor[62];
int init_stage;
int csv_file_init;
string operation_mode;
bool music_play_mode;
int event_packet;

int play_stop;
int time_reset;

//--------------------------------------------------------------
void ofApp::setup(){
	//socketTCP.setup();      // ethernet class
	//ofxSerial.setup();      // Serial
	//CSVFORMAT.setup();
	thread1.setup();
	thread1.startThread();
	thread2.setup();
	thread2.startThread();
	thread3.setup();
	thread3.startThread();
	/*--------------------------*/
	init_stage = 1;
	csv_file_init = 1;
	/*--------------------------*/
}

void ofApp::mp3_list(int music_list)
{
	if (music_list == 0) {
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("SERVER PC . INTERACTIVE HELMAT", 20, 20);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 1 : " + music_name[0], 20, 40);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 2 : " + music_name[1], 20, 60);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 3 : " + music_name[2], 20, 80);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 4 : " + music_name[3], 20, 100);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 5 : " + music_name[4], 20, 120);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 6 : " + music_name[5], 20, 140);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 7 : " + music_name[6], 20, 160);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 8 : " + music_name[7], 20, 180);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 9 : " + music_name[8], 20, 200);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 0 : " + music_name[9], 20, 220);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("AUTO / MANUAL : " + operation_mode, 20, 240);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("EVENT TERM : " + time_event + " min", 20, 260);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Auto Mode : KEYBOARD a] ", 20, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Manual Mode : KEYBOARD m]", 220, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Music stop : KEYBOARD s]", 450, 750);
	}
	if (music_list == 1){
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("SERVER PC . INTERACTIVE HELMAT", 20, 20);
		ofSetColor(250, 0, 250);
		ofDrawBitmapString("KEY BOARD 1 : " + music_name[0], 20, 40);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 2 : " + music_name[1], 20, 60);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 3 : " + music_name[2], 20, 80);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 4 : " + music_name[3], 20, 100);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 5 : " + music_name[4], 20, 120);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 6 : " + music_name[5], 20, 140);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 7 : " + music_name[6], 20, 160);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 8 : " + music_name[7], 20, 180);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 9 : " + music_name[8], 20, 200);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 0 : " + music_name[9], 20, 220);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("AUTO / MANUAL : " + operation_mode, 20, 240);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("EVENT TERM : " + time_event + " min", 20, 260);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Auto Mode : KEYBOARD a] ", 20, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Manual Mode : KEYBOARD m]", 220, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Music stop : KEYBOARD s]", 450, 750);
	}
	if (music_list == 2){
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("SERVER PC . INTERACTIVE HELMAT", 20, 20);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 1 : " + music_name[0], 20, 40);
		ofSetColor(250, 0, 250);
		ofDrawBitmapString("KEY BOARD 2 : " + music_name[1], 20, 60);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 3 : " + music_name[2], 20, 80);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 4 : " + music_name[3], 20, 100);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 5 : " + music_name[4], 20, 120);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 6 : " + music_name[5], 20, 140);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 7 : " + music_name[6], 20, 160);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 8 : " + music_name[7], 20, 180);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 9 : " + music_name[8], 20, 200);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 0 : " + music_name[9], 20, 220);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("AUTO / MANUAL : " + operation_mode, 20, 240);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("EVENT TERM : " + time_event + " min", 20, 260);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Auto Mode : KEYBOARD a] ", 20, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Manual Mode : KEYBOARD m]", 220, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Music stop : KEYBOARD s]", 450, 750);
	}
	if (music_list == 3)
	{
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("SERVER PC . INTERACTIVE HELMAT", 20, 20);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 1 : " + music_name[0], 20, 40);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 2 : " + music_name[1], 20, 60);
		ofSetColor(250, 0, 250);
		ofDrawBitmapString("KEY BOARD 3 : " + music_name[2], 20, 80);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 4 : " + music_name[3], 20, 100);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 5 : " + music_name[4], 20, 120);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 6 : " + music_name[5], 20, 140);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 7 : " + music_name[6], 20, 160);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 8 : " + music_name[7], 20, 180);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 9 : " + music_name[8], 20, 200);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 0 : " + music_name[9], 20, 220);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("AUTO / MANUAL : " + operation_mode, 20, 240);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("EVENT TERM : " + time_event + " min", 20, 260);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Auto Mode : KEYBOARD a] ", 20, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Manual Mode : KEYBOARD m]", 220, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Music stop : KEYBOARD s]", 450, 750);
	}
	if (music_list == 4)
	{
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("SERVER PC . INTERACTIVE HELMAT", 20, 20);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 1 : " + music_name[0], 20, 40);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 2 : " + music_name[1], 20, 60);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 3 : " + music_name[2], 20, 80);
		ofSetColor(250, 0, 250);
		ofDrawBitmapString("KEY BOARD 4 : " + music_name[3], 20, 100);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 5 : " + music_name[4], 20, 120);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 6 : " + music_name[5], 20, 140);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 7 : " + music_name[6], 20, 160);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 8 : " + music_name[7], 20, 180);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 9 : " + music_name[8], 20, 200);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 0 : " + music_name[9], 20, 220);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("AUTO / MANUAL : " + operation_mode, 20, 240);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("EVENT TERM : " + time_event + " min", 20, 260);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Auto Mode : KEYBOARD a] ", 20, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Manual Mode : KEYBOARD m]", 220, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Music stop : KEYBOARD s]", 450, 750);
	}
	if (music_list == 5)
	{
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("SERVER PC . INTERACTIVE HELMAT", 20, 20);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 1 : " + music_name[0], 20, 40);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 2 : " + music_name[1], 20, 60);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 3 : " + music_name[2], 20, 80);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 4 : " + music_name[3], 20, 100);
		ofSetColor(250, 0, 250);
		ofDrawBitmapString("KEY BOARD 5 : " + music_name[4], 20, 120);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 6 : " + music_name[5], 20, 140);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 7 : " + music_name[6], 20, 160);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 8 : " + music_name[7], 20, 180);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 9 : " + music_name[8], 20, 200);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 0 : " + music_name[9], 20, 220);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("AUTO / MANUAL : " + operation_mode, 20, 240);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("EVENT TERM : " + time_event + " min", 20, 260);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Auto Mode : KEYBOARD a] ", 20, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Manual Mode : KEYBOARD m]", 220, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Music stop : KEYBOARD s]", 450, 750);
	}
	if (music_list == 6)
	{
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("SERVER PC . INTERACTIVE HELMAT", 20, 20);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 1 : " + music_name[0], 20, 40);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 2 : " + music_name[1], 20, 60);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 3 : " + music_name[2], 20, 80);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 4 : " + music_name[3], 20, 100);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 5 : " + music_name[4], 20, 120);
		ofSetColor(250, 0, 250);
		ofDrawBitmapString("KEY BOARD 6 : " + music_name[5], 20, 140);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 7 : " + music_name[6], 20, 160);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 8 : " + music_name[7], 20, 180);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 9 : " + music_name[8], 20, 200);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 0 : " + music_name[9], 20, 220);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("AUTO / MANUAL : " + operation_mode, 20, 240);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("EVENT TERM : " + time_event + " min", 20, 260);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Auto Mode : KEYBOARD a] ", 20, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Manual Mode : KEYBOARD m]", 220, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Music stop : KEYBOARD s]", 450, 750);
	}
	if (music_list == 7)
	{
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("SERVER PC . INTERACTIVE HELMAT", 20, 20);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 1 : " + music_name[0], 20, 40);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 2 : " + music_name[1], 20, 60);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 3 : " + music_name[2], 20, 80);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 4 : " + music_name[3], 20, 100);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 5 : " + music_name[4], 20, 120);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 6 : " + music_name[5], 20, 140);
		ofSetColor(250, 0, 250);
		ofDrawBitmapString("KEY BOARD 7 : " + music_name[6], 20, 160);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 8 : " + music_name[7], 20, 180);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 9 : " + music_name[8], 20, 200);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 0 : " + music_name[9], 20, 220);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("AUTO / MANUAL : " + operation_mode, 20, 240);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("EVENT TERM : " + time_event + " min", 20, 260);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Auto Mode : KEYBOARD a] ", 20, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Manual Mode : KEYBOARD m]", 220, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Music stop : KEYBOARD s]", 450, 750);
	}
	if (music_list == 8)
	{
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("SERVER PC . INTERACTIVE HELMAT", 20, 20);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 1 : " + music_name[0], 20, 40);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 2 : " + music_name[1], 20, 60);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 3 : " + music_name[2], 20, 80);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 4 : " + music_name[3], 20, 100);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 5 : " + music_name[4], 20, 120);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 6 : " + music_name[5], 20, 140);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 7 : " + music_name[6], 20, 160);
		ofSetColor(250, 0, 250);
		ofDrawBitmapString("KEY BOARD 8 : " + music_name[7], 20, 180);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 9 : " + music_name[8], 20, 200);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 0 : " + music_name[9], 20, 220);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("AUTO / MANUAL : " + operation_mode, 20, 240);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("EVENT TERM : " + time_event + " min", 20, 260);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Auto Mode : KEYBOARD a] ", 20, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Manual Mode : KEYBOARD m]", 220, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Music stop : KEYBOARD s]", 450, 750);
	}
	if (music_list == 9)
	{
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("SERVER PC . INTERACTIVE HELMAT", 20, 20);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 1 : " + music_name[0], 20, 40);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 2 : " + music_name[1], 20, 60);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 3 : " + music_name[2], 20, 80);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 4 : " + music_name[3], 20, 100);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 5 : " + music_name[4], 20, 120);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 6 : " + music_name[5], 20, 140);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 7 : " + music_name[6], 20, 160);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 8 : " + music_name[7], 20, 180);
		ofSetColor(250, 0, 250);
		ofDrawBitmapString("KEY BOARD 9 : " + music_name[8], 20, 200);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 0 : " + music_name[9], 20, 220);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("AUTO / MANUAL : " + operation_mode, 20, 240);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("EVENT TERM : " + time_event + " min", 20, 260);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Auto Mode : KEYBOARD a] ", 20, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Manual Mode : KEYBOARD m]", 220, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Music stop : KEYBOARD s]", 450, 750);
	}
	if (music_list == 10)
	{
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("SERVER PC . INTERACTIVE HELMAT", 20, 20);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 1 : " + music_name[0], 20, 40);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 2 : " + music_name[1], 20, 60);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 3 : " + music_name[2], 20, 80);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 4 : " + music_name[3], 20, 100);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 5 : " + music_name[4], 20, 120);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 6 : " + music_name[5], 20, 140);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 7 : " + music_name[6], 20, 160);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 8 : " + music_name[7], 20, 180);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("KEY BOARD 9 : " + music_name[8], 20, 200);
		ofSetColor(250, 0, 250);
		ofDrawBitmapString("KEY BOARD 0 : " + music_name[9], 20, 220);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("AUTO / MANUAL : " + operation_mode, 20, 240);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("EVENT TERM : " + time_event + " min", 20, 260);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Auto Mode : KEYBOARD a] ", 20, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Manual Mode : KEYBOARD m]", 220, 750);
		ofSetColor(250, 250, 250);
		ofDrawBitmapString("[Music stop : KEYBOARD s]", 450, 750);
	}
}

void ofApp::devicelist()
{
	ofDrawBitmapString("01", 550, 40);
	ofDrawBitmapString("02", 550, 60);
	ofDrawBitmapString("03", 550, 80);
	ofDrawBitmapString("04", 550, 100);
	ofDrawBitmapString("05", 550, 120);
	ofDrawBitmapString("06", 550, 140);
	ofDrawBitmapString("07", 550, 160);
	ofDrawBitmapString("08", 550, 180);
	ofDrawBitmapString("09", 550, 200);
	ofDrawBitmapString("10", 550, 220);
	ofDrawBitmapString("11", 550, 240);
	ofDrawBitmapString("12", 550, 260);
	ofDrawBitmapString("13", 550, 280);
	ofDrawBitmapString("14", 550, 300);
	ofDrawBitmapString("15", 550, 320);
	ofDrawBitmapString("16", 550, 340);
	ofDrawBitmapString("17", 550, 360);
	ofDrawBitmapString("18", 550, 380);
	ofDrawBitmapString("19", 550, 400);
	ofDrawBitmapString("20", 550, 420);
	ofDrawBitmapString("21", 550, 440);
	ofDrawBitmapString("22", 550, 460);
	ofDrawBitmapString("23", 550, 480);
	ofDrawBitmapString("24", 550, 500);
	ofDrawBitmapString("25", 550, 520);
	ofDrawBitmapString("26", 550, 540);
	ofDrawBitmapString("27", 550, 560);
	ofDrawBitmapString("28", 550, 580);
	ofDrawBitmapString("29", 550, 600);
	ofDrawBitmapString("30", 550, 620);

	ofSetColor(rfidcolortag[0], rfidcolortag[1], 0);
	ofDrawBitmapString(devicestatus[0], 600, 40);
	ofSetColor(Batterycolor[0], Batterycolor[1], 0);
	ofDrawBitmapString(batterystatus[0], 670, 40);

	ofSetColor(rfidcolortag[2], rfidcolortag[3], 0);
	ofDrawBitmapString(devicestatus[1], 600, 60);
	ofSetColor(Batterycolor[2], Batterycolor[3], 250);
	ofDrawBitmapString(batterystatus[1], 670, 60);

	ofSetColor(rfidcolortag[4], rfidcolortag[5], 0);
	ofDrawBitmapString(devicestatus[2], 600, 80);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[2], 670, 80);

	ofSetColor(rfidcolortag[6], rfidcolortag[7], 0);
	ofDrawBitmapString(devicestatus[3], 600, 100);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[3], 670, 100);

	ofSetColor(rfidcolortag[8], rfidcolortag[9], 0);
	ofDrawBitmapString(devicestatus[4], 600, 120);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[4], 670, 120);

	ofSetColor(rfidcolortag[10], rfidcolortag[11], 0);
	ofDrawBitmapString(devicestatus[5], 600, 140);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[5], 670, 140);

	ofSetColor(rfidcolortag[12], rfidcolortag[13], 0);
	ofDrawBitmapString(devicestatus[6], 600, 160);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[6], 670, 160);

	ofSetColor(rfidcolortag[14], rfidcolortag[15], 0);
	ofDrawBitmapString(devicestatus[7], 600, 180);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[7], 670, 180);

	ofSetColor(rfidcolortag[16], rfidcolortag[17], 0);
	ofDrawBitmapString(devicestatus[8], 600, 200);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[8], 670, 200);

	ofSetColor(rfidcolortag[18], rfidcolortag[19], 0);
	ofDrawBitmapString(devicestatus[9], 600, 220);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[9], 670, 220);

	ofSetColor(rfidcolortag[20], rfidcolortag[21], 0);
	ofDrawBitmapString(devicestatus[10], 600, 240);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[10], 670, 240);

	ofSetColor(rfidcolortag[22], rfidcolortag[23], 0);
	ofDrawBitmapString(devicestatus[11], 600, 260);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[11], 670, 260);

	ofSetColor(rfidcolortag[24], rfidcolortag[25], 0);
	ofDrawBitmapString(devicestatus[12], 600, 280);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[12], 670, 280);

	ofSetColor(rfidcolortag[26], rfidcolortag[27], 0);
	ofDrawBitmapString(devicestatus[13], 600, 300);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[13], 670, 300);      

	ofSetColor(rfidcolortag[28], rfidcolortag[29], 0);
	ofDrawBitmapString(devicestatus[14], 600, 320);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[14], 670, 320);

	ofSetColor(rfidcolortag[30], rfidcolortag[31], 0);
	ofDrawBitmapString(devicestatus[15], 600, 340);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[15], 670, 340);

	ofSetColor(rfidcolortag[32], rfidcolortag[33], 0);
	ofDrawBitmapString(devicestatus[16], 600, 360);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[16], 670, 360);

	ofSetColor(rfidcolortag[34], rfidcolortag[35], 0);
	ofDrawBitmapString(devicestatus[17], 600, 380);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[17], 670, 380);

	ofSetColor(rfidcolortag[36], rfidcolortag[37], 0);
	ofDrawBitmapString(devicestatus[18], 600, 400);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[18], 670, 400);

	ofSetColor(rfidcolortag[38], rfidcolortag[39], 0);
	ofDrawBitmapString(devicestatus[19], 600, 420);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[19], 670, 420);

	ofSetColor(rfidcolortag[40], rfidcolortag[41], 0);
	ofDrawBitmapString(devicestatus[20], 600, 440);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[20], 670, 440);

	ofSetColor(rfidcolortag[42], rfidcolortag[43], 0);
	ofDrawBitmapString(devicestatus[21], 600, 460);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[21], 670, 460);

	ofSetColor(rfidcolortag[44], rfidcolortag[45], 0);
	ofDrawBitmapString(devicestatus[22], 600, 480);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[22], 670, 480);

	ofSetColor(rfidcolortag[46], rfidcolortag[47], 0);
	ofDrawBitmapString(devicestatus[23], 600, 500);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[23], 670, 500);

	ofSetColor(rfidcolortag[48], rfidcolortag[49], 0);
	ofDrawBitmapString(devicestatus[24], 600, 520);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[24], 670, 520);

	ofSetColor(rfidcolortag[50], rfidcolortag[51], 0);
	ofDrawBitmapString(devicestatus[25], 600, 540);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[25], 670, 540);

	ofSetColor(rfidcolortag[52], rfidcolortag[53], 0);
	ofDrawBitmapString(devicestatus[26], 600, 560);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[26], 670, 560);

	ofSetColor(rfidcolortag[54], rfidcolortag[55], 0);
	ofDrawBitmapString(devicestatus[27], 600, 580);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[27], 670, 580);

	ofSetColor(rfidcolortag[56], rfidcolortag[57], 0);
	ofDrawBitmapString(devicestatus[28], 600, 600);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[28], 670, 600);

	ofSetColor(rfidcolortag[58], rfidcolortag[59], 0);
	ofDrawBitmapString(devicestatus[29], 600, 620);
	ofSetColor(250, 250, 250);
	ofDrawBitmapString(batterystatus[29], 670, 620);
}
//--------------------------------------------------------------
void ofApp::update(){}
//--------------------------------------------------------------
void ofApp::draw(){
	
	if (music_play_mode == true) {
		if (timer <= timer_csv)mp3_list(0);
		if (timer >= timer_csv && timer <= (timer_csv * 2) - 1)mp3_list(play_line);
		if (timer >= timer_csv * 2 && timer <= (timer_csv * 3) - 1)mp3_list(play_line);
		if (timer >= timer_csv * 3 && timer <= (timer_csv * 4) - 1)mp3_list(play_line);
		if (timer >= timer_csv * 4 && timer <= (timer_csv * 5) - 1)mp3_list(play_line);
		if (timer >= timer_csv * 5 && timer <= (timer_csv * 6) - 1)mp3_list(play_line);
		if (timer >= timer_csv * 6 && timer <= (timer_csv * 7) - 1)mp3_list(play_line);
		if (timer >= timer_csv * 7 && timer <= (timer_csv * 8) - 1)mp3_list(play_line);
		if (timer >= timer_csv * 8 && timer <= (timer_csv * 9) - 1)mp3_list(play_line);
		if (timer >= timer_csv * 9 && timer <= (timer_csv * 10) - 1)mp3_list(play_line);
		if (timer >= timer_csv * 10 && timer <= (timer_csv * 11) - 1)mp3_list(play_line);
		if (timer == timer_csv * 11) {
			time_reset = 1;
			timer = 0;
		}
	}
	if (music_play_mode == false)mp3_list(play_line);
	if (init_stage == 1)
	{
		devicestatus[0] = "STANDBY"; rfidcolortag[0] = 255; rfidcolortag[1] = 255;
		devicestatus[1] = "STANDBY"; rfidcolortag[2] = 255; rfidcolortag[3] = 255;
		devicestatus[2] = "STANDBY"; rfidcolortag[4] = 255; rfidcolortag[5] = 255;
		devicestatus[3] = "STANDBY"; rfidcolortag[6] = 255; rfidcolortag[7] = 255;
		devicestatus[4] = "STANDBY"; rfidcolortag[8] = 255; rfidcolortag[9] = 255;

		devicestatus[5] = "STANDBY"; rfidcolortag[10] = 255; rfidcolortag[11] = 255;
		devicestatus[6] = "STANDBY"; rfidcolortag[12] = 255; rfidcolortag[13] = 255;
		devicestatus[7] = "STANDBY"; rfidcolortag[14] = 255; rfidcolortag[15] = 255;
		devicestatus[8] = "STANDBY"; rfidcolortag[16] = 255; rfidcolortag[17] = 255;
		devicestatus[9] = "STANDBY"; rfidcolortag[18] = 255; rfidcolortag[19] = 255;

		devicestatus[10] = "STANDBY"; rfidcolortag[20] = 255; rfidcolortag[21] = 255;
		devicestatus[11] = "STANDBY"; rfidcolortag[22] = 255; rfidcolortag[23] = 255;
		devicestatus[12] = "STANDBY"; rfidcolortag[24] = 255; rfidcolortag[25] = 255;
		devicestatus[13] = "STANDBY"; rfidcolortag[26] = 255; rfidcolortag[27] = 255;
		devicestatus[14] = "STANDBY"; rfidcolortag[28] = 255; rfidcolortag[29] = 255;

		devicestatus[15] = "STANDBY"; rfidcolortag[30] = 255; rfidcolortag[31] = 255;
		devicestatus[16] = "STANDBY"; rfidcolortag[32] = 255; rfidcolortag[33] = 255;
		devicestatus[17] = "STANDBY"; rfidcolortag[34] = 255; rfidcolortag[35] = 255;
		devicestatus[18] = "STANDBY"; rfidcolortag[36] = 255; rfidcolortag[37] = 255;
		devicestatus[19] = "STANDBY"; rfidcolortag[38] = 255; rfidcolortag[39] = 255;

		devicestatus[20] = "STANDBY"; rfidcolortag[40] = 255; rfidcolortag[41] = 255;
		devicestatus[21] = "STANDBY"; rfidcolortag[42] = 255; rfidcolortag[43] = 255;
		devicestatus[22] = "STANDBY"; rfidcolortag[44] = 255; rfidcolortag[45] = 255;
		devicestatus[23] = "STANDBY"; rfidcolortag[46] = 255; rfidcolortag[47] = 255;
		devicestatus[24] = "STANDBY"; rfidcolortag[48] = 255; rfidcolortag[49] = 255;

		devicestatus[25] = "STANDBY"; rfidcolortag[50] = 255; rfidcolortag[51] = 255;
		devicestatus[26] = "STANDBY"; rfidcolortag[52] = 255; rfidcolortag[53] = 255;
		devicestatus[27] = "STANDBY"; rfidcolortag[54] = 255; rfidcolortag[55] = 255;
		devicestatus[28] = "STANDBY"; rfidcolortag[56] = 255; rfidcolortag[57] = 255;
		devicestatus[29] = "STANDBY"; rfidcolortag[58] = 255; rfidcolortag[59] = 255;
		devicestatus[30] = "STANDBY"; rfidcolortag[60] = 255; rfidcolortag[61] = 255;

		init_stage = 0;
	}
	if (rfid_status == 1) { devicestatus[0] = "ACTIVE"; rfidcolortag[0] = 0; rfidcolortag[1] = 255; }
	if (rfid_status == 2) { devicestatus[0] = "STANDBY"; rfidcolortag[0] = 255; rfidcolortag[1] = 255; }
	
	if (rfid_status == 3) { devicestatus[1] = "ACTIVE"; rfidcolortag[2] = 0; rfidcolortag[3] = 255; }
	if (rfid_status == 4) { devicestatus[1] = "STANDBY"; rfidcolortag[2] = 255; rfidcolortag[3] = 255; }
	
	devicelist();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'a')operation_mode = "auto";
	if (key == 'm')operation_mode = "manual";
	if (key == 's') {
		play_stop = 1;
		play_line = 0;
	}
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

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
