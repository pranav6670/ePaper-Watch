#include <Arduino.h>

#define face_width 200
#define face_height 200
uint8_t face_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xE8, 0xBE, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xE8, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x6F, 0xBC, 0xFA, 0xFF, 0xFF, 
  0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0xFF, 0x17, 0x04, 0x3E, 0x60, 0xD8, 
  0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x7F, 0x87, 0x4C, 0x38, 0x60, 
  0xC0, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x27, 0x03, 0x16, 0xBC, 
  0x38, 0xD2, 0xE0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0x0A, 0x22, 0x0C, 
  0x38, 0x30, 0x40, 0x80, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0xBF, 0x01, 0x06, 
  0x18, 0x3D, 0x68, 0xE0, 0xA2, 0xF5, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0x87, 0x81, 
  0x06, 0x0C, 0x9C, 0x31, 0x48, 0x90, 0xE5, 0xFF, 0x3F, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x00, 
  0x03, 0x06, 0x48, 0x38, 0x10, 0x60, 0x81, 0x41, 0xFF, 0x7F, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 
  0x80, 0x02, 0x06, 0x0C, 0x5C, 0x32, 0xE8, 0xC0, 0x00, 0xFF, 0xFF, 0x01, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 
  0x8F, 0x01, 0x03, 0x84, 0x18, 0x38, 0x30, 0x20, 0xC8, 0x0A, 0xF3, 0xFF, 
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 
  0xFF, 0x83, 0x01, 0x42, 0x04, 0x09, 0x3A, 0x58, 0xA0, 0x40, 0xA0, 0xD1, 
  0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xF8, 0xFF, 0x84, 0x01, 0x06, 0x0C, 0x48, 0x78, 0x10, 0x30, 0x60, 0x80, 
  0x09, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xFE, 0xFF, 0x00, 0x01, 0x04, 0x08, 0x0C, 0x3C, 0x14, 0x31, 0x70, 
  0x80, 0x45, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xFF, 0xEF, 0x41, 0x87, 0x2E, 0x1C, 0x38, 0x38, 0x30, 0x10, 
  0x68, 0xC4, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xC0, 0xFF, 0xE7, 0x01, 0x02, 0x0C, 0x18, 0x00, 0x5C, 0x08, 
  0x38, 0x20, 0xE0, 0x82, 0xD7, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xC0, 0xFF, 0xC3, 0x4B, 0x06, 0x08, 0x00, 0x00, 0x39, 
  0x00, 0x00, 0x30, 0x60, 0xD0, 0xA7, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0xD0, 0x03, 0x16, 0x08, 0x00, 0x00, 
  0x38, 0x01, 0x00, 0x38, 0x71, 0xC0, 0x83, 0xFF, 0x0F, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x07, 0x0C, 0x00, 0x00, 
  0x00, 0x3C, 0x00, 0x10, 0x00, 0x20, 0xE4, 0x15, 0xFE, 0x1F, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x5F, 0x80, 0x27, 0x08, 0x00, 
  0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0xB0, 0xF0, 0x02, 0xFE, 0x3F, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xD7, 0x01, 0x0F, 0x28, 
  0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x02, 0x18, 0xF1, 0x80, 0xF3, 0x7F, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xA3, 0x81, 0x1E, 
  0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x20, 0x10, 0x78, 0x92, 0xE9, 
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x05, 0x07, 
  0x1E, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x02, 0x78, 0xC0, 
  0x81, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x01, 
  0x02, 0x9C, 0x02, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x40, 0x7C, 
  0xC4, 0x20, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x7F, 
  0x00, 0x0E, 0x38, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 
  0x3C, 0x62, 0x41, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 
  0xFF, 0x00, 0x0E, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 
  0x10, 0x1C, 0xBA, 0x10, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xF8, 0xAF, 0x81, 0x18, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x40, 0x1F, 0x10, 0x82, 0xF9, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xFC, 0x0F, 0x03, 0x18, 0xE2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x40, 0x0F, 0x1C, 0xC0, 0xF2, 0x3F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xFE, 0x23, 0x06, 0x60, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x17, 0x2C, 0x70, 0xC4, 0x7F, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xFF, 0x03, 0x04, 0x20, 0xE0, 0x01, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x43, 0x04, 0x74, 0xC4, 0xFF, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x80, 0xFF, 0x05, 0x1C, 0x00, 0xC0, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x27, 0x48, 0x98, 0xA0, 0xFF, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x00, 0x38, 0x00, 0x80, 0x07, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE1, 0x01, 0x00, 0x18, 0x80, 0xFF, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x83, 0x60, 0x00, 0x80, 0x07, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x05, 0x00, 0x0E, 0xC2, 
  0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x7F, 0x02, 0x60, 0x00, 0x00, 
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x02, 0x82, 0x06, 
  0x60, 0xFD, 0x07, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x2E, 0xC0, 0x00, 
  0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 
  0x41, 0x70, 0xFA, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x0F, 0x1C, 0x02, 
  0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x04, 
  0x80, 0x08, 0x1D, 0xF8, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x57, 0x30, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
  0x00, 0x00, 0x40, 0x2C, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x07, 
  0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x14, 0x00, 0x20, 0x1E, 0xE8, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xFC, 
  0x07, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0xE2, 0x3F, 0x00, 0x00, 0x00, 0x00, 
  0xFE, 0x0F, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x08, 0xC1, 0x81, 0xF0, 0x7F, 0x00, 0x00, 0x00, 
  0x00, 0xFF, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x08, 0xB4, 0xFF, 0x00, 0x00, 
  0x00, 0x00, 0xFF, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x48, 0x2E, 0xFF, 0x01, 
  0x00, 0x00, 0x80, 0x7F, 0xC0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0xFE, 
  0x01, 0x00, 0x00, 0x80, 0x7F, 0xA1, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x81, 0x0B, 
  0xFE, 0x01, 0x00, 0x00, 0xC0, 0x3F, 0x80, 0x43, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xE0, 
  0x40, 0xFD, 0x03, 0x00, 0x00, 0xE0, 0x3F, 0x04, 0x0E, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x70, 0x02, 0xFC, 0x07, 0x00, 0x00, 0xE0, 0x7F, 0x00, 0x18, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
  0x08, 0x38, 0x50, 0xFE, 0x07, 0x00, 0x00, 0xF0, 0xFF, 0x90, 0x04, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x20, 0x04, 0xA8, 0xFF, 0x0F, 0x00, 0x00, 0xF0, 0xFF, 0x07, 0x02, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x80, 0x82, 0xFF, 0x0F, 0x00, 0x00, 0xF8, 0xDF, 0x0F, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x04, 0xF8, 0xF3, 0x1F, 0x00, 0x00, 0xF8, 0x83, 
  0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0xF8, 0xDB, 0x1F, 0x00, 0x00, 0xFC, 
  0xA7, 0x7D, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x7F, 0xE8, 0x3F, 0x00, 0x00, 
  0xFC, 0x03, 0xFA, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xA0, 0x7F, 0x82, 0x3F, 0x00, 
  0x00, 0xFC, 0x01, 0xF4, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE9, 0x2F, 0x82, 0x7F, 
  0x00, 0x00, 0xFE, 0x11, 0xC0, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0xF0, 0x03, 0xA0, 
  0x7F, 0x00, 0x00, 0xFF, 0x01, 0xC4, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFC, 0x56, 
  0xA0, 0xFF, 0x00, 0x00, 0xFF, 0x8F, 0x00, 0xFE, 0x01, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x7F, 
  0x00, 0xF1, 0xFF, 0x00, 0x00, 0x7F, 0x3A, 0x10, 0xF4, 0x03, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 
  0x9F, 0x10, 0xBC, 0xFF, 0x00, 0x00, 0xFF, 0xE8, 0x02, 0xE8, 0x03, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0x27, 0x80, 0x87, 0xFE, 0x01, 0x80, 0x3F, 0x80, 0x07, 0xC0, 0x03, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xE2, 0x01, 0xC0, 0x07, 0xFC, 0x01, 0xC0, 0x7F, 0x49, 0x0E, 0x80, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x44, 0xF9, 0x20, 0xFE, 0x01, 0xC0, 0x3F, 0x10, 0x1C, 
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x80, 0x06, 0x98, 0x10, 0xFE, 0x03, 0xC0, 0x3F, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xFC, 0x03, 0xC0, 0x5F, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x20, 0x8A, 0xF9, 0x03, 0xE0, 
  0x3F, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0xFE, 0x07, 
  0xE0, 0xFF, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x80, 0xFF, 
  0x07, 0xE0, 0x8F, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x40, 0xFC, 
  0xF1, 0x07, 0xF0, 0x0F, 0xFA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x01, 0x00, 
  0xBE, 0xF8, 0x07, 0xF0, 0x2F, 0xA8, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x01, 0x00, 
  0xC0, 0x07, 0xF0, 0x0F, 0xF0, 0x47, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x10, 0x42, 0x10, 0xE0, 0x0F, 0xF0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
  0x00, 0x00, 0x00, 0x05, 0xE9, 0x0F, 0xF0, 0x07, 0x10, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x10, 0x01, 0x00, 0x48, 0xE0, 0x0F, 0xF8, 0x27, 0x00, 0x02, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x02, 0x00, 0x00, 0x20, 0x00, 0xE2, 0x1F, 0xF8, 0x47, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0xE8, 0x1F, 0xF8, 0xFF, 0x11, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0xA0, 0xFF, 0x1F, 0xF8, 0xAB, 
  0x4F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x84, 0xFB, 0xC9, 0x1F, 0xFC, 
  0x03, 0x7A, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x11, 0x20, 0x00, 0x5E, 0xE1, 0x1F, 
  0xFC, 0x4B, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x40, 0x82, 0x88, 
  0x3F, 0xFC, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xBA, 0xEA, 0xED, 0x00, 0x00, 0x08, 
  0xC1, 0x3F, 0xFC, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 
  0x00, 0xE4, 0x3F, 0xFC, 0x03, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0x42, 
  0x02, 0x21, 0x80, 0x3F, 0xFC, 0x41, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x21, 0x51, 0xEA, 
  0x00, 0x00, 0x00, 0xC2, 0x3F, 0xFC, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 
  0xF0, 0x01, 0x41, 0x44, 0x84, 0x3F, 0xFE, 0xFF, 0x05, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 
  0x00, 0xE0, 0x01, 0x01, 0x60, 0xFF, 0x7F, 0xFC, 0xA5, 0x3F, 0x10, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 
  0x00, 0x00, 0xE0, 0x14, 0x80, 0xFC, 0xD5, 0x3F, 0xFC, 0x25, 0x2A, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1C, 0x00, 0x00, 0xE0, 0x04, 0x20, 0xA9, 0x88, 0x7F, 0xFE, 0x00, 0x00, 
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0xF0, 0x01, 0x00, 0x88, 0xA0, 0x3F, 0xFE, 0x81, 
  0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 
  0x00, 0x00, 0x38, 0x00, 0x00, 0xE0, 0x00, 0x04, 0x02, 0x48, 0x7F, 0xFE, 
  0x05, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 
  0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0xE0, 0x41, 0x40, 0x20, 0x81, 0x7F, 
  0xFE, 0x04, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
  0xFF, 0x01, 0x00, 0x00, 0x3C, 0x00, 0x00, 0xE0, 0x49, 0x40, 0x94, 0x80, 
  0x7F, 0xFC, 0x21, 0x02, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0xFF, 0x03, 0x00, 0x00, 0x1C, 0x00, 0x00, 0xE0, 0x00, 0x04, 0x01, 
  0x25, 0x7F, 0xFE, 0xA9, 0x96, 0x9A, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xC0, 0xFF, 0x03, 0x00, 0x00, 0x3C, 0x00, 0x00, 0xF0, 0x00, 0x75, 
  0x56, 0xB6, 0x7F, 0xFE, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xC0, 0xFF, 0x03, 0x00, 0x00, 0x38, 0x00, 0x00, 0xE0, 0xA2, 
  0xFF, 0xFF, 0xFF, 0x7F, 0xFE, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xC0, 0xFF, 0x03, 0x00, 0x00, 0x1C, 0x00, 0x00, 0xE0, 
  0xC1, 0xFF, 0xFF, 0xFF, 0x7F, 0xFE, 0xB7, 0xAA, 0x95, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x07, 0x00, 0x00, 0x3C, 0x00, 0x00, 
  0xF0, 0x84, 0x69, 0x79, 0xF9, 0x7F, 0xFE, 0x80, 0x05, 0x98, 0x04, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x03, 0x00, 0x00, 0x38, 0x00, 
  0x00, 0xE0, 0x01, 0x5A, 0x04, 0x84, 0x7F, 0xFE, 0x0D, 0x50, 0x01, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0x3C, 
  0x00, 0x00, 0xE0, 0x20, 0x00, 0xA2, 0x92, 0x7F, 0xFE, 0x85, 0x12, 0x08, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 
  0x3D, 0x00, 0x00, 0xF0, 0x11, 0x88, 0x8A, 0x64, 0x7F, 0xFC, 0x20, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 
  0x00, 0x38, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x7F, 0xFC, 0x01, 
  0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 
  0x00, 0x00, 0x1C, 0x00, 0x00, 0xF0, 0x02, 0x22, 0x02, 0x85, 0x7F, 0xFE, 
  0x05, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0xE0, 0x80, 0x00, 0xA8, 0x60, 0x3F, 
  0xFC, 0xD4, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0x3D, 0x00, 0x00, 0xE0, 0x82, 0x00, 0xFC, 0xA5, 
  0x3F, 0xFE, 0xBF, 0x06, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0xE0, 0x01, 0x28, 0x98, 
  0xFF, 0x7F, 0xFC, 0xAB, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0xF0, 0x00, 0x00, 
  0x00, 0xE8, 0x3F, 0xFC, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x20, 0x80, 0xF8, 0x05, 
  0x04, 0x8A, 0x81, 0x3F, 0xFC, 0x01, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 
  0x04, 0x40, 0x44, 0xC8, 0x3F, 0xFC, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 
  0xFF, 0x40, 0x00, 0x20, 0xA0, 0x3F, 0xFC, 0x03, 0x10, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFA, 0xBF, 
  0x77, 0x77, 0x02, 0x20, 0x40, 0x80, 0x3F, 0xFC, 0x05, 0x82, 0x01, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xA0, 0x44, 0x44, 0x80, 0x04, 0x02, 0xC4, 0x3F, 0xF8, 0x03, 0x7A, 0x00, 
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
  0x00, 0x00, 0x28, 0x48, 0x00, 0x00, 0x5F, 0xE1, 0x3F, 0xF8, 0xD7, 0x1F, 
  0x12, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x81, 0xF8, 0xDA, 0x1F, 0xF8, 0xFF, 
  0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x08, 0x20, 0x80, 0x80, 0x02, 0x00, 0x41, 0xFF, 0x1F, 0xF8, 
  0x17, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x10, 0x88, 0xE4, 0x1F, 
  0xF8, 0xA7, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0xE2, 
  0x1F, 0xF0, 0x07, 0x42, 0x08, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x14, 
  0xE8, 0x0F, 0xF0, 0x47, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x10, 0x80, 0x84, 
  0x08, 0xE0, 0x0F, 0xF0, 0x0F, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x09, 
  0x00, 0x41, 0xF0, 0x0F, 0xF0, 0x07, 0xA1, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x28, 0x00, 0x00, 
  0x00, 0xD0, 0x11, 0xF9, 0x0F, 0xE0, 0x2F, 0xFC, 0x20, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 
  0x40, 0x20, 0x00, 0x4F, 0xF0, 0x07, 0xE0, 0x1F, 0x5F, 0x04, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 
  0x00, 0x00, 0x00, 0x89, 0x78, 0xF4, 0x07, 0xE0, 0xFF, 0x03, 0x02, 0x82, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 
  0x00, 0x00, 0x01, 0x04, 0x00, 0xE1, 0xFF, 0x07, 0xE0, 0xBF, 0x02, 0x12, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x04, 0x08, 0x48, 0x48, 0xFF, 0x07, 0xC0, 0x3F, 0x12, 
  0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x20, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0xF8, 0x03, 0xC0, 0x9F, 
  0x80, 0x40, 0x00, 0x20, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x10, 0x00, 0x40, 0x04, 0x18, 0x40, 0x40, 0x41, 0x60, 0xFC, 0x03, 0xC0, 
  0x3F, 0x00, 0x08, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x10, 0x04, 0xFE, 0x03, 
  0x80, 0x3F, 0x08, 0x0F, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x40, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x02, 0x10, 0x7A, 0x09, 0xFC, 
  0x01, 0x80, 0xBF, 0x92, 0x07, 0x90, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x04, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x43, 0xE0, 0x81, 
  0xFE, 0x01, 0x80, 0x7F, 0xE0, 0x4A, 0xE4, 0x07, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0xE8, 0x0B, 0x40, 
  0x17, 0xFF, 0x01, 0x00, 0xFF, 0x7C, 0x00, 0xF0, 0x03, 0x02, 0x00, 0x00, 
  0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x08, 0x00, 0x00, 0xA0, 0xC0, 0x5F, 
  0x11, 0x5E, 0xFE, 0x00, 0x00, 0xFF, 0x4F, 0x11, 0xFD, 0x00, 0x00, 0x00, 
  0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x80, 0x00, 0x00, 0x20, 
  0x3F, 0x00, 0xFA, 0xFF, 0x00, 0x00, 0xFF, 0x13, 0x08, 0x3F, 0x01, 0x00, 
  0x02, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 
  0x80, 0xFC, 0x99, 0xA0, 0x7F, 0x00, 0x00, 0xFE, 0x01, 0xC0, 0x6F, 0x04, 
  0x20, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x28, 
  0x00, 0x06, 0xFA, 0x03, 0x82, 0x7F, 0x00, 0x00, 0xFE, 0x45, 0xF0, 0x17, 
  0x10, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 
  0x00, 0x04, 0x00, 0xE0, 0x2F, 0x88, 0x7F, 0x00, 0x00, 0xFC, 0x0B, 0xF9, 
  0x01, 0x02, 0x08, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x40, 0x00, 0xD0, 0x9F, 0xE0, 0x3F, 0x00, 0x00, 0xFC, 0x23, 
  0xFE, 0x15, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
  0x08, 0x00, 0x00, 0x00, 0x80, 0x08, 0x7E, 0xC9, 0x3F, 0x00, 0x00, 0xF8, 
  0xA7, 0x3F, 0x82, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x20, 0x00, 0x40, 0x10, 0x01, 0x08, 0x81, 0xFC, 0xE0, 0x1F, 0x00, 0x00, 
  0xF8, 0xD7, 0xCF, 0x00, 0x00, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 0x00, 
  0x02, 0x00, 0x40, 0x00, 0x00, 0x00, 0x10, 0x10, 0xF2, 0xFF, 0x1F, 0x00, 
  0x00, 0xF0, 0xFF, 0x13, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x10, 0x00, 0x00, 0xA0, 0x00, 0x10, 0x00, 0xE0, 0xFF, 0x0F, 
  0x00, 0x00, 0xF0, 0xFF, 0x06, 0x92, 0x00, 0x00, 0x00, 0x01, 0x00, 0xC0, 
  0xE3, 0xF3, 0xC7, 0x3F, 0x04, 0x82, 0x00, 0x04, 0x00, 0xA1, 0x82, 0xFF, 
  0x0F, 0x00, 0x00, 0xE0, 0x7F, 0x88, 0x08, 0x04, 0x08, 0x80, 0x00, 0x04, 
  0x40, 0x0C, 0x22, 0x0C, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x38, 0x4A, 
  0xFE, 0x07, 0x00, 0x00, 0xE0, 0x7F, 0x21, 0x1E, 0x40, 0x00, 0x00, 0x00, 
  0x00, 0x60, 0x08, 0x22, 0x18, 0x04, 0x00, 0x00, 0x00, 0x80, 0x81, 0x30, 
  0x20, 0xFD, 0x07, 0x00, 0x00, 0xC0, 0x7F, 0x02, 0x13, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x40, 0x04, 0x31, 0x50, 0x24, 0x01, 0x08, 0x40, 0x00, 0x01, 
  0xF2, 0x09, 0xFC, 0x03, 0x00, 0x00, 0xC0, 0x7F, 0xA0, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x10, 0xE0, 0xC7, 0x13, 0x10, 0x04, 0x40, 0x80, 0x00, 0x48, 
  0x40, 0x80, 0x91, 0xFE, 0x01, 0x00, 0x00, 0x80, 0x7F, 0xE1, 0x00, 0x00, 
  0x80, 0x00, 0x08, 0x00, 0x40, 0x01, 0x11, 0x10, 0x06, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x08, 0x87, 0xFF, 0x01, 0x00, 0x00, 0x00, 0xFF, 0x74, 0x42, 
  0x42, 0x04, 0x08, 0x00, 0x00, 0x48, 0x00, 0x22, 0x18, 0x04, 0x00, 0x00, 
  0x04, 0x00, 0x20, 0x10, 0x1E, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x9D, 
  0x09, 0x02, 0x00, 0x20, 0x04, 0x00, 0x40, 0x00, 0x13, 0x08, 0x04, 0x00, 
  0x08, 0x00, 0x00, 0x40, 0x85, 0x9A, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFE, 
  0x17, 0x80, 0x03, 0x88, 0x01, 0x00, 0x02, 0x60, 0x60, 0xA1, 0x0E, 0x04, 
  0x00, 0x00, 0x21, 0x01, 0xE1, 0x01, 0xF8, 0x7F, 0x00, 0x00, 0x00, 0x00, 
  0xFC, 0x17, 0xC4, 0x21, 0x00, 0x00, 0x80, 0x40, 0x40, 0xA1, 0xE1, 0x21, 
  0x24, 0x18, 0x00, 0x02, 0x01, 0x80, 0x03, 0xC1, 0x3F, 0x00, 0x00, 0x00, 
  0x00, 0xFC, 0x8F, 0xD0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x20, 0x00, 0x10, 0x08, 0x46, 0xF0, 0x3F, 0x00, 0x00, 
  0x00, 0x00, 0xF8, 0x0F, 0xB0, 0x21, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1E, 0xF8, 0x1F, 0x00, 
  0x00, 0x00, 0x00, 0xF0, 0x1F, 0x19, 0x00, 0x01, 0x10, 0x0A, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x90, 0x00, 0x12, 0x58, 0xF6, 0x0F, 
  0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x1C, 0x80, 0x10, 0x50, 0x0E, 0x08, 
  0x10, 0x00, 0x10, 0x10, 0x00, 0x40, 0x68, 0x01, 0x90, 0x03, 0x38, 0xF8, 
  0x0F, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xBF, 0x27, 0xE4, 0x02, 0x00, 0x17, 
  0x80, 0x00, 0x84, 0x00, 0x00, 0x21, 0x08, 0xF0, 0x04, 0x04, 0x46, 0xE0, 
  0xFE, 0x07, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x25, 0x70, 0x40, 0x80, 
  0x0F, 0x20, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0xC0, 0x45, 0x21, 0x96, 
  0xC1, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x03, 0x5A, 0x00, 
  0xA0, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xE1, 0x01, 0x00, 
  0x0C, 0xA8, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x38, 
  0x44, 0xC8, 0x27, 0x00, 0x08, 0x00, 0x80, 0x00, 0x00, 0x00, 0xD8, 0x23, 
  0x40, 0x38, 0x40, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x85, 
  0x0C, 0x21, 0xE1, 0x01, 0x00, 0x20, 0x08, 0x05, 0x89, 0x88, 0x00, 0x80, 
  0x07, 0x16, 0xA5, 0xD2, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 
  0x07, 0x1E, 0x30, 0xE8, 0x24, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x08, 
  0xA4, 0x07, 0x06, 0x74, 0xE0, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xFC, 0x9F, 0x83, 0x98, 0xF0, 0x01, 0x08, 0x00, 0x80, 0x20, 0x00, 0x00, 
  0x40, 0x00, 0x9F, 0x5C, 0x40, 0xF5, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xF8, 0xDF, 0x01, 0x3C, 0xF1, 0x09, 0x00, 0x00, 0x04, 0x04, 0x40, 
  0x40, 0x40, 0x01, 0x4E, 0x18, 0x90, 0xF9, 0x1F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xF0, 0xBF, 0x0A, 0x05, 0x78, 0x00, 0x40, 0x40, 0x00, 0x3C, 
  0x04, 0x01, 0x00, 0x90, 0x1E, 0xB1, 0x84, 0xFF, 0x0F, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xE0, 0xFF, 0x02, 0x0E, 0x39, 0x88, 0x01, 0x00, 0x11, 
  0x18, 0x02, 0x00, 0x00, 0x20, 0x1C, 0x64, 0x11, 0xFE, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0x40, 0x23, 0xBC, 0x01, 0x00, 0x00, 
  0x00, 0xBE, 0x00, 0x40, 0x08, 0x04, 0x7D, 0x60, 0x40, 0xFF, 0x07, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x65, 0xA1, 0x3D, 0x00, 0x40, 
  0x04, 0x01, 0x1C, 0x04, 0x00, 0x40, 0x90, 0x78, 0xD1, 0xA0, 0xFF, 0x01, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x07, 0x05, 0x8E, 0x14, 
  0x20, 0x40, 0x80, 0x7C, 0x10, 0x08, 0x04, 0x02, 0x72, 0x84, 0xDB, 0xFF, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xCF, 0x05, 0x9F, 
  0x18, 0x00, 0x00, 0x00, 0x9D, 0x20, 0x08, 0x00, 0x10, 0xFC, 0xA0, 0xF3, 
  0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x90, 
  0x07, 0x8D, 0x12, 0x04, 0x20, 0x38, 0x01, 0x20, 0x41, 0x7C, 0xE0, 0x05, 
  0xF7, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F, 
  0x88, 0x07, 0x24, 0x08, 0x21, 0x04, 0x98, 0x04, 0x00, 0x10, 0x30, 0xE2, 
  0x15, 0xFE, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 
  0xFF, 0x93, 0x97, 0x0E, 0x2C, 0x00, 0x40, 0x3C, 0x00, 0x21, 0x98, 0x62, 
  0xE4, 0x81, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0xFF, 0xD1, 0x47, 0x66, 0x4E, 0x41, 0x00, 0xBD, 0x84, 0x00, 0x14, 
  0x78, 0xA8, 0xD3, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xC0, 0xFF, 0xCF, 0x01, 0x02, 0x04, 0x18, 0x44, 0x1C, 0x00, 0x78, 
  0x30, 0x40, 0xC2, 0xE7, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0xAB, 0x27, 0xA6, 0x0C, 0x18, 0x78, 0x10, 
  0x3A, 0x68, 0xD0, 0x08, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x00, 0x03, 0x0C, 0x18, 0x59, 0x3C, 
  0x59, 0x10, 0x60, 0x88, 0x91, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0x80, 0x85, 0x06, 0x0D, 0x1C, 
  0x79, 0x12, 0xB4, 0x61, 0x91, 0x89, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0x97, 0x12, 0x1B, 0xA4, 
  0x1C, 0x3C, 0x38, 0x20, 0x44, 0x80, 0xA3, 0xFF, 0x0F, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xCF, 0x04, 0x02, 
  0x0E, 0x8A, 0x1C, 0x70, 0x21, 0xD2, 0x00, 0xF1, 0xFF, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x01, 
  0x83, 0x44, 0x18, 0xB9, 0x32, 0x68, 0xC0, 0x59, 0xFF, 0xFF, 0x01, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 
  0xA1, 0x47, 0x26, 0x0D, 0x3D, 0x10, 0x60, 0x80, 0xA0, 0xFF, 0x7F, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 
  0xFF, 0x87, 0x01, 0x06, 0x18, 0xD8, 0x74, 0x64, 0xA2, 0xC3, 0xFF, 0x3F, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xF0, 0xFF, 0xBF, 0x21, 0x82, 0xAC, 0x3C, 0x21, 0x4A, 0x82, 0xFD, 0xFF, 
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xC0, 0xFF, 0xFF, 0x85, 0x17, 0x0C, 0xBA, 0x74, 0xE0, 0xA4, 0xFF, 
  0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x27, 0x42, 0x04, 0x3C, 0x29, 0xC4, 0xF9, 
  0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x7F, 0x07, 0x2E, 0x3A, 0x70, 0xD0, 
  0xFE, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0xFF, 0x6F, 0x9C, 0x7D, 0x60, 
  0xDA, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xB7, 0xBC, 
  0xF6, 0xFF, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xF0, 0xFF, 0xFF, 0xFF, 0x17, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xD2, 0x7F, 0x1B, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };
