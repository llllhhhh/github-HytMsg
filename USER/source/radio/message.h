#ifndef _MESSAGE_H_
#define _MESSAGE_H_


//是否启用集群模式
#define  TRUNKING_MODE

#ifdef  TRUNKING_MODE
  #include "radio/hdtap.h"

#else
  #include "radio/hdpep.h"

#endif

#include "log/log.h"
#include "app.h"

#define MSG_DATA 0x01
#define MSG_ACK  0x00
#define MSG_ALIVE 0x02
#define MSG_NACK 0xFF

#define MAX_MSG_DATA_SIZE 62//多出的两个字节用来存储checksum数据
#define Msg_Header 0xFFFE


#pragma pack(1)

typedef struct
{
    unsigned short Header;
    unsigned short Address;
    unsigned char Opcode;
    unsigned char Length;
    
}MessageHeader_t;


typedef struct
{
    MessageHeader_t Header;
    unsigned char Payload[MAX_MSG_DATA_SIZE];
    unsigned short Checksum;
}Message_t;

typedef struct
{
    MessageHeader_t Header;
    unsigned short Checksum;
}Message_ack_t;



#pragma pack()


unsigned short msg_checksum(Message_t * msg);

void msg_init(void);
void msg_send( Message_t * msg);
unsigned char  msg_receive(Message_t * msg);
void msg_receive_event(void * msg);
#endif