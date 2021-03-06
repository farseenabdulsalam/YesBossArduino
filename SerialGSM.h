#ifndef _SerialGSM_H
#define _SerialGSM_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "GlobalOptions.h"
#include "Utils.h"


#define SERIALTIMEOUT 2000
#define MAXMSGLEN 160
#define MAXPHONELEN 15
#define BUFFERLEN 50

class SerialGSM : public SoftwareSerial {
public:
  struct SMS {
    char phone_no[MAXPHONELEN];
    char message[MAXMSGLEN];
  };

  SerialGSM(int rxpin,int txpin);
  /* returns:
   * 0 if succeed
   * 1 if length of the message>MAXMSGLEN
   * 2 for some other errors
   */
  byte sendSMS(SMS& sms);
  void deleteAllSMS();
  void reset();
  int receiveSMS(SMS& sms);
  void boot();
  void debug_loop();

protected:
  unsigned long lastrec;
  void fwdSMS2Serial();
  char buffer[BUFFERLEN];
  int response;
  int length_read;
  int readline(char buffer[],int bufferlen,int& length_read);
  void print_d(const char *s);
  void println_d(const char *s);
  void print_d(const char s);
  void println_d(const char s);
  bool debug_show_prompt = true;
};

#endif /* not defined _SerialGSM_H */


