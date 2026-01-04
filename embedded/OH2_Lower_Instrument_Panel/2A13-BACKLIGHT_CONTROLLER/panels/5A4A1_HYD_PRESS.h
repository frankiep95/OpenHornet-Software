/**********************************************************************************************************************
 *        ____                   _    _                       _
 *       / __ \                 | |  | |                     | |
 *      | |  | |_ __   ___ _ __ | |__| | ___  _ __ _ __   ___| |_
 *      | |  | | '_ \ / _ \ '_ \|  __  |/ _ \| '__| '_ \ / _ \ __|
 *      | |__| | |_) |  __/ | | | |  | | (_) | |  | | | |  __/ |_
 *       \____/| .__/ \___|_| |_|_|  |_|\___/|_|  |_| |_|\___|\__|
 *             | |
 *             |_|
 *   ----------------------------------------------------------------------------------
 *  
 * @file      5A4A1_HYD_PRESS.h
 * @author    Ulukaii
 * @date      20.05.2025
 * @version   u 0.3.1
 * @copyright Copyright 2016-2025 OpenHornet. See 2A13-BACKLIGHT_CONTROLLER.ino for details.
 * @brief     Implements backlighting for the Hydraulic Pressure panel.
 *********************************************************************************************************************/


#ifndef __HYD_PRESS_H
#define __HYD_PRESS_H

#include "DcsBios.h"
#include "../helpers/Panel.h"


/********************************************************************************************************************
 * @brief   This table defines the panel's LEDs.
 * @details "Role" in this context refers to the LED role enum in the Panel.h file (enum used for memory efficiency).
 * @remark  This table is stored in PROGMEM for memory efficiency.
 ********************************************************************************************************************/
const int HYD_PRESS_LED_COUNT = 42;  // Total number of LEDs in the panel
const Led hydPressLedTable[HYD_PRESS_LED_COUNT] PROGMEM = {
    {0, LED_5MM_RGB}, {1, LED_5MM_RGB}, {2, LED_5MM_RGB}, {3, LED_5MM_RGB}, {4, LED_5MM_RGB}, 
    {5, LED_5MM_RGB}, {6, LED_5MM_RGB}, {7, LED_5MM_RGB}, {8, LED_5MM_RGB}, {9, LED_5MM_RGB},
    {10, LED_5MM_RGB}, {11, LED_5MM_RGB}, {12, LED_5MM_RGB}, {13, LED_5MM_RGB}, {14, LED_5MM_RGB}, 
    {15, LED_5MM_RGB}, {16, LED_5MM_RGB}, {17, LED_5MM_RGB}, {18, LED_5MM_RGB}, {19, LED_5MM_RGB},
    {20, LED_5MM_RGB}, {21, LED_5MM_RGB}, {22, LED_5MM_RGB}, {23, LED_5MM_RGB}, {24, LED_5MM_RGB}, 
    {25, LED_5MM_RGB}, {26, LED_5MM_RGB}, {27, LED_5MM_RGB}, {28, LED_5MM_RGB}, {29, LED_5MM_RGB},
    {30, LED_5MM_RGB}, {31, LED_5MM_RGB}, {32, LED_5MM_RGB}, {33, LED_5MM_RGB}, {34, LED_5MM_RGB}, 
    {35, LED_5MM_RGB}, {36, LED_5MM_RGB}, {37, LED_5MM_RGB}, {38, LED_5MM_RGB}, {39, LED_5MM_RGB},
    {40, LED_5MM_RGB}, {41, LED_5MM_RGB}
};

/********************************************************************************************************************
 * @brief   This table defines the optional legend text for specific backlight LEDs.
 * @details Only LEDs that need text are included in this table.
 * @remark  This table is stored in PROGMEM for memory efficiency.
 ********************************************************************************************************************/
const int HYD_PRESS_TEXT_COUNT = 0;  // Number of LEDs that need text
const LedText hydPressTextTable[HYD_PRESS_TEXT_COUNT] PROGMEM = {
    // No text needed for this panel
};

/********************************************************************************************************************
 * @brief   Hydraulic Pressure Panel / Gauge class
 * @details Backlighting controller for the Hydraulic Pressure gauge.
 *          Total LEDs: 42
 *          Backlight LEDs: 42 (all LEDs are backlights)
 *          Indicator LEDs: 0 (no indicators in this panel)
 * @remark  This class inherits from the "basic" Panel class in panels/Panel.h
 *          It also enforces a singleton pattern; this is required to use DCS-BIOS callbacks in class methods.
 ********************************************************************************************************************/
class HydPressGauge : public Panel {
public:
    /**
     * @brief Gets the singleton instance of the HydPressGauge class
     * @param startIndex The starting index for this panel's LEDs on the strip
     * @param ledStrip Pointer to the LED strip array
     * @return Pointer to the singleton instance
     * @see This method is called by the main .ino file's addPanel() method to create the panel instance
     */
    static HydPressGauge* getInstance(int startIndex = 0, CRGB* ledStrip = nullptr) {
        if (!instance) {
            instance = new HydPressGauge(startIndex, ledStrip);
        }
        return instance;
    }

private:
    /**
     * @brief Private constructor to enforce singleton pattern
     * @param startIndex The starting index for this panel's LEDs on the strip
     * @param ledStrip Pointer to the LED strip array
     * @see This method is called by the public getInstance() if and only if no instance exists yet
     */
    HydPressGauge(int startIndex, CRGB* ledStrip) {
        panelStartIndex = startIndex;
        this->ledStrip = ledStrip;
        ledCount = HYD_PRESS_LED_COUNT;
        ledTable = hydPressLedTable;
    }

    // Static callback functions for DCS-BIOS
    // NIL


    // Instance data
    static HydPressGauge* instance;
};

// Initialize static instance pointer
HydPressGauge* HydPressGauge::instance = nullptr;

#endif 