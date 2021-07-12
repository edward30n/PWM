/* Ruler 1         2         3         4         5         6         7        */
/******************************************************************************/
/*                                                                            */
/*                             ____   _ _ _  ____                             */
/*                            |  _ \ | | | ||    \                            */
/*                            | | | || | | || | | |                           */
/*                            | ||_/  \____||_|_|_|                           */
/*                            |_|                      (C)                    */
/*                                                                            */
/*                                                                            */
/*    Written in 2021 by Camilo Ramirez, <camilo_ramirez@javeriana.edu.co>    */
/*                       Edward Duarte, <edwardduarte@javeriana.edu.co>       */
/*                       David Orozco, <davidorozco@javeriana.edu.co>         */
/*                       Nicolas Pedraza <pedraza_n@javeriana.edu.co>         */
/*                                                                            */
/*                                                                            */
/* Letters created with "Big" font using http://www.network-science.de/ascii/ */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*    PWM for any pin (Arduino) in digital pins using cuadratic signals.      */
/*                                                                            */
/*    Copyright (C) 2021 Camilo Ramirez                                       */
/*                       Edward Duarte                                        */
/*                       David Orozco                                         */
/*                       Nicolas Pedraza                                      */
/*                                                                            */
/*    This file is part of PWM.                                               */
/*                                                                            */
/*    PWM is free software: you can redistribute it and/or modify             */
/*    it under the terms of the GNU General Public License as published by    */
/*    the Free Software Foundation, either version 3 of the License, or       */
/*    (at your option) any later version.                                     */
/*                                                                            */
/*    PWM is distributed in the hope that it will be useful,                  */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of          */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           */
/*    GNU General Public License for more details.                            */
/*                                                                            */
/*    You should have received a copy of the GNU General Public License       */
/*    along with DC Solver.  If not, see <http://www.gnu.org/licenses/>.      */
/*                                                                            */
/******************************************************************************/

#ifndef _pwmUno_H
#define _pwmUno_H 
/******************************  MyAnalogWrite ********************************/

/*FN****************************************************************************
*
*   Purpose: Function on a library encharge of doing the correct logic to make
*   the pmw possible
*
*   Plan:
*           Part 1: Ask the 2 parameter required
*           Part 2: Make the FSM with only 1 case
*           Part 3: Calculate the period of the signal according
*                   to the frecuency
*           Part 4: Calculate the unitary basic interval 
*           Part 5: Determine whether or not the pin has to be HIGH
*           Part 6: Deliver results to user
*
*   Register of Revisions:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
/*   Jun 05/21  C.Ramirez                                                     */
/*              E.Duarte                                                      */
/*              D.Orozco                                                      */
/*              N.Pedraza                                                     */
/*              J.Girarldo   Initial implementation                           */
/*                                                                            */
/******************************************************************************/
void MyAnalogWrite(ANALOG_WRITE_T *datos1,long int entrada){
 switch (datos1->casos)
  {
    case 1:
      datos1->periodo = (1000000 / datos1->frecuencia);
      datos1->uBI = (1000000 / (datos1->frecuencia * 255));
      if (datos1->tiempo <= ((datos1->uBI) * (entrada))) {
        digitalWrite(datos1->puerto, HIGH);
        datos1->tiempo = (micros() - datos1->periodo * (micros() / datos1
        ->periodo));
      }
      else {
        digitalWrite(datos1->puerto, LOW);
        datos1->tiempo = (micros() - datos1->periodo * (micros() / datos1->periodo));
      }
      break;
  }
}/*MyAnalogWrite*/
/***************************** MyAnalogWriteSetUp ******************************/

/*FN****************************************************************************
*
*   Purpose: iterate to mantein a pwm signal on a normal port
*
*   Plan:
*           Part 1: Ask the 2 parameter required
*           Part 2: Make the FSM with only 1 case
*           Part 3: Calculate the period of the signal according
*                   to the frecuency
*           Part 4: Calculate the unitary basic interval 
*           Part 5: Determine whether or not the pin has to be HIGH
*           Part 6: Deliver results to user
*
*   Register of Revisions:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
/*   Jun 05/21  C.Ramirez                                                     */
/*              E.Duarte                                                      */
/*              D.Orozco                                                      */
/*              N.Pedraza                                                     */
/*              J.Girarldo   Initial implementation                           */
/*                                                                            */
/******************************************************************************/
void MyAnalogWriteSetUp(ANALOG_WRITE_T *datos1,long int entrada, long int frecuencia, long int puerto){
 switch (datos1->casos)
  {
    case 1:

      datos1->periodo = (1000000 / frecuencia);
      datos1->uBI = (1000000 / (frecuencia * 255));
      // put your main code here, to run repeatedly:
      datos1->tiempo = (micros() - datos1->periodo * (micros() / datos1->periodo));
      if (datos1->tiempo <= ((datos1->uBI) * (entrada))) {
        digitalWrite(puerto, HIGH);
        Serial.println(5);
       
      }
      else {
        digitalWrite(puerto, LOW);
        Serial.println(0);
      }

      break;
  }
}/*MyAnalogWriteSetUp*/
#endif  // _pwnUno_H
