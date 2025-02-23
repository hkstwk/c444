EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:switches
LIBS:ledcube444-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Led Cube 4x4x4"
Date "2018-02-11"
Rev "0.1"
Comp "schematic created by Harm Kolvoort"
Comment1 "Best results so far using birght blue 3mm leds from China"
Comment2 "4 transistors to control layer is active (grounded when transitor is on)"
Comment3 "2 shift registers to control HIGH/LOW on 16 leds"
Comment4 "4x4x4 led cube driven by atmega328p"
$EndDescr
$Comp
L Conn_02x10_Counter_Clockwise J1
U 1 1 5A741846
P 9250 1200
F 0 "J1" H 9300 1700 50  0000 C CNN
F 1 "CubeConnector_02x10" H 9300 600 50  0000 C CNN
F 2 "" H 9250 1200 50  0001 C CNN
F 3 "" H 9250 1200 50  0001 C CNN
	1    9250 1200
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5A74C0B9
P 8650 800
F 0 "R1" V 8700 650 50  0000 C CNN
F 1 "220" V 8650 800 50  0000 C CNN
F 2 "" V 8580 800 50  0001 C CNN
F 3 "" H 8650 800 50  0001 C CNN
	1    8650 800 
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 5A74C18A
P 8650 900
F 0 "R2" V 8700 750 50  0000 C CNN
F 1 "220" V 8650 900 50  0000 C CNN
F 2 "" V 8580 900 50  0001 C CNN
F 3 "" H 8650 900 50  0001 C CNN
	1    8650 900 
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 5A74C3E4
P 8650 1000
F 0 "R3" V 8700 850 50  0000 C CNN
F 1 "220" V 8650 1000 50  0000 C CNN
F 2 "" V 8580 1000 50  0001 C CNN
F 3 "" H 8650 1000 50  0001 C CNN
	1    8650 1000
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 5A74C51B
P 8650 1100
F 0 "R4" V 8700 950 50  0000 C CNN
F 1 "220" V 8650 1100 50  0000 C CNN
F 2 "" V 8580 1100 50  0001 C CNN
F 3 "" H 8650 1100 50  0001 C CNN
	1    8650 1100
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 5A74C635
P 8650 1200
F 0 "R5" V 8700 1050 50  0000 C CNN
F 1 "220" V 8650 1200 50  0000 C CNN
F 2 "" V 8580 1200 50  0001 C CNN
F 3 "" H 8650 1200 50  0001 C CNN
	1    8650 1200
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 5A74C63B
P 8650 1300
F 0 "R6" V 8700 1150 50  0000 C CNN
F 1 "220" V 8650 1300 50  0000 C CNN
F 2 "" V 8580 1300 50  0001 C CNN
F 3 "" H 8650 1300 50  0001 C CNN
	1    8650 1300
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 5A74C641
P 8650 1400
F 0 "R7" V 8700 1250 50  0000 C CNN
F 1 "220" V 8650 1400 50  0000 C CNN
F 2 "" V 8580 1400 50  0001 C CNN
F 3 "" H 8650 1400 50  0001 C CNN
	1    8650 1400
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 5A74C647
P 8650 1500
F 0 "R8" V 8700 1350 50  0000 C CNN
F 1 "220" V 8650 1500 50  0000 C CNN
F 2 "" V 8580 1500 50  0001 C CNN
F 3 "" H 8650 1500 50  0001 C CNN
	1    8650 1500
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 5A74C6A9
P 8650 1600
F 0 "R9" V 8700 1450 50  0000 C CNN
F 1 "220" V 8650 1600 50  0000 C CNN
F 2 "" V 8580 1600 50  0001 C CNN
F 3 "" H 8650 1600 50  0001 C CNN
	1    8650 1600
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 5A74C6AF
P 8650 1700
F 0 "R10" V 8700 1550 50  0000 C CNN
F 1 "220" V 8650 1700 50  0000 C CNN
F 2 "" V 8580 1700 50  0001 C CNN
F 3 "" H 8650 1700 50  0001 C CNN
	1    8650 1700
	0    1    1    0   
$EndComp
$Comp
L R R11
U 1 1 5A74CA58
P 9950 1200
F 0 "R11" V 10000 1050 50  0000 C CNN
F 1 "220" V 9950 1200 50  0000 C CNN
F 2 "" V 9880 1200 50  0001 C CNN
F 3 "" H 9950 1200 50  0001 C CNN
	1    9950 1200
	0    -1   1    0   
$EndComp
$Comp
L R R12
U 1 1 5A74CA5E
P 9950 1300
F 0 "R12" V 10000 1150 50  0000 C CNN
F 1 "220" V 9950 1300 50  0000 C CNN
F 2 "" V 9880 1300 50  0001 C CNN
F 3 "" H 9950 1300 50  0001 C CNN
	1    9950 1300
	0    -1   1    0   
$EndComp
$Comp
L R R13
U 1 1 5A74CA64
P 9950 1400
F 0 "R13" V 10000 1250 50  0000 C CNN
F 1 "220" V 9950 1400 50  0000 C CNN
F 2 "" V 9880 1400 50  0001 C CNN
F 3 "" H 9950 1400 50  0001 C CNN
	1    9950 1400
	0    -1   1    0   
$EndComp
$Comp
L R R14
U 1 1 5A74CA6A
P 9950 1500
F 0 "R14" V 10000 1350 50  0000 C CNN
F 1 "220" V 9950 1500 50  0000 C CNN
F 2 "" V 9880 1500 50  0001 C CNN
F 3 "" H 9950 1500 50  0001 C CNN
	1    9950 1500
	0    -1   1    0   
$EndComp
$Comp
L R R15
U 1 1 5A74CA70
P 9950 1600
F 0 "R15" V 10000 1450 50  0000 C CNN
F 1 "220" V 9950 1600 50  0000 C CNN
F 2 "" V 9880 1600 50  0001 C CNN
F 3 "" H 9950 1600 50  0001 C CNN
	1    9950 1600
	0    -1   1    0   
$EndComp
$Comp
L R R16
U 1 1 5A74CA76
P 9950 1700
F 0 "R16" V 10000 1550 50  0000 C CNN
F 1 "220" V 9950 1700 50  0000 C CNN
F 2 "" V 9880 1700 50  0001 C CNN
F 3 "" H 9950 1700 50  0001 C CNN
	1    9950 1700
	0    -1   1    0   
$EndComp
$Comp
L Q_NPN_CBE Q1
U 1 1 5A74D0EA
P 10700 4850
F 0 "Q1" H 10900 4900 50  0000 L CNN
F 1 "NPN3" H 10900 4800 50  0000 L CNN
F 2 "" H 10900 4950 50  0001 C CNN
F 3 "" H 10700 4850 50  0001 C CNN
	1    10700 4850
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_CBE Q2
U 1 1 5A74D15A
P 9900 4850
F 0 "Q2" H 10100 4900 50  0000 L CNN
F 1 "NPN2" H 10100 4800 50  0000 L CNN
F 2 "" H 10100 4950 50  0001 C CNN
F 3 "" H 9900 4850 50  0001 C CNN
	1    9900 4850
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_CBE Q3
U 1 1 5A74D1A4
P 9100 4850
F 0 "Q3" H 9300 4900 50  0000 L CNN
F 1 "NPN1" H 9300 4800 50  0000 L CNN
F 2 "" H 9300 4950 50  0001 C CNN
F 3 "" H 9100 4850 50  0001 C CNN
	1    9100 4850
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_CBE Q4
U 1 1 5A74D209
P 8300 4850
F 0 "Q4" H 8500 4900 50  0000 L CNN
F 1 "NPN0" H 8500 4800 50  0000 L CNN
F 2 "" H 8500 4950 50  0001 C CNN
F 3 "" H 8300 4850 50  0001 C CNN
	1    8300 4850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5A74D56D
P 10800 5250
F 0 "#PWR01" H 10800 5000 50  0001 C CNN
F 1 "GND" H 10800 5100 50  0000 C CNN
F 2 "" H 10800 5250 50  0001 C CNN
F 3 "" H 10800 5250 50  0001 C CNN
	1    10800 5250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5A74D5AB
P 10000 5250
F 0 "#PWR02" H 10000 5000 50  0001 C CNN
F 1 "GND" H 10000 5100 50  0000 C CNN
F 2 "" H 10000 5250 50  0001 C CNN
F 3 "" H 10000 5250 50  0001 C CNN
	1    10000 5250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5A74D5E9
P 9200 5250
F 0 "#PWR03" H 9200 5000 50  0001 C CNN
F 1 "GND" H 9200 5100 50  0000 C CNN
F 2 "" H 9200 5250 50  0001 C CNN
F 3 "" H 9200 5250 50  0001 C CNN
	1    9200 5250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5A74D627
P 8400 5250
F 0 "#PWR04" H 8400 5000 50  0001 C CNN
F 1 "GND" H 8400 5100 50  0000 C CNN
F 2 "" H 8400 5250 50  0001 C CNN
F 3 "" H 8400 5250 50  0001 C CNN
	1    8400 5250
	1    0    0    -1  
$EndComp
$Comp
L R R21
U 1 1 5A74DA17
P 10500 4600
F 0 "R21" V 10400 4600 50  0000 C CNN
F 1 "10k" V 10500 4600 50  0000 C CNN
F 2 "" V 10430 4600 50  0001 C CNN
F 3 "" H 10500 4600 50  0001 C CNN
	1    10500 4600
	-1   0    0    1   
$EndComp
$Comp
L R R22
U 1 1 5A74DACF
P 9700 4600
F 0 "R22" V 9800 4600 50  0000 C CNN
F 1 "10k" V 9700 4600 50  0000 C CNN
F 2 "" V 9630 4600 50  0001 C CNN
F 3 "" H 9700 4600 50  0001 C CNN
	1    9700 4600
	1    0    0    -1  
$EndComp
$Comp
L R R23
U 1 1 5A74DB5C
P 8900 4600
F 0 "R23" V 9000 4600 50  0000 C CNN
F 1 "10k" V 8900 4600 50  0000 C CNN
F 2 "" V 8830 4600 50  0001 C CNN
F 3 "" H 8900 4600 50  0001 C CNN
	1    8900 4600
	1    0    0    -1  
$EndComp
$Comp
L R R24
U 1 1 5A74DBE0
P 8100 4600
F 0 "R24" V 8200 4600 50  0000 C CNN
F 1 "10k" V 8100 4600 50  0000 C CNN
F 2 "" V 8030 4600 50  0001 C CNN
F 3 "" H 8100 4600 50  0001 C CNN
	1    8100 4600
	1    0    0    -1  
$EndComp
Text Label 10500 4100 3    60   ~ 0
PB3
Text Label 9700 4100 3    60   ~ 0
PB2
Text Label 8900 4100 3    60   ~ 0
PB1
Text Label 8100 4100 3    60   ~ 0
PB0
$Comp
L ATMEGA328P-PU U1
U 1 1 5A74FAF5
P 2400 2300
F 0 "U1" H 1650 3550 50  0000 L BNN
F 1 "ATMEGA328P-PU" H 2200 900 50  0000 L BNN
F 2 "DIL28" H 2400 2300 50  0001 C CIN
F 3 "" H 2400 2300 50  0001 C CNN
	1    2400 2300
	1    0    0    -1  
$EndComp
$Comp
L 74HC595 U2
U 1 1 5A74FE46
P 7100 1250
F 0 "U2" H 7250 1850 50  0000 C CNN
F 1 "74HC595" H 7100 650 50  0000 C CNN
F 2 "" H 7100 1250 50  0001 C CNN
F 3 "" H 7100 1250 50  0001 C CNN
	1    7100 1250
	1    0    0    -1  
$EndComp
$Comp
L 74HC595 U3
U 1 1 5A74FEDA
P 8500 2900
F 0 "U3" H 8650 3500 50  0000 C CNN
F 1 "74HC595" H 8500 2300 50  0000 C CNN
F 2 "" H 8500 2900 50  0001 C CNN
F 3 "" H 8500 2900 50  0001 C CNN
	1    8500 2900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 5A750AD1
P 1200 3500
F 0 "#PWR05" H 1200 3250 50  0001 C CNN
F 1 "GND" V 1200 3300 50  0000 C CNN
F 2 "" H 1200 3500 50  0001 C CNN
F 3 "" H 1200 3500 50  0001 C CNN
	1    1200 3500
	0    1    1    0   
$EndComp
Text Label 3750 1200 0    60   ~ 0
PB0
Text Label 3750 1300 0    60   ~ 0
PB1
Text Label 3750 1400 0    60   ~ 0
PB2
Text Label 3750 1500 0    60   ~ 0
PB3
$Comp
L VCC #PWR06
U 1 1 5A752EEF
P 1200 1200
F 0 "#PWR06" H 1200 1050 50  0001 C CNN
F 1 "VCC" V 1200 1400 50  0000 C CNN
F 2 "" H 1200 1200 50  0001 C CNN
F 3 "" H 1200 1200 50  0001 C CNN
	1    1200 1200
	0    -1   -1   0   
$EndComp
NoConn ~ 9200 3350
$Comp
L Conn_01x02_Male J2
U 1 1 5A7716B4
P 3400 7100
F 0 "J2" H 3400 7200 50  0000 C CNN
F 1 "Conn_Male_PWR" H 3400 6900 50  0000 C CNN
F 2 "" H 3400 7100 50  0001 C CNN
F 3 "" H 3400 7100 50  0001 C CNN
	1    3400 7100
	1    0    0    -1  
$EndComp
Text Label 4050 7100 0    60   ~ 0
VCC
Text Label 4050 7200 0    60   ~ 0
GND
$Comp
L PWR_FLAG #FLG07
U 1 1 5A772216
P 3750 6900
F 0 "#FLG07" H 3750 6975 50  0001 C CNN
F 1 "PWR_FLAG" H 3750 7050 50  0000 C CNN
F 2 "" H 3750 6900 50  0001 C CNN
F 3 "" H 3750 6900 50  0001 C CNN
	1    3750 6900
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG08
U 1 1 5A772339
P 3750 7400
F 0 "#FLG08" H 3750 7475 50  0001 C CNN
F 1 "PWR_FLAG" H 3750 7550 50  0000 C CNN
F 2 "" H 3750 7400 50  0001 C CNN
F 3 "" H 3750 7400 50  0001 C CNN
	1    3750 7400
	-1   0    0    1   
$EndComp
$Comp
L SW_Push_Dual SW1
U 1 1 5A772A23
P 2100 6550
F 0 "SW1" H 2150 6650 50  0000 L CNN
F 1 "Reset_Btn" H 2100 6280 50  0000 C CNN
F 2 "" H 2100 6750 50  0001 C CNN
F 3 "" H 2100 6750 50  0001 C CNN
	1    2100 6550
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR09
U 1 1 5A772EE0
P 2100 7400
F 0 "#PWR09" H 2100 7150 50  0001 C CNN
F 1 "GND" H 2100 7250 50  0000 C CNN
F 2 "" H 2100 7400 50  0001 C CNN
F 3 "" H 2100 7400 50  0001 C CNN
	1    2100 7400
	1    0    0    -1  
$EndComp
$Comp
L R R25
U 1 1 5A772F7C
P 2300 7050
F 0 "R25" V 2380 7050 50  0000 C CNN
F 1 "10k" V 2300 7050 50  0000 C CNN
F 2 "" V 2230 7050 50  0001 C CNN
F 3 "" H 2300 7050 50  0001 C CNN
	1    2300 7050
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR010
U 1 1 5A773085
P 2300 7400
F 0 "#PWR010" H 2300 7250 50  0001 C CNN
F 1 "VCC" H 2300 7550 50  0000 C CNN
F 2 "" H 2300 7400 50  0001 C CNN
F 3 "" H 2300 7400 50  0001 C CNN
	1    2300 7400
	-1   0    0    1   
$EndComp
Text Label 2500 6100 0    60   ~ 0
RESET_BTN
Text Label 3750 2650 0    60   ~ 0
RESET_BTN
$Comp
L C C1
U 1 1 5A773AFE
P 800 2350
F 0 "C1" H 825 2450 50  0000 L CNN
F 1 "104" H 825 2250 50  0000 L CNN
F 2 "" H 838 2200 50  0001 C CNN
F 3 "" H 800 2350 50  0001 C CNN
	1    800  2350
	1    0    0    -1  
$EndComp
$Comp
L Crystal_Small Y1
U 1 1 5A77447D
P 4400 1500
F 0 "Y1" H 4400 1600 50  0000 C CNN
F 1 "16Mhz" V 4400 1300 50  0000 C CNN
F 2 "" H 4400 1500 50  0001 C CNN
F 3 "" H 4400 1500 50  0001 C CNN
	1    4400 1500
	-1   0    0    1   
$EndComp
$Comp
L C_Small C2
U 1 1 5A775391
P 4200 1200
F 0 "C2" V 4250 1250 50  0000 L CNN
F 1 "22" V 4250 1050 50  0000 L CNN
F 2 "" H 4200 1200 50  0001 C CNN
F 3 "" H 4200 1200 50  0001 C CNN
	1    4200 1200
	-1   0    0    1   
$EndComp
$Comp
L C_Small C3
U 1 1 5A77548D
P 4600 1200
F 0 "C3" V 4650 1250 50  0000 L CNN
F 1 "22" V 4650 1050 50  0000 L CNN
F 2 "" H 4600 1200 50  0001 C CNN
F 3 "" H 4600 1200 50  0001 C CNN
	1    4600 1200
	-1   0    0    1   
$EndComp
NoConn ~ 3400 2550
Text Label 3750 1600 0    60   ~ 0
MISO
Text Label 3750 1700 0    60   ~ 0
SCK
Text Label 3550 1000 0    60   ~ 0
MOSI
Text Label 3750 2750 0    60   ~ 0
RST
$Comp
L Conn_02x03_Odd_Even J3
U 1 1 5A77971C
P 6200 7150
F 0 "J3" H 6250 7350 50  0000 C CNN
F 1 "Conn_02x03_ISP_Male" H 6250 6900 50  0000 C CNN
F 2 "" H 6200 7150 50  0001 C CNN
F 3 "" H 6200 7150 50  0001 C CNN
	1    6200 7150
	1    0    0    -1  
$EndComp
Text Label 5900 7050 2    60   ~ 0
MISO
Text Label 5900 7150 2    60   ~ 0
SCK
Text Label 5900 7250 2    60   ~ 0
RST
Text Label 6600 7050 0    60   ~ 0
VCC
Text Label 6600 7150 0    60   ~ 0
MOSI
Text Label 6600 7250 0    60   ~ 0
GND
$Comp
L Conn_01x06_Male J4
U 1 1 5A78B077
P 4600 7100
F 0 "J4" H 4600 7400 50  0000 C CNN
F 1 "Conn_01x06_Serial" H 4800 6700 50  0000 C CNN
F 2 "" H 4600 7100 50  0001 C CNN
F 3 "" H 4600 7100 50  0001 C CNN
	1    4600 7100
	1    0    0    -1  
$EndComp
Text Label 4400 800  1    60   ~ 0
GND
Text Label 5000 6900 0    60   ~ 0
GND
NoConn ~ 5000 7000
Text Label 5000 7200 0    60   ~ 0
TX
Text Label 5000 7300 0    60   ~ 0
RX
Text Label 4500 2800 0    60   ~ 0
TX
Text Label 4500 2900 0    60   ~ 0
RX
Text Notes 4700 2900 0    60   Italic 0
For serial communication\nRXD is connected to TX\nTXD is connected to RX
NoConn ~ 3400 3100
NoConn ~ 3400 3200
$Comp
L SW_Push_Dual SW2
U 1 1 5A78D375
P 1200 6550
F 0 "SW2" H 1250 6650 50  0000 L CNN
F 1 "Reset_Btn" H 1200 6280 50  0000 C CNN
F 2 "" H 1200 6750 50  0001 C CNN
F 3 "" H 1200 6750 50  0001 C CNN
	1    1200 6550
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR011
U 1 1 5A791022
P 1200 7400
F 0 "#PWR011" H 1200 7150 50  0001 C CNN
F 1 "GND" H 1200 7250 50  0000 C CNN
F 2 "" H 1200 7400 50  0001 C CNN
F 3 "" H 1200 7400 50  0001 C CNN
	1    1200 7400
	1    0    0    -1  
$EndComp
NoConn ~ 2100 6350
Text Label 1400 6100 0    60   ~ 0
MODE
Text Label 3600 3000 0    60   ~ 0
MODE
NoConn ~ 1400 6750
NoConn ~ 3400 3500
$Comp
L GND #PWR012
U 1 1 5A750C0E
P 1200 3400
F 0 "#PWR012" H 1200 3150 50  0001 C CNN
F 1 "GND" V 1200 3200 50  0000 C CNN
F 2 "" H 1200 3400 50  0001 C CNN
F 3 "" H 1200 3400 50  0001 C CNN
	1    1200 3400
	0    1    1    0   
$EndComp
NoConn ~ 1200 1500
NoConn ~ 1200 1800
NoConn ~ 5000 7100
NoConn ~ 5000 7400
$Comp
L Conn_01x06_Female J6
U 1 1 5A80B70F
P 6350 6350
F 0 "J6" H 6350 6650 50  0000 C CNN
F 1 "Conn_01x06_ISP_Female" H 6200 5950 50  0000 C CNN
F 2 "" H 6350 6350 50  0001 C CNN
F 3 "" H 6350 6350 50  0001 C CNN
	1    6350 6350
	1    0    0    -1  
$EndComp
Text Label 6150 6150 2    60   ~ 0
MISO
Text Label 6150 6250 2    60   ~ 0
VCC
Text Label 6150 6350 2    60   ~ 0
SCK
Text Label 6150 6450 2    60   ~ 0
MOSI
Text Label 6150 6550 2    60   ~ 0
RST
Text Label 6150 6650 2    60   ~ 0
GND
$Comp
L R R20
U 1 1 5A80D0DE
P 3900 3300
F 0 "R20" V 3980 3300 50  0000 C CNN
F 1 "R" V 3900 3300 50  0000 C CNN
F 2 "" V 3830 3300 50  0001 C CNN
F 3 "" H 3900 3300 50  0001 C CNN
	1    3900 3300
	0    1    1    0   
$EndComp
$Comp
L LED_ALT D4
U 1 1 5A80D375
P 4350 3300
F 0 "D4" H 4350 3150 50  0000 C CNN
F 1 "LED_AVR_MODE" H 4000 3150 50  0000 C CNN
F 2 "" H 4350 3300 50  0001 C CNN
F 3 "" H 4350 3300 50  0001 C CNN
	1    4350 3300
	-1   0    0    1   
$EndComp
$Comp
L R R26
U 1 1 5A80D57E
P 3900 3500
F 0 "R26" V 3980 3500 50  0000 C CNN
F 1 "R" V 3900 3500 50  0000 C CNN
F 2 "" V 3830 3500 50  0001 C CNN
F 3 "" H 3900 3500 50  0001 C CNN
	1    3900 3500
	0    1    1    0   
$EndComp
$Comp
L LED_ALT D5
U 1 1 5A80D734
P 4350 3500
F 0 "D5" H 4350 3600 50  0000 C CNN
F 1 "LED_SERIAL_MODE" H 3950 3600 50  0000 C CNN
F 2 "" H 4350 3500 50  0001 C CNN
F 3 "" H 4350 3500 50  0001 C CNN
	1    4350 3500
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR013
U 1 1 5A80E111
P 5200 3300
F 0 "#PWR013" H 5200 3050 50  0001 C CNN
F 1 "GND" H 5200 3150 50  0000 C CNN
F 2 "" H 5200 3300 50  0001 C CNN
F 3 "" H 5200 3300 50  0001 C CNN
	1    5200 3300
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR014
U 1 1 5A80E227
P 5200 3500
F 0 "#PWR014" H 5200 3250 50  0001 C CNN
F 1 "GND" H 5200 3350 50  0000 C CNN
F 2 "" H 5200 3500 50  0001 C CNN
F 3 "" H 5200 3500 50  0001 C CNN
	1    5200 3500
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR015
U 1 1 5A80E983
P 2750 5150
F 0 "#PWR015" H 2750 4900 50  0001 C CNN
F 1 "GND" H 2750 5000 50  0000 C CNN
F 2 "" H 2750 5150 50  0001 C CNN
F 3 "" H 2750 5150 50  0001 C CNN
	1    2750 5150
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR016
U 1 1 5A80EA43
P 2750 4850
F 0 "#PWR016" H 2750 4600 50  0001 C CNN
F 1 "GND" H 2750 4700 50  0000 C CNN
F 2 "" H 2750 4850 50  0001 C CNN
F 3 "" H 2750 4850 50  0001 C CNN
	1    2750 4850
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR017
U 1 1 5A80EB03
P 2750 4550
F 0 "#PWR017" H 2750 4300 50  0001 C CNN
F 1 "GND" H 2750 4400 50  0000 C CNN
F 2 "" H 2750 4550 50  0001 C CNN
F 3 "" H 2750 4550 50  0001 C CNN
	1    2750 4550
	0    -1   -1   0   
$EndComp
$Comp
L LED_ALT D3
U 1 1 5A80EEC5
P 2450 5150
F 0 "D3" H 2450 5250 50  0000 C CNN
F 1 "YELLOW" H 2450 5050 50  0000 C CNN
F 2 "" H 2450 5150 50  0001 C CNN
F 3 "" H 2450 5150 50  0001 C CNN
	1    2450 5150
	-1   0    0    1   
$EndComp
$Comp
L LED_ALT D2
U 1 1 5A80EFC7
P 2450 4850
F 0 "D2" H 2450 4950 50  0000 C CNN
F 1 "RED" H 2450 4750 50  0000 C CNN
F 2 "" H 2450 4850 50  0001 C CNN
F 3 "" H 2450 4850 50  0001 C CNN
	1    2450 4850
	-1   0    0    1   
$EndComp
$Comp
L LED_ALT D1
U 1 1 5A80F09B
P 2450 4550
F 0 "D1" H 2450 4650 50  0000 C CNN
F 1 "GREEN" H 2400 4400 50  0000 C CNN
F 2 "" H 2450 4550 50  0001 C CNN
F 3 "" H 2450 4550 50  0001 C CNN
	1    2450 4550
	-1   0    0    1   
$EndComp
$Comp
L R R19
U 1 1 5A80F5D5
P 2000 5150
F 0 "R19" V 2080 5150 50  0000 C CNN
F 1 "R" V 2000 5150 50  0000 C CNN
F 2 "" V 1930 5150 50  0001 C CNN
F 3 "" H 2000 5150 50  0001 C CNN
	1    2000 5150
	0    -1   -1   0   
$EndComp
$Comp
L R R18
U 1 1 5A80F6A9
P 2000 4850
F 0 "R18" V 2080 4850 50  0000 C CNN
F 1 "R" V 2000 4850 50  0000 C CNN
F 2 "" V 1930 4850 50  0001 C CNN
F 3 "" H 2000 4850 50  0001 C CNN
	1    2000 4850
	0    -1   -1   0   
$EndComp
$Comp
L R R17
U 1 1 5A80F781
P 2000 4550
F 0 "R17" V 2080 4550 50  0000 C CNN
F 1 "R" V 2000 4550 50  0000 C CNN
F 2 "" V 1930 4550 50  0001 C CNN
F 3 "" H 2000 4550 50  0001 C CNN
	1    2000 4550
	0    -1   -1   0   
$EndComp
$Comp
L Conn_01x03_Female J5
U 1 1 5A80FC85
P 850 4850
F 0 "J5" H 850 5050 50  0000 C CNN
F 1 "Conn_01x03_Female" H 750 4650 50  0000 C CNN
F 2 "" H 850 4850 50  0001 C CNN
F 3 "" H 850 4850 50  0001 C CNN
	1    850  4850
	-1   0    0    -1  
$EndComp
Text Notes 3100 4600 0    60   ~ 0
Power LED (Green)
Text Notes 3100 4900 0    60   ~ 0
Programming Error LED (red)
Text Notes 3100 5200 0    60   ~ 0
Programming in progress (Yellow)\n
Wire Wire Line
	1400 6350 1400 6100
Wire Wire Line
	1500 4750 1500 4550
Wire Wire Line
	1050 4750 1500 4750
Wire Wire Line
	1500 4950 1500 5150
Wire Wire Line
	1050 4950 1500 4950
Wire Wire Line
	1500 4550 1850 4550
Wire Wire Line
	1050 4850 1850 4850
Wire Wire Line
	1500 5150 1850 5150
Wire Wire Line
	2150 4550 2300 4550
Wire Wire Line
	2150 4850 2300 4850
Wire Wire Line
	2300 5150 2150 5150
Wire Wire Line
	2600 4550 2750 4550
Wire Wire Line
	2600 4850 2750 4850
Wire Wire Line
	2750 5150 2600 5150
Wire Wire Line
	4500 3500 5200 3500
Wire Wire Line
	4500 3300 5200 3300
Wire Wire Line
	4050 3500 4200 3500
Wire Wire Line
	3650 3500 3750 3500
Wire Wire Line
	3650 3400 3650 3500
Wire Wire Line
	3400 3400 3650 3400
Wire Wire Line
	4050 3300 4200 3300
Wire Wire Line
	3400 3300 3750 3300
Wire Wire Line
	8250 1600 8500 1600
Wire Wire Line
	8250 2200 8250 1600
Wire Wire Line
	8350 1700 8500 1700
Wire Wire Line
	8350 2100 8350 1700
Wire Notes Line
	4650 2600 4650 2950
Wire Notes Line
	5900 2600 4650 2600
Wire Notes Line
	5900 2950 5900 2600
Wire Notes Line
	4650 2950 5900 2950
Wire Wire Line
	4450 1900 3400 1900
Wire Wire Line
	4350 1800 3400 1800
Wire Wire Line
	1500 1500 1200 1500
Wire Wire Line
	1500 3400 1200 3400
Wire Wire Line
	9700 4100 9700 4450
Wire Wire Line
	1200 6350 1200 6100
Wire Wire Line
	3400 3000 3600 3000
Wire Wire Line
	1200 6750 1200 7400
Wire Wire Line
	6000 1400 6400 1400
Connection ~ 6000 2450
Wire Wire Line
	7200 2450 7200 3050
Connection ~ 6000 1400
Wire Wire Line
	6000 2450 6000 1400
Connection ~ 5900 2350
Wire Wire Line
	7300 2350 7300 2750
Wire Wire Line
	5900 1100 5900 2350
Connection ~ 5700 2250
Wire Wire Line
	7400 2250 7400 2650
Wire Wire Line
	5700 2250 5700 1000
Connection ~ 5800 2150
Wire Wire Line
	6800 2150 6800 2950
Wire Wire Line
	5800 2150 5800 1300
Wire Wire Line
	5600 2050 5600 800 
Wire Wire Line
	4450 1700 4450 1900
Wire Wire Line
	4350 1700 4350 1800
Wire Wire Line
	10800 3700 8400 3700
Wire Wire Line
	10800 1100 10800 3700
Wire Wire Line
	10900 3800 9200 3800
Wire Wire Line
	10900 1000 10900 3800
Wire Wire Line
	11000 3900 10000 3900
Wire Wire Line
	11000 900  11000 3900
Wire Wire Line
	11100 4000 10800 4000
Wire Wire Line
	11100 800  11100 4000
Wire Wire Line
	10700 3150 10700 1200
Wire Wire Line
	10600 3050 10600 1300
Wire Wire Line
	10500 2950 10500 1400
Wire Wire Line
	10400 2850 10400 1500
Wire Wire Line
	10300 1600 10100 1600
Wire Wire Line
	10300 2750 10300 1600
Wire Wire Line
	10200 2650 10200 1700
Wire Wire Line
	8250 2200 9500 2200
Wire Wire Line
	9500 2200 9500 2450
Wire Wire Line
	9600 2100 9600 2550
Wire Wire Line
	8350 2100 9600 2100
Wire Wire Line
	7600 2450 7800 2450
Wire Wire Line
	7600 2100 7600 2450
Wire Wire Line
	7900 2100 7600 2100
Wire Wire Line
	7900 1700 7900 2100
Wire Wire Line
	7800 1700 7900 1700
Wire Wire Line
	4500 2900 3400 2900
Wire Wire Line
	3400 2800 4500 2800
Connection ~ 4400 950 
Wire Wire Line
	4400 950  4400 800 
Wire Wire Line
	4200 950  4400 950 
Wire Wire Line
	4400 950  4600 950 
Wire Wire Line
	5000 7400 4800 7400
Wire Wire Line
	5000 7300 4800 7300
Wire Wire Line
	5000 7200 4800 7200
Wire Wire Line
	5000 7100 4800 7100
Wire Wire Line
	5000 7000 4800 7000
Wire Wire Line
	4800 6900 5000 6900
Wire Wire Line
	6600 7250 6500 7250
Wire Wire Line
	6600 7150 6500 7150
Wire Wire Line
	6600 7050 6500 7050
Wire Wire Line
	5900 7250 6000 7250
Wire Wire Line
	5900 7150 6000 7150
Wire Wire Line
	6000 7050 5900 7050
Connection ~ 3600 2650
Wire Wire Line
	3600 2750 3750 2750
Wire Wire Line
	3600 2650 3600 2750
Connection ~ 3550 1500
Wire Wire Line
	3550 1500 3550 1000
Wire Wire Line
	3400 1700 3750 1700
Wire Wire Line
	3400 1600 3750 1600
Wire Wire Line
	1200 1800 1500 1800
Wire Wire Line
	4200 1100 4200 950 
Wire Wire Line
	4600 950  4600 1100
Connection ~ 4600 1500
Wire Wire Line
	4500 1500 4600 1500
Connection ~ 4200 1500
Wire Wire Line
	4200 1500 4300 1500
Wire Wire Line
	4200 1300 4200 1500
Wire Wire Line
	4200 1500 4200 1700
Wire Wire Line
	4600 1300 4600 1500
Wire Wire Line
	4600 1500 4600 1700
Wire Wire Line
	4600 1700 4450 1700
Wire Wire Line
	4200 1700 4350 1700
Connection ~ 1400 3500
Wire Wire Line
	1400 3750 1400 3500
Wire Wire Line
	800  3750 1400 3750
Wire Wire Line
	800  2500 800  3750
Connection ~ 1350 1200
Wire Wire Line
	800  900  800  2200
Wire Wire Line
	1350 900  800  900 
Wire Wire Line
	1350 1200 1350 900 
Wire Wire Line
	3400 2650 3600 2650
Wire Wire Line
	3600 2650 3750 2650
Wire Wire Line
	2300 6100 2500 6100
Wire Wire Line
	2300 6350 2300 6100
Wire Wire Line
	2300 7400 2300 7200
Wire Wire Line
	2100 6750 2100 7400
Wire Wire Line
	2300 6750 2300 6900
Connection ~ 3750 7200
Wire Wire Line
	3750 7400 3750 7200
Connection ~ 3750 7100
Wire Wire Line
	3750 6900 3750 7100
Wire Wire Line
	3600 7200 3750 7200
Wire Wire Line
	3750 7200 4050 7200
Wire Wire Line
	3600 7100 3750 7100
Wire Wire Line
	3750 7100 4050 7100
Wire Wire Line
	3400 2450 6000 2450
Wire Wire Line
	6000 2450 7200 2450
Wire Wire Line
	7200 3050 7800 3050
Wire Wire Line
	7400 2650 7800 2650
Wire Wire Line
	6800 2950 7800 2950
Wire Wire Line
	7300 2750 7800 2750
Wire Wire Line
	3400 2250 5700 2250
Wire Wire Line
	5700 2250 7400 2250
Wire Wire Line
	5700 1000 6400 1000
Wire Wire Line
	6400 1100 5900 1100
Wire Wire Line
	3400 2350 5900 2350
Wire Wire Line
	5900 2350 7300 2350
Wire Wire Line
	5800 1300 6400 1300
Wire Wire Line
	3400 2150 5800 2150
Wire Wire Line
	5800 2150 6800 2150
Wire Wire Line
	5600 800  6400 800 
Wire Wire Line
	3400 2050 5600 2050
Wire Wire Line
	9200 3150 10700 3150
Wire Wire Line
	9200 3050 10600 3050
Wire Wire Line
	9200 2950 10500 2950
Wire Wire Line
	9200 2850 10400 2850
Wire Wire Line
	9200 2750 10300 2750
Wire Wire Line
	9200 2650 10200 2650
Wire Wire Line
	9600 2550 9200 2550
Wire Wire Line
	9500 2450 9200 2450
Wire Wire Line
	9550 1100 10800 1100
Wire Wire Line
	9550 1000 10900 1000
Wire Wire Line
	9550 900  11000 900 
Wire Wire Line
	9550 800  11100 800 
Wire Wire Line
	10200 1700 10100 1700
Wire Wire Line
	10400 1500 10100 1500
Wire Wire Line
	10500 1400 10100 1400
Wire Wire Line
	10600 1300 10100 1300
Wire Wire Line
	10700 1200 10100 1200
Wire Wire Line
	7800 1500 8500 1500
Wire Wire Line
	7800 1400 8500 1400
Wire Wire Line
	7800 1300 8500 1300
Wire Wire Line
	7800 1200 8500 1200
Wire Wire Line
	7800 1100 8500 1100
Wire Wire Line
	7800 1000 8500 1000
Wire Wire Line
	7800 900  8500 900 
Wire Wire Line
	7800 800  8500 800 
Wire Wire Line
	3400 1500 3550 1500
Wire Wire Line
	3550 1500 3750 1500
Wire Wire Line
	3400 1400 3750 1400
Wire Wire Line
	3400 1300 3750 1300
Wire Wire Line
	3400 1200 3750 1200
Wire Wire Line
	1200 3500 1400 3500
Wire Wire Line
	1400 3500 1500 3500
Wire Wire Line
	1200 1200 1350 1200
Wire Wire Line
	1350 1200 1500 1200
Wire Wire Line
	8100 4450 8100 4100
Wire Wire Line
	8900 4450 8900 4100
Wire Wire Line
	10500 4450 10500 4100
Wire Wire Line
	8400 3700 8400 4650
Wire Wire Line
	9200 3800 9200 4650
Wire Wire Line
	10000 3900 10000 4650
Wire Wire Line
	10800 4000 10800 4650
Wire Wire Line
	8100 4750 8100 4850
Wire Wire Line
	8900 4750 8900 4850
Wire Wire Line
	9700 4750 9700 4850
Wire Wire Line
	10500 4750 10500 4850
Wire Wire Line
	8400 5050 8400 5250
Wire Wire Line
	9200 5050 9200 5250
Wire Wire Line
	10000 5050 10000 5250
Wire Wire Line
	10800 5050 10800 5250
Wire Wire Line
	9550 1700 9800 1700
Wire Wire Line
	9550 1600 9800 1600
Wire Wire Line
	9550 1500 9800 1500
Wire Wire Line
	9550 1400 9800 1400
Wire Wire Line
	9550 1300 9800 1300
Wire Wire Line
	9550 1200 9800 1200
Wire Wire Line
	8800 1700 9050 1700
Wire Wire Line
	8800 1600 9050 1600
Wire Wire Line
	8800 1500 9050 1500
Wire Wire Line
	8800 1400 9050 1400
Wire Wire Line
	8800 1300 9050 1300
Wire Wire Line
	8800 1200 9050 1200
Wire Wire Line
	8800 1100 9050 1100
Wire Wire Line
	8800 1000 9050 1000
Wire Wire Line
	8800 900  9050 900 
Wire Wire Line
	8800 800  9050 800 
NoConn ~ 1200 6100
$EndSCHEMATC
