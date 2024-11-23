#ifndef _CSV_H
#define _CSV_H

#include "ofMain.h"
#include "ofxCsv.h"
#include "ofThread.h"
#include "extern.h"

class CSV : public ofThread{
	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		
		void threadedFunction() {
			while (isThreadRunning() != 0) {
				if (lock()) {
					CSV::update();
					unlock();
					ofSleepMillis(30);
				}
				//unlock();
				//ofSleepMillis(10);       // 30
			}
		}
		
		ofxCsv csv;
		ofxCsvRow row;
		ofSoundPlayer myMp3;
	private:
};

#endif
