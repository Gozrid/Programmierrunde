// Display Library example for SPI e-paper panels from Dalian Good Display and boards from Waveshare.
// Requires HW SPI and Adafruit_GFX. Caution: the e-paper panels require 3.3V supply AND data lines!
//
// Display Library based on Demo Example from Good Display: https://www.good-display.com/companyfile/32/
//
// Author: Jean-Marc Zingg
//
// Version: see library.properties
//
// Library: https://github.com/ZinggJM/GxEPD2

// Supporting Arduino Forum Topics (closed, read only):
// Good Display ePaper for Arduino: https://forum.arduino.cc/t/good-display-epaper-for-arduino/419657
// Waveshare e-paper displays with SPI: https://forum.arduino.cc/t/waveshare-e-paper-displays-with-spi/467865
//
// Add new topics in https://forum.arduino.cc/c/using-arduino/displays/23 for new questions and issues

#define GxEPD2_290_IS_BW true
#define GxEPD2_290_T5_IS_BW true
#define GxEPD2_290_T5D_IS_BW true
#define GxEPD2_290_I6FD_IS_BW true
#define GxEPD2_290_T94_IS_BW true
#define GxEPD2_290_T94_V2_IS_BW true
#define GxEPD2_290_BS_IS_BW true
#define GxEPD2_290_M06_IS_BW true
#define GxEPD2_290_GDEY029T94_IS_BW true
// 3-color e-papers
#define GxEPD2_290c_IS_3C true
#define GxEPD2_290_Z13c_IS_3C true
#define GxEPD2_290_C90c_IS_3C true


#if defined(GxEPD2_DISPLAY_CLASS) && defined(GxEPD2_DRIVER_CLASS)
#define IS_GxEPD2_DRIVER(c, x) (c##x)
#define IS_GxEPD2_DRIVER_BW(x) IS_GxEPD2_DRIVER(x, _IS_BW)
#define IS_GxEPD2_DRIVER_3C(x) IS_GxEPD2_DRIVER(x, _IS_3C)
#define IS_GxEPD2_DRIVER_4C(x) IS_GxEPD2_DRIVER(x, _IS_4C)
#define IS_GxEPD2_DRIVER_7C(x) IS_GxEPD2_DRIVER(x, _IS_7C)
#if IS_GxEPD2_BW(GxEPD2_DISPLAY_CLASS) && IS_GxEPD2_DRIVER_3C(GxEPD2_DRIVER_CLASS)
#error "GxEPD2_BW used with 3-color driver class"
#endif
#if IS_GxEPD2_3C(GxEPD2_DISPLAY_CLASS) && IS_GxEPD2_DRIVER_BW(GxEPD2_DRIVER_CLASS)
#error "GxEPD2_3C used with b/w driver class"
#endif
#if IS_GxEPD2_4C(GxEPD2_DISPLAY_CLASS) && IS_GxEPD2_DRIVER_BW(GxEPD2_DRIVER_CLASS)
#error "GxEPD2_4C used with b/w driver class"
#endif
#if IS_GxEPD2_4C(GxEPD2_DISPLAY_CLASS) && IS_GxEPD2_DRIVER_3C(GxEPD2_DRIVER_CLASS)
#error "GxEPD2_4C used with 3-color driver class"
#endif
#if IS_GxEPD2_7C(GxEPD2_DISPLAY_CLASS) && !IS_GxEPD2_DRIVER_7C(GxEPD2_DRIVER_CLASS)
#error "GxEPD2_7C used with less colors driver class"
#endif
#if !IS_GxEPD2_DRIVER_BW(GxEPD2_DRIVER_CLASS) && !IS_GxEPD2_DRIVER_3C(GxEPD2_DRIVER_CLASS) && !IS_GxEPD2_DRIVER_4C(GxEPD2_DRIVER_CLASS) && !IS_GxEPD2_DRIVER_7C(GxEPD2_DRIVER_CLASS)
#error "neither BW nor 3C nor 4C nor 7C kind defined for driver class (error in GxEPD2_selection_check.h)"
#endif

#endif
