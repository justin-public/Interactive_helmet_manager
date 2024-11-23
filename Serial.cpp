#include "Serial.h"

string serialString;
string partString;
float readTime;

string SERIAL::ofxGetSerialString(ofSerial &serial, char until)
{
	static string str;
	stringstream ss;
	char ch;
	int ttl = 1000;

	while ((ch = serial.readByte()) > 0 && ttl-- > 0 && ch != until) {
		ss << ch;
	}
	str += ss.str();
	if (ch == until) {
		string tmp = str;
		str = "";
		return ofxTrimString(tmp);
	}
	else {
		return "";
	}
}

string SERIAL::ofxTrimStringRight(string str) {
	size_t endpos = str.find_last_not_of(" \t\r\n");
	return (string::npos != endpos) ? str.substr(0, endpos + 1) : str;
}

string SERIAL::ofxTrimStringLeft(string str) {
	size_t startpos = str.find_first_not_of(" \t\r\n");
	return (string::npos != startpos) ? str.substr(startpos) : str;
}

string SERIAL::ofxTrimString(string str)
{
	return ofxTrimStringLeft(ofxTrimStringRight(str));;
}

void SERIAL::setup()
{
	Serial.listDevices();
	vector<ofSerialDeviceInfo> deviceList = Serial.getDeviceList();
	int baud = 9600;
	Serial.setup(0, baud);
}

void SERIAL::update()
{
	serialString = "";
	serialString = ofxGetSerialString(Serial, '\n');

	if (serialString.length() > 0)
	{
		readTime = ofGetElapsedTimef();
		partString = serialString.substr(1, serialString.length() - 2);
	}
}

void SERIAL::draw()
{

}




