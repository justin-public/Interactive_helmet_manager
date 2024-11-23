#ifndef _NETWORK_H
#define _NETWORK_H

#include "ofMain.h"
#include "ofxNetwork.h"
#include "extern.h"
#include "ofThread.h"
#include "ofxTimerEventTable.h"

class NETWORK : public ofThread{
	public:
		void setup();
		void update();
		void draw();

		void threadedFunction(){
			while (isThreadRunning() != 0) {
				if (lock()) {
					NETWORK::update();
					unlock();
					ofSleepMillis(30);
				}
				//unlock();
				//ofSleepMillis(10);       // 30
			}
		}
		ofxTCPServer TCP;
		ofxTCPManager TCPmanager;
		ofxTE::ofxTimerEvents events;
		vector <string> storeText;
		//NETWORK();
	private:
};



#endif // !_NETWORK_H


