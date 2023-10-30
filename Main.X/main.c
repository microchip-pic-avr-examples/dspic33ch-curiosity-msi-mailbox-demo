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
#include <string.h>
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/secondary_core/sec_core1.h"
#include "mcc_generated_files/system/pins.h"

/* Create a pointer of type SEC_CORE_INTERFACE and assign it to the address of the MSIInterface SEC_CORE_INTERFACE struct.
This enables us to get access the portable API interface. */
const struct SEC_CORE_INTERFACE *secondaryCore =  &MSIInterface;

#define DATA_UNDER_TEST       0xAAAA       // data used for protocol write and read test

uint16_t dataSend[MSI1_ProtocolA_SIZE];      //for Protocol size refer sec_core_types.h file
uint16_t dataReceive[MSI1_ProtocolB_SIZE];

int main(void)
{
    SYSTEM_Initialize();
 
    secondaryCore->Initialize();
    secondaryCore->Program();
    secondaryCore->Start();
    
    dataSend[0] =  DATA_UNDER_TEST;         //Initializing to known value.
    dataReceive[0] = 0;
    
    //Mailbox write
    secondaryCore->ProtocolWrite(MSI1_ProtocolA, (uint16_t*)dataSend);
 
    //Issue interrupt to secondary
    secondaryCore->InterruptRequestGenerate();
    while(!secondaryCore->IsInterruptRequestAcknowledged());
    secondaryCore->InterruptRequestComplete();
    while(secondaryCore->IsInterruptRequestAcknowledged());
 
    //Wait for interrupt from secondary
    while(!secondaryCore->IsInterruptRequested());
    secondaryCore->InterruptRequestAcknowledge();
    while(secondaryCore->IsInterruptRequested());
    secondaryCore->InterruptRequestAcknowledgeComplete();   
 
    //Mailbox read
    secondaryCore->ProtocolRead(MSI1_ProtocolB, (uint16_t*)dataReceive);
 
    //Glow LED on data match
    if(memcmp(dataSend, dataReceive, sizeof(dataSend)) == 0)
    {
        LED_Main_SetHigh();
    }
    else
    {
        LED_Main_SetLow();
    }
    while(1)
    {

    }    
}
