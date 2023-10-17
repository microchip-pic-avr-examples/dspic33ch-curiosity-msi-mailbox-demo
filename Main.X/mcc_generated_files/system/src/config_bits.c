/**
 * CONFIGURATION_BITS Generated Driver Source File 
 * 
 * @file      configuration_bits.c
 *            
 * @defgroup  config_bitsdriver CONFIGBITS Driver
 *            
 * @brief     Device Configuration Bits using dsPIC MCUs
 *
 * @version   Firmware Driver Version 1.0.1
 *
 * @version   PLIB Version 1.2.2-rc.1
 *
 * @skipline  Device : dsPIC33CH128MP508
*/

/*
� [2023] Microchip Technology Inc. and its subsidiaries.

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

// Configuration bits: selected in the GUI

// FSEC
#pragma config BWRP = OFF    //Boot Segment Write-Protect bit->Boot Segment may be written
#pragma config BSS = DISABLED    //Boot Segment Code-Protect Level bits->No Protection (other than BWRP)
#pragma config BSEN = OFF    //Boot Segment Control bit->No Boot Segment
#pragma config GWRP = OFF    //General Segment Write-Protect bit->General Segment may be written
#pragma config GSS = DISABLED    //General Segment Code-Protect Level bits->No Protection (other than GWRP)
#pragma config CWRP = OFF    //Configuration Segment Write-Protect bit->Configuration Segment may be written
#pragma config CSS = DISABLED    //Configuration Segment Code-Protect Level bits->No Protection (other than CWRP)
#pragma config AIVTDIS = OFF    //Alternate Interrupt Vector Table bit->Disabled AIVT

// FBSLIM
#pragma config BSLIM = 0x1fff    //Boot Segment Flash Page Address Limit bits

// FOSCSEL
#pragma config FNOSC = FRC    //Oscillator Source Selection->Internal Fast RC (FRC)
#pragma config IESO = OFF    //Two-speed Oscillator Start-up Enable bit->Start up with user-selected oscillator source

// FOSC
#pragma config POSCMD = NONE    //Primary Oscillator Mode Select bits->Primary Oscillator disabled
#pragma config OSCIOFNC = ON    //OSC2 Pin Function bit->OSC2 is general purpose digital I/O pin
#pragma config FCKSM = CSDCMD    //Clock Switching Mode bits->Both Clock switching and Fail-safe Clock Monitor are disabled
#pragma config PLLKEN = PLLKEN_ON    //PLLKEN->reserved as PLLKEN_ON
#pragma config XTCFG = G3    //XT Config->24-32 MHz crystals
#pragma config XTBST = ENABLE    //XT Boost->Boost the kick-start

// FWDT
#pragma config RWDTPS = PS1048576    //Run Mode Watchdog Timer Post Scaler select bits->1:1048576
#pragma config RCLKSEL = LPRC    //Watchdog Timer Clock Select bits->Always use LPRC
#pragma config WINDIS = ON    //Watchdog Timer Window Enable bit->Watchdog Timer in Non-Window mode
#pragma config WDTWIN = WIN25    //Watchdog Timer Window Select bits->WDT Window is 25% of WDT period
#pragma config SWDTPS = PS1048576    //Sleep Mode Watchdog Timer Post Scaler select bits->1:1048576
#pragma config FWDTEN = ON_SW    //Watchdog Timer Enable bit->WDT controlled via SW, use WDTCON.ON bit

// FICD
#pragma config ICS = PGD1    //ICD Communication Channel Select bits->Communicate on PGC1 and PGD1
#pragma config JTAGEN = OFF    //JTAG Enable bit->JTAG is disabled

// FDMTIVTL
#pragma config DMTIVTL = 0x0    //Dead Man Timer Interval low word

// FDMTIVTH
#pragma config DMTIVTH = 0x0    //Dead Man Timer Interval high word

// FDMTCNTL
#pragma config DMTCNTL = 0x0    //Lower 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF)

// FDMTCNTH
#pragma config DMTCNTH = 0x0    //Upper 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF)

// FDMT
#pragma config DMTDIS = OFF    //Dead Man Timer Disable bit->Dead Man Timer is Disabled and can be enabled by software

// FDEVOPT
#pragma config ALTI2C1 = OFF    //Alternate I2C1 Pin bit->I2C1 mapped to SDA1/SCL1 pins
#pragma config ALTI2C2 = OFF    //Alternate I2C2 Pin bit->I2C2 mapped to SDA2/SCL2 pins
#pragma config SMBEN = SMBUS    //SM Bus Enable->SMBus input threshold is enabled
#pragma config SPI2PIN = PPS    //SPI2 Pin Select bit->SPI2 uses I/O remap (PPS) pins

// FALTREG
#pragma config CTXT1 = OFF    //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits->Not Assigned
#pragma config CTXT2 = OFF    //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits->Not Assigned
#pragma config CTXT3 = OFF    //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 3 bits->Not Assigned
#pragma config CTXT4 = OFF    //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 4 bits->Not Assigned

// FCFGPRA0
#pragma config CPRA0 = MAIN    //Pin RA0 Ownership Bits->Main core owns pin.
#pragma config CPRA1 = MAIN    //Pin RA1 Ownership Bits->Main core owns pin.
#pragma config CPRA2 = MAIN    //Pin RA2 Ownership Bits->Main core owns pin.
#pragma config CPRA3 = MAIN    //Pin RA3 Ownership Bits->Main core owns pin.
#pragma config CPRA4 = MAIN    //Pin RA4 Ownership Bits->Main core owns pin.

// FCFGPRB0
#pragma config CPRB0 = MAIN    //Pin RB0 Ownership Bits->Main core owns pin.
#pragma config CPRB1 = MAIN    //Pin RB1 Ownership Bits->Main core owns pin.
#pragma config CPRB2 = MAIN    //Pin RB2 Ownership Bits->Main core owns pin.
#pragma config CPRB3 = MAIN    //Pin RB3 Ownership Bits->Main core owns pin.
#pragma config CPRB4 = MAIN    //Pin RB4 Ownership Bits->Main core owns pin.
#pragma config CPRB5 = MAIN    //Pin RB5 Ownership Bits->Main core owns pin.
#pragma config CPRB6 = MAIN    //Pin RB6 Ownership Bits->Main core owns pin.
#pragma config CPRB7 = MAIN    //Pin RB7 Ownership Bits->Main core owns pin.
#pragma config CPRB8 = MAIN    //Pin RB8 Ownership Bits->Main core owns pin.
#pragma config CPRB9 = MAIN    //Pin RB9 Ownership Bits->Main core owns pin.
#pragma config CPRB10 = MAIN    //Pin RB10 Ownership Bits->Main core owns pin.
#pragma config CPRB11 = MAIN    //Pin RB11 Ownership Bits->Main core owns pin.
#pragma config CPRB12 = MAIN    //Pin RB12 Ownership Bits->Main core owns pin.
#pragma config CPRB13 = MAIN    //Pin RB13 Ownership Bits->Main core owns pin.
#pragma config CPRB14 = MAIN    //Pin RB14 Ownership Bits->Main core owns pin.
#pragma config CPRB15 = MAIN    //Pin RB15 Ownership Bits->Main core owns pin.

// FCFGPRC0
#pragma config CPRC0 = MAIN    //Pin RC0 Ownership Bits->Main core owns pin.
#pragma config CPRC1 = MAIN    //Pin RC1 Ownership Bits->Main core owns pin.
#pragma config CPRC2 = MAIN    //Pin RC2 Ownership Bits->Main core owns pin.
#pragma config CPRC3 = MAIN    //Pin RC3 Ownership Bits->Main core owns pin.
#pragma config CPRC4 = MAIN    //Pin RC4 Ownership Bits->Main core owns pin.
#pragma config CPRC5 = MAIN    //Pin RC5 Ownership Bits->Main core owns pin.
#pragma config CPRC6 = MAIN    //Pin RC6 Ownership Bits->Main core owns pin.
#pragma config CPRC7 = MAIN    //Pin RC7 Ownership Bits->Main core owns pin.
#pragma config CPRC8 = MAIN    //Pin RC8 Ownership Bits->Main core owns pin.
#pragma config CPRC9 = MAIN    //Pin RC9 Ownership Bits->Main core owns pin.
#pragma config CPRC10 = MAIN    //Pin RC10 Ownership Bits->Main core owns pin.
#pragma config CPRC11 = MAIN    //Pin RC11 Ownership Bits->Main core owns pin.
#pragma config CPRC12 = MAIN    //Pin RC12 Ownership Bits->Main core owns pin.
#pragma config CPRC13 = MAIN    //Pin RC13 Ownership Bits->Main core owns pin.
#pragma config CPRC14 = MAIN    //Pin RC14 Ownership Bits->Main core owns pin.
#pragma config CPRC15 = MAIN    //Pin RC15 Ownership Bits->Main core owns pin.

// FCFGPRD0
#pragma config CPRD0 = MAIN    //Pin RD0 Ownership Bits->Main core owns pin.
#pragma config CPRD1 = MAIN    //Pin RD1 Ownership Bits->Main core owns pin.
#pragma config CPRD2 = MAIN    //Pin RD2 Ownership Bits->Main core owns pin.
#pragma config CPRD3 = MAIN    //Pin RD3 Ownership Bits->Main core owns pin.
#pragma config CPRD4 = MAIN    //Pin RD4 Ownership Bits->Main core owns pin.
#pragma config CPRD5 = MAIN    //Pin RD5 Ownership Bits->Main core owns pin.
#pragma config CPRD6 = MAIN    //Pin RD6 Ownership Bits->Main core owns pin.
#pragma config CPRD7 = MAIN    //Pin RD7 Ownership Bits->Main core owns pin.
#pragma config CPRD8 = MAIN    //Pin RD8 Ownership Bits->Main core owns pin.
#pragma config CPRD9 = MAIN    //Pin RD9 Ownership Bits->Main core owns pin.
#pragma config CPRD10 = MAIN    //Pin RD10 Ownership Bits->Main core owns pin.
#pragma config CPRD11 = MAIN    //Pin RD11 Ownership Bits->Main core owns pin.
#pragma config CPRD12 = MAIN    //Pin RD12 Ownership Bits->Main core owns pin.
#pragma config CPRD13 = MAIN    //Pin RD13 Ownership Bits->Main core owns pin.
#pragma config CPRD14 = MAIN    //Pin RD14 Ownership Bits->Main core owns pin.
#pragma config CPRD15 = MAIN    //Pin RD15 Ownership Bits->Main core owns pin.

// FCFGPRE0
#pragma config CPRE0 = MAIN    //Pin RE0 Ownership Bits->Main core owns pin.
#pragma config CPRE1 = SEC1    //Pin RE1 Ownership Bits->Secondary core owns pin.
#pragma config CPRE2 = MAIN    //Pin RE2 Ownership Bits->Main core owns pin.
#pragma config CPRE3 = MAIN    //Pin RE3 Ownership Bits->Main core owns pin.
#pragma config CPRE4 = MAIN    //Pin RE4 Ownership Bits->Main core owns pin.
#pragma config CPRE5 = MAIN    //Pin RE5 Ownership Bits->Main core owns pin.
#pragma config CPRE6 = MAIN    //Pin RE6 Ownership Bits->Main core owns pin.
#pragma config CPRE7 = MAIN    //Pin RE7 Ownership Bits->Main core owns pin.
#pragma config CPRE8 = MAIN    //Pin RE8 Ownership Bits->Main core owns pin.
#pragma config CPRE9 = MAIN    //Pin RE9 Ownership Bits->Main core owns pin.
#pragma config CPRE10 = MAIN    //Pin RE10 Ownership Bits->Main core owns pin.
#pragma config CPRE11 = MAIN    //Pin RE11 Ownership Bits->Main core owns pin.
#pragma config CPRE12 = MAIN    //Pin RE12 Ownership Bits->Main core owns pin.
#pragma config CPRE13 = MAIN    //Pin RE13 Ownership Bits->Main core owns pin.
#pragma config CPRE14 = MAIN    //Pin RE14 Ownership Bits->Main core owns pin.
#pragma config CPRE15 = MAIN    //Pin RE15 Ownership Bits->Main core owns pin.

/**
 End of File
*/