/*********************************************************************
*                SEGGER MICROCONTROLLER SYSTEME GmbH                 *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2015  SEGGER Microcontroller Systeme GmbH        *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

***** emWin - Graphical user interface for embedded applications *****
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : BASIC_HelloWorld.c
Purpose     : Simple demo drawing "Hello world"
----------------------------------------------------------------------
*/

#include "GUI.h"

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
void MainTask(void)
{
  GUI_Clear();
  GUI_SetFont(&GUI_Font32_1);
  /* Displays the string at the current text position in the current window using the current font.*/
  GUI_DispString("Hello World\r\n");
  GUI_DispString("Getting Started with STemWin Library\r\n");
  /*Change Background Color*/
  GUI_SetBkColor(GUI_BLUE);
  /* Displays the string at the specified position in the current window using the current font.*/
  GUI_DispStringAt("Writing at Specific Position with Blue Background", 0, 64);
  GUI_DispStringAt("Clearing the complete line", 0, 96);
  /*Clears the current line in the current window from the current text position
  to the end of the window using the height of the current font.*/
  GUI_DispCEOL();
  /*Combining the above two functions*/
  GUI_DispStringAtCEOL("Displaying Text and Cleaning Line in a single statement", 0, 128);

  GUI_SetBkColor(GUI_RED);
  /*Display Text Horizontally Centered*/
  GUI_DispStringHCenterAt("Horizontal Centered Text", LCD_GetXSize()/2, 160);
  /*Displaying Text Within Rectangle with Rotation*/
  GUI_SetFont(&GUI_Font8_1);
  GUI_RECT Rect = {10, 192, 40, 256 };
  char acText[] = "Rotated\ntext";
  GUI_SetTextMode(GUI_TM_XOR);
  GUI_FillRectEx(&Rect);
  /*GUI_ROTATE_0, GUI_ROTATE_180, GUI_ROTATE_CCW, GUI_ROTATE_CW*/
  GUI_DispStringInRectEx(acText, &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER, strlen(acText), GUI_ROTATE_CW );

  /*Text Mode: GUI_TEXTMODE_NORMAL, _REV, _TRANS, _XOR*/
  GUI_SetFont(&GUI_Font32_1);
  GUI_GotoXY(0, 288);
  GUI_SetTextMode(GUI_TEXTMODE_REV);
  GUI_DispString("Reverse Text");
  GUI_SetTextMode(GUI_TEXTMODE_TRANS);
  GUI_DispString("Transparent Text");
  GUI_SetTextMode(GUI_TEXTMODE_XOR);
  GUI_DispString("Xor Text\r\n");
  /*Text Style: GUI_TS_NORMAL, UNDERLINE, STRIKETHRU, OVERLINE*/
  GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
  GUI_SetTextStyle(GUI_TS_UNDERLINE);
  GUI_DispString("Underline Text");
  GUI_SetTextStyle(GUI_TS_STRIKETHRU);
  GUI_DispString("Strike Text");
  GUI_SetTextStyle(GUI_TS_OVERLINE);
  GUI_DispString("Overline Text\r\n");

  /*Displaying Values*/
  GUI_SetFont(&GUI_Font32_1);
  GUI_SetBkColor(GUI_BLACK);
  GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
  GUI_SetTextStyle(GUI_TS_NORMAL);
  GUI_DispDec(1234, 4);
  GUI_DispDecAt( 9876, 100, 352, 4);
  // GUI_Delay(1000);

  /*2D Graphics Library Examples*/
  /*Basic Drawing Routines*/
  GUI_Clear();
  GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
  /*Horizontal Color Gradient*/
  GUI_DrawGradientH(0, 0, 99, 99, 0x0000FF, 0x00FFFF);
  /*Vertical Color Gradient*/
  GUI_DrawGradientV(100, 0, 199, 99, 0x0000FF, 0x00FFFF);
  /*Horizontal Color Gradient with Radius*/
  GUI_DrawGradientRoundedH(200, 0, 299, 99, 25, 0x0000FF, 0x00FFFF);
  /*Vertical Color Gradient with Radius*/
  GUI_DrawGradientRoundedV(300, 0, 399, 99, 25, 0x0000FF, 0x00FFFF);

  /*Draw Pixel*/
  GUI_DrawPixel(400, 0);
  /*Draw Point*/
  /*Increase Pen Size*/
  GUI_SetPenSize(10);
  GUI_DrawPoint(400, 80);
  /*Reset Pen Size*/
  GUI_SetPenSize(1);
  /*Draw Rectangle*/
  GUI_DrawRect(0, 100, 100, 200 );
  /*Draw Rounded Frame*/
  GUI_DrawRoundedFrame(100, 100, 200, 200, 25, 5);
  while(1);
}

/*************************** End of file ****************************/
