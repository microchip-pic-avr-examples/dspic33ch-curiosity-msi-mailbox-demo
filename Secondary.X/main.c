/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include <inttypes.h>
#include <string.h>
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/main_core/main_core.h"

#define DATA_UNDER_TEST 0xAAAA        // data used for protocol write and read test

/* Create a pointer of type MAIN_CORE_INTERFACE and assign it to the address of the MSIInterface MAIN_CORE_INTERFACE struct.
This enables us to get access the portable API interface. */
const struct MAIN_CORE_INTERFACE *mainCore = &MSIInterface;

uint16_t dataReceive[MSI1_ProtocolA_SIZE];    //for Protocol size refer main_core_types.h file
uint16_t dataSend[MSI1_ProtocolB_SIZE];

int main(void)
{
    SYSTEM_Initialize();

    //Wait for interrupt from Main core    
    while(!mainCore->IsInterruptRequested());
    mainCore->InterruptRequestAcknowledge();
    while(mainCore->IsInterruptRequested());
    mainCore->InterruptRequestAcknowledgeComplete();
 
    //Mailbox read    
    mainCore->ProtocolRead(MSI1_ProtocolA, (uint16_t*)dataReceive);
    //Copy the received data for retransmission
    memcpy(dataSend, dataReceive, sizeof(dataReceive));
    //Retransmits Mailbox 
    mainCore->ProtocolWrite(MSI1_ProtocolB, (uint16_t*)dataSend);
 
    //Issue interrupt to Main core
    mainCore->InterruptRequestGenerate();
    while(!mainCore->IsInterruptRequestAcknowledged());
    mainCore->InterruptRequestComplete();
    while(mainCore->IsInterruptRequestAcknowledged());
 
    //Glow LED on data match
    if(dataReceive[0] == DATA_UNDER_TEST)
    {
        LED_Secondary_SetHigh();
    }
    else
    {
        LED_Secondary_SetLow();
    }
    while(1)
    {

    }    
}
