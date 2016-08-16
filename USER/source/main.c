/*******************************************************************************
* File Name       main.c
* Anthor          WXJ     
* Version         V1.00
* Date            2013/7/30
* Description     --    
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include <wchar.h>

#include "stm32f10x.h"

#include "main.h"
#include "radio/message.h"
#include "app.h"


/*******************************************************************************
* Function Nmae     main
* Date              2013/7/30
* Anthor            WXJ
* Input Parameter   None
* Output Parameter  None
* Description       --
* File              main.c
*******************************************************************************/

#define SYSTEM_CLOCK 72000000
unsigned char ble_alive_flag = 0;
unsigned char  ble_rx_counter = 0;

int main ( void )
{  
    SysTick_Config(SYSTEM_CLOCK / 1000);  //1ms   
  
    log_init();
    printf("log iniitlize finish\r\n");
    
    
    msg_init();
    ble_init();  

    Message_t Message, * Msg = &Message;
    
    for(;;)
    {        
        if(SUCCESS == ble_receive(Msg))
        {
            printf("\r\n Ble_receive \r\n");
            msg_send(Msg);
        }
        
        if(SUCCESS == msg_receive(Msg))
        {
            ble_send(Msg);
        }
    } 
    while(1);
      
    return 0;
} /* End of main */             
/***************************** End of File ************************************/

//
//PUTCHAR_PROTOTYPE
//{
//    
//
//    return ch;
//} /* End of PUTCHAR_PROTOTYPE */