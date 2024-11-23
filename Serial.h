#ifndef _SERIAL_H
#define _SERIAL_H

#include "ofMain.h"
#include "extern.h"
#include "ofThread.h"

class SERIAL : public ofThread {
	public:
		void setup();
		void update();
		void draw();
		
		void threadedFunction() {
			while (isThreadRunning() != 0) {
				if (lock()) {
					SERIAL::update();
					unlock();
					ofSleepMillis(30);
				}
				//unlock();
				//ofSleepMillis(10);     // 10 
			}
		}
		
		//string Serialupdate(string parsdata);
		string ofxGetSerialString(ofSerial &serial, char until);
		string ofxTrimStringRight(string str);
		string ofxTrimStringLeft(string str);
		string ofxTrimString(string str);
		ofSerial Serial;
	private:
};

#endif
