/* 
 * File:   application.c
 * Author: chbrahem
 *
 * Created on May 21, 2023, 10:02 PM
 */


#include "application.h" 

Std_ReturnType ret = E_NOT_OK;

int main() {
    uint8_t counter_text[4];
    uint8_t counter = 0 ; 
    application_initialize();
    
    uint8_t  customChar1[] = {0x0E,0x0A,0x1B,0x11,0x11,0x11,0x1F,0x00};
    uint8_t  customChar2[] = {0x0E,0x0A,0x1B,0x11,0x11,0x1F,0x1F,0x00};
    uint8_t  customChar3[] = {0x0E,0x0A,0x1B,0x11,0x1F,0x1F,0x1F,0x00};
    uint8_t  customChar4[] = {0x0E,0x0A,0x1B,0x1F,0x1F,0x1F,0x1F,0x00};
    uint8_t  customChar5[] = {0x0E,0x0A,0x1F,0x1F,0x1F,0x1F,0x1F,0x00};
    uint8_t  customChar6[] = {0x0E,0x0E,0x1F,0x1F,0x1F,0x1F,0x1F,0x00};
    
    /*
    
    loading_func();
    ret = lcd_8bit_send_string_pos (&lcd8bit , 1 ,1 , "counter: ");
    for (counter = 0 ; counter <255 ; counter ++){
    convert_byte_into_string(counter , counter_text );
    ret = lcd_8bit_send_string_pos (&lcd8bit , 1 ,10 , counter_text);
    __delay_ms (100);
    */

    while (1){
       ret = lcd_8bit_send_custom_char (&lcd8bit , 1 , 1 ,customChar1 , 0);
       __delay_ms(50);
       ret = lcd_8bit_send_custom_char (&lcd8bit , 1 , 1 ,customChar2 , 0);
              __delay_ms(50);
       ret = lcd_8bit_send_custom_char (&lcd8bit , 1 , 1 ,customChar3 , 0);
              __delay_ms(50);
       ret = lcd_8bit_send_custom_char (&lcd8bit , 1 , 1 ,customChar4 , 0);
              __delay_ms(50);
       ret = lcd_8bit_send_custom_char (&lcd8bit , 1 , 1 ,customChar5 , 0);
              __delay_ms(50);
       ret = lcd_8bit_send_custom_char (&lcd8bit , 1 , 1 ,customChar6 , 0);
              __delay_ms(50);
    }
        
    

    return (EXIT_SUCCESS);
}
    
void application_initialize (void){
    ecu_layer_intialize();
  }

void  welcome_func (void) {
    ret = lcd_8bit_send_string_pos (&lcd8bit , 1 ,7 , "WELCOME");
    ret = lcd_8bit_send_string_pos (&lcd8bit , 3 ,4 , "IBRAHEM AHMED");
    ret = lcd_8bit_send_command(&lcd8bit, _LCD_DISPLAY_SHIFT_LEFT);
    __delay_ms(100);
    ret = lcd_8bit_send_command(&lcd8bit, _LCD_DISPLAY_SHIFT_RIGHT);


}
void  loading_func (void) {
    ret = lcd_8bit_send_string_pos (&lcd8bit , 1 ,1 , "Loading");
    for (int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 7 ; j++){
      ret = lcd_8bit_send_string_pos (&lcd8bit , 1 ,8+j , ".");
      __delay_ms(50);
        }
        ret = lcd_8bit_send_string_pos (&lcd8bit , 1 ,8 , "       ");
    }
        ret = lcd_8bit_send_command(&lcd8bit, _LCD_CLEAR);
        ret = lcd_8bit_send_command(&lcd8bit, _LCD_RETURN_HOME);
    
}
