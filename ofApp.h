#pragma once

#include "ofMain.h"
#include "Network.h"
#include "Serial.h"
#include "ofCSV.h"
#include "ofxGui.h"
#include "ofxTimerEventTable.h"
#include "ofxCsv.h"
#include "extern.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void devicelist();
		void mp3_list(int music_list);
		
		//NETWORK socketTCP;       // socket class
		//SERIAL ofxSerial;        // Serial class
		//CSV CSVFORMAT;           // CSV class

		SERIAL  thread1;
		CSV		thread2;
		NETWORK thread3;
};




