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
  while(1);
}

/*************************** End of file ****************************/
