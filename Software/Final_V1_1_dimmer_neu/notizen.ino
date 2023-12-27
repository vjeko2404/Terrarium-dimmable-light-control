/*

\40  !
\41  "
\42  #
\43  $
\44  %
\45  &
\50  (
\51  )
\52  *
\53  Plus-Zeichen
\54  Komma
\55  Minus-Zeichen
\56  Punkt
\57  Schrägstrich
\72  Doppelpunkt
\73  Semikolon
\74  <
\75  Gleichheitszeichen
\76  >
\77  ?
\100  @
\134  eckige Klammer links
\136  eckige Klammer rechts
\137  accent circonflexe
\138  Unterstrich
\140  accent grave
\173  geschweifte Klammer links
\174  senkrechter Strich
\175  geschweifte Klammer rechts
\176  Pfeil nach rechts
\177  Pfeil nach links
\260  Minuszeichen
\333  Kastenrahmen
\337  hochgestellter Kastenrahmen(wie Potenz)
\340  gr. alpha
\341  ä
\342  ß
\343  klein epsilon
\344  µ
\350  Wurzelzeichen
\351  hoch minus 1
\353  hoch x
\356  n mit Oberstrich ( spanisch )
\357  ö
\363  Zeichen unendlich
\364  Ohm
\365  ü
\366  gr.Summe
\367  pi ( klein )
\371  u mit strich rechts unten
\375  geteilt durch
\377  alle Leuchtpunkte eingeschaltet

*/

/*  FUNKTIONEN BEISPIEL!!!!!!

// *********************************************************************
void mFunc_goToRootMenu(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    // remmove compiler warnings when the param variable is not used:
    LCDML_UNUSED(param);

    // go to root and display menu
    LCDML.MENU_goRoot();
  }
}


// *********************************************************************
void mFunc_jumpTo_timer_info(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    // remmove compiler warnings when the param variable is not used:
    LCDML_UNUSED(param);

    // Jump to main screen
    LCDML.OTHER_jumpToFunc(mFunc_timer_info);
  }
}



  // *********************************************************************
uint8_t g_func_timer_info = 0;  // time counter (global variable)
unsigned long g_timer_1 = 0;    // timer variable (global variable)
void mFunc_timer_info(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    // remmove compiler warnings when the param variable is not used:
    LCDML_UNUSED(param);

    lcd.print(F("20 sec wait"));      // print some content on first row
    g_func_timer_info = 20;           // reset and set timer
    LCDML.FUNC_setLoopInterval(100);  // starts a trigger event for the loop function every 100 milliseconds

    LCDML.TIMER_msReset(g_timer_1);
  }


  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
    // the quit button works in every DISP function without any checks; it starts the loop_end function

    // reset screensaver timer
    LCDML.SCREEN_resetTimer();

    // this function is called every 100 milliseconds

    // this method checks every 1000 milliseconds if it is called
    if (LCDML.TIMER_ms(g_timer_1, 1000)) {
      g_func_timer_info--;  // increment the value every second
      lcd.setCursor(0, 0);  // set cursor pos
      lcd.print(F("  "));
      lcd.setCursor(0, 0);           // set cursor pos
      lcd.print(g_func_timer_info);  // print the time counter value
    }

    // this function can only be ended when quit button is pressed or the time is over
    // check if the function ends normally
    if (g_func_timer_info <= 0) {
      // leave this function
      LCDML.FUNC_goBackToMenu();
    }
  }

  if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    // you can here reset some global vars or do nothing
  }
}




/* ===================================================================== *
 *                                                                       *
 * Menu Callback Function                                                *
 *                                                                       *
 * ===================================================================== *
 *
 * EXAMPLE CODE:

// *********************************************************************
// Void Beispiel
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // remmove compiler warnings when the param variable is not used:
    //LCDML_UNUSED(param);
    // setup
    // is called only if it is started

    // starts a trigger event for the loop function every 100 milliseconds
    LCDML.FUNC_setLoopInterval(100);

    // uncomment this line when the menu should go back to the last called position
    // this could be a cursor position or the an active menu function
    // GBA means => go back advanced
    //LCDML.FUNC_setGBA() 

    //
  }

  if(LCDML.FUNC_loop())           // ****** LOOP *********
  {
    // loop
    // is called when it is triggered
    // - with LCDML_DISP_triggerMenu( milliseconds )
    // - with every button or event status change

    // uncomment this line when the screensaver should not be called when this function is running
    // reset screensaver timer
    //LCDML.SCREEN_resetTimer();

    // check if any button is pressed (enter, up, down, left, right)
    if(LCDML.BT_checkAny()) {
      LCDML.FUNC_goBackToMenu();
    }
  }

  if(LCDML.FUNC_close())      // ****** STABLE END *********
  {
    // loop end
    // you can here reset some global vars or delete it
    // this function is always called when the functions ends.
    // this means when you are calling a jumpTo ore a goRoot function
    // that this part is called before a function is closed
  }
}


 * ===================================================================== *
 */

