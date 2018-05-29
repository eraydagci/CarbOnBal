// This software, known as CarbOnBal is
// Copyright, 2017 L.L.M. (Dennis) Meulensteen. dennis@meulensteen.nl
//
// This file is part of CarbOnBal. A combination of software and hardware.
// I hope it may be of some help to you in balancing your carburetors and throttle bodies.
// Always be careful when working on a vehicle or electronic project like this.
// Your life and health are your sole responsibility, use wisely.
//
// CarbOnBal hardware is covered by the Cern Open Hardware License v1.2
// a copy of the text is incuded with the source code.
//
// CarbOnBal is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// CarbOnBal is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CarbOnBal.  If not, see <http://www.gnu.org/licenses/>.


#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED
#include <Arduino.h>

#define SOFTWARE_VERSION "1.5.1"

#define SELECT 2
#define LEFT 3
#define RIGHT 4
#define CANCEL 5

#define P0VSENSOR 150                                             //minimum pressure reported by MAP sensor at 0V in millibar/hPa (=10x KPa value)
#define P5VSENSOR 1020												//maximum pressure reported by sensor at 5V in millibar
#define NUM_BUTTONS 4
#define NUM_SENSORS 4
#define DISPLAY_COLS 20
#define DISPLAY_ROWS 4
#define LANGUAGE "lang_en_gb.h"			//select a different language file to change translations
//#define LANGUAGE "lang_nl_nl.h"
static const uint8_t numReadings=20;
static const int maxValue=1024;
static const uint8_t brightnessPin=6;
static const uint8_t contrastPin=11;
static const int numberOfCalibrationValues=256;
static const int calibrationOffset=256; //eeprom base address for calibration


static const uint8_t versionUID = 23; //update when settings_t changes!
static const uint8_t settingsOffset = sizeof(versionUID);

//this struct is used to store settings in NVRAM
//does not use bit fields because these cause more writes to the same NVRAM locations
struct settings_t
{
    bool usePeakAverage;
    bool silent;
    bool advanced;
    bool splashScreen;
    uint8_t cylinders;
    uint8_t master;
    uint8_t button1;
    uint8_t button2;
    uint8_t contrast;
    uint8_t brightness;
    uint8_t graphType;
    int baudRate;
    uint8_t damping;
    int delayTime;
    int threshold;
    uint8_t rpmDamping;
    uint8_t responsiveness;
    uint8_t units;
    uint8_t zoom;
    uint8_t calibrationMax;
    bool arduinoCompatible;
    uint8_t averagingMethod;
    uint8_t emaShift;
    uint8_t emaFactor;
    uint8_t emaCorrection;
    uint8_t emaRpmSensitivity;
};

extern int readingCount[NUM_SENSORS];
extern unsigned int average[NUM_SENSORS];
extern int total[NUM_SENSORS];

//int timeBase=0;

extern int reading[NUM_SENSORS];
extern int peak[NUM_SENSORS];
extern unsigned int rpm;
//unsigned long smoothed16=0;


extern settings_t settings;
extern float alpha;
extern float alphaRpm;
extern float stabilityThreshold;
extern int ambientPressure;

#endif
