#ifndef NEC_V20_CPU_H
#define NEC_V20_CPU_H

#include <stdint.h>

// Define el tamaño total de la memoria para el emulador del NEC V20 en bytes.
#define MEM_SIZE (1024 * 640) // 640KB

/**
 * Enumeración para las banderas del procesador NEC V20. Cada bandera tiene un
 * valor correspondiente a su bit en el registro de banderas del procesador.
 */
typedef enum flag_t {
  /**
   * Bandera de acarreo: se establece si una operación aritmética genera un
   * acarreo fuera del bit más significativo.
   */
  FLAG_CARRY = 0x0001,

  /**
   * Bandera de paridad: se establece si el número de bits establecidos en el
   * resultado es par.
   * */
  FLAG_PARITY = 0x0004,
  /**
   * Bandera de acarreo auxiliar: se establece si una operación aritmética
   * genera un acarreo fuera del nibble menos significativo.
   * */
  FLAG_AUX_CARRY = 0x0010,
  /**
   * Bandera de cero: se establece si el resultado de una operación es cero.
   */
  FLAG_ZERO = 0x0040,
  /**
   * Bandera de signo: se establece si el resultado de una operación es negativo
   * (bit más significativo establecido).
   * */
  FLAG_SIGN = 0x0080,
  /**
   * Bandera de trampa: utilizada para la depuración paso a paso.
   * */
  FLAG_TRAP = 0x0100,
  /**
   * Bandera de interrupción: habilita o deshabilita la
   * respuesta a las interrupciones de hardware.
   * */
  FLAG_INTERRUPT = 0x0200,
  /**
   * Bandera de dirección: controla la dirección de procesamiento de cadenas de
   * datos.
   * */
  FLAG_DIRECTION = 0x0400,
  /**
   * Bandera de desbordamiento: se establece si una operación aritmética resulta
   * en un desbordamiento.
   * */
  FLAG_OVERFLOW = 0x0800
} Flag;

// Estructura para representar los bytes alto y bajo de un registro de 16 bits.
typedef struct bytes_t {
  uint8_t low;
  uint8_t high;
} Bytes;

/**
 * Unión que permite el acceso a un registro de 16 bits como un valor completo o
 * como bytes individuales alto y bajo. Siendo `word` el valor completo del
 * registro y `bytes` la estructura que representa los bytes alto y bajo del
 * registro.
 **/
typedef union register_t {
  uint16_t word;
  Bytes bytes;
} Register;

/**
 * Estructura que define el banco de registros generales del CPU.
 *
 * - AX: Registro acumulador.
 *   - AL: Registro de 8 bits bajo.
 *   - AH: Registro de 8 bits alto.
 *   - AX: Registro de 16 bits.
 * - BX: Registro base.
 *   - BL: Registro de 8 bits bajo.
 *   - BH: Registro de 8 bits alto.
 *   - BX: Registro de 16 bits.
 * - CX: Registro contador.
 *   - CL: Registro de 8 bits bajo.
 *   - CH: Registro de 8 bits alto.
 *   - CX: Registro de 16 bits.
 * - DX: Registro de datos.
 *   - DL: Registro de 8 bits bajo.
 *   - DH: Registro de 8 bits alto.
 *   - DX: Registro de 16 bits.
 **/
typedef struct register_bank_t {
  Register ax;
  Register bx;
  Register cx;
  Register dx;
} RegisterBank;

// Estructura que representa el estado completo del CPU NEC V20.
typedef struct cpu_t {
  uint8_t memory[MEM_SIZE]; // Memoria del CPU representada como un arreglo de
                            // bytes.
  RegisterBank registers;   // Banco de registros del CPU.
  Register sp;              // Puntero de pila (Stack Pointer).
  Register bp;              // Puntero base (Base Pointer).
  Register si;              // Índice fuente (Source Index).
  Register di;              // Índice destino (Destination Index).
  Register ip;              // Puntero de instrucción (Instruction Pointer).
  Register flags;           // Registro de banderas del CPU.
  uint16_t cs;              // Segmento de código (Code Segment).
  uint16_t ds;              // Segmento de datos (Data Segment).
  uint16_t ss;              // Segmento de pila (Stack Segment).
  uint16_t es;              // Segmento extra (Extra Segment).
} CPU;

#endif // NEC_V20_CPU_H
