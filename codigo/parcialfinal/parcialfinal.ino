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

/* ---------------------- Inclusion of Own Structures ----------------------- */
typedef struct {
/*
 * Tiempo:     Variable encargada de medir el intervalo del periodo de la señal.
 * Frecuencia: Variable encargada de almacenar la frecuencia del pwm
 * uBI:        Variable encaragda de almacenar la unidad basica del intervalo
 *             Para determianr la variable se ddivide en 255 partes, siendo el
 *             valor minimo posible
 * periodo:    Periodo de la señal pwm
 * casos:      Variable para el unico caso que tiene la FSM
 * puerto:     Variable que almacena el puerto que se desea convertir a PWM
 */
  long int tiempo = 0, frecuencia = 490, uBI = 0, periodo = 0;
  int casos = 1, puerto = 12;
}  ANALOG_WRITE_T; // Declaración del tipo de estructura
/* ------------------------ Inclusion of Own Variables ---------------------- */
// Declaración de datos como tipo de estructura "ANALOG_WRITE_T"
ANALOG_WRITE_T datos; 
// Valor maximo del led, equivalente a 6 bits -> 1/4 1024
long int entrada = 50;
/* ------------------------ Inclusion of Own Headers ------------------------ */
#include "pwmUno.h"
/************************** Prototypes of Functions ***************************/

/* ---------------------------- Public Functions ---------------------------- */

/******************************* Void Setup ***********************************/

/*FN****************************************************************************
*
*   Purpose: initialize the diferent ports you want to transform into
*   "Analog ports" or port with pwm on an arduino 
*   Plan:
*           Part 1: Initialize the ports
*
*   Register of Revisions:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
/*   Jun 05/21  C.Ramirez                                                     */
/*              E.Duarte                                                      */
/*              D.Orozco                                                      */
/*              N.Pedraza                                                     */
/*              J.Girarldo   Initial implementation of comments               */
/*                                                                            */
/******************************************************************************/
void setup() {
  // put your setup code here, to run once:
  pinMode(datos.puerto, OUTPUT);
  Serial.begin(9600);
}/*void setUp*/

/********************************* Void loop **********************************/

/*FN****************************************************************************
*
*   Purpose: iterate to mantein a pwm signal on a normal port
*
*   Plan:
*           Part 1: Call any of the two functions commented belowed
*           Part 2: Select the parameters for your personal use
*           Part 3: Deliver results to user
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
void loop() {
  // Esta función recibe como parametros la estructura de la información 
  // y el nivel al que se quiere poner el pin (0-255)
  //MyAnalogWrite(&datos,entrada);
  // Esta función recibe como parametros la estructura de la información 
  // , el nivel al que se quiere poner el pin (0-255), la frecuencia a la 
  // que se quiere manejar el pun y finalmente el número del puerto del arduino  
  MyAnalogWriteSetUp(&datos,127,2000,12);
}/*void loop*/
