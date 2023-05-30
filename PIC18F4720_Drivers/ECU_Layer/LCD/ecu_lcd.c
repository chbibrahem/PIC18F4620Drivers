/* 
 * File:   ecu_lcd.c
 * Author: chbib
 *
 * Created on May 26, 2023, 6:58 PM
 */

#include "ecu_lcd.h"

static Std_ReturnType lcd_send_4bit_en(const chr_lcd_4bit_t *lcd);
static Std_ReturnType lcd_send_4bit (const chr_lcd_4bit_t * lcd , uint8_t data_command);
static Std_ReturnType lcd_send_8bit_en(const chr_lcd_8bit_t *lcd);
static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd , uint8_t row , uint8_t columns);
static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_t *lcd , uint8_t row , uint8_t column);



Std_ReturnType lcd_4bit_initialize (const chr_lcd_4bit_t * lcd){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd ) {
        ret = E_NOT_OK;
    }
    else {
        ret = gpio_pin_initialize (&(lcd->lcd_rs));
        ret = gpio_pin_initialize (&(lcd->lcd_en));
        for (int counter = 0 ; counter <4 ; counter ++){
             ret = gpio_pin_initialize (&(lcd->lcd_data[counter]));
    }
        __delay_ms(20);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        
        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_4bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON);
        ret = lcd_4bit_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
        ret = lcd_4bit_send_command(lcd, 0x80);
        ret = lcd_4bit_send_string_pos (lcd , 1 ,7 , "WELCOME");
        ret = lcd_4bit_send_string_pos (lcd , 3 ,4 , "IBRAHEM AHMED");
        __delay_ms(2000);
        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
        
    }
    return ret ;
}
Std_ReturnType lcd_4bit_send_command (const chr_lcd_4bit_t * lcd , uint8_t command){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd ) {
        ret = E_NOT_OK;
    }
    else {
        ret = gpio_pin_write_logic (&(lcd->lcd_rs),GPIO_LOW);
        ret = lcd_send_4bit (lcd , command >> 4);
        ret = lcd_send_4bit_en (lcd);
        ret = lcd_send_4bit (lcd , command);
        ret = lcd_send_4bit_en (lcd);
               
    }
    return ret ;
    
}
Std_ReturnType lcd_4bit_send_char_data (const chr_lcd_4bit_t * lcd , uint8_t data){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd ) {
        ret = E_NOT_OK;
    }
    else {
        ret = gpio_pin_write_logic (&(lcd->lcd_rs),GPIO_HIGH);
        ret = lcd_send_4bit (lcd , data >> 4);
        ret = lcd_send_4bit_en (lcd);
        ret = lcd_send_4bit (lcd , data);
        ret = lcd_send_4bit_en (lcd);
               
    }
    return ret ;
    
}
Std_ReturnType lcd_4bit_send_char_data_pos (const chr_lcd_4bit_t * lcd , uint8_t row , uint8_t column, uint8_t data){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    }
    else {
        ret = lcd_4bit_set_cursor (lcd , row , column);
        ret = lcd_4bit_send_char_data (lcd ,data);
    }
    return ret ;
    
}
Std_ReturnType lcd_4bit_send_string (const chr_lcd_4bit_t * lcd , uint8_t *str){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd || NULL == str) {
        ret = E_NOT_OK;
    }
    else {
        for (int string_counter = 0 ; str[string_counter] != '\0' ; string_counter++ ){
                ret = lcd_4bit_send_char_data (lcd , str[string_counter]);
        }

    }
    return ret ;
    
}
Std_ReturnType lcd_4bit_send_string_pos (const chr_lcd_4bit_t * lcd , uint8_t row , uint8_t column, uint8_t *str){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd || NULL == str) {
        ret = E_NOT_OK;
    }
    else {
        ret = lcd_4bit_set_cursor (lcd , row , column);
        for (int string_counter = 0 ; str[string_counter] != '\0' ; string_counter++ ){
                ret = lcd_4bit_send_char_data (lcd , str[string_counter]);
        }
    
    }
    return ret ;
    
}
Std_ReturnType lcd_4bit_send_custom_char (const chr_lcd_4bit_t * lcd , uint8_t row , uint8_t column, 
                                          const uint8_t chr[],uint8_t mem_pos){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd ) {
        ret = E_NOT_OK;
    }
    else {
        ret = lcd_4bit_send_command(lcd, _LCD_CGRAM_START + (8 * mem_pos));
        for (int data_counter = 0 ; data_counter <=7 ; data_counter++){
            ret = lcd_4bit_send_char_data (lcd , chr[data_counter]);
        } 
        ret = lcd_4bit_send_char_data_pos (lcd , row , column , mem_pos);
    }
    return ret ;
    
}


/************************************ ~LCD 8 BIT~ **************************************/

Std_ReturnType lcd_8bit_initialize (const chr_lcd_8bit_t * lcd){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd ) {
        ret = E_NOT_OK;
    }
    else {
        ret = gpio_pin_initialize (&(lcd->lcd_rs));
        ret = gpio_pin_initialize (&(lcd->lcd_en));
        for (uint8_t counter = 0 ; counter <8 ; counter ++){
             ret = gpio_pin_initialize (&(lcd->lcd_data[counter]));
    }
        __delay_ms(20);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        
        ret = lcd_8bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_8bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_8bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bit_send_command(lcd, 0x80);
        ret = lcd_8bit_send_string_pos (lcd , 1 ,7 , "WELCOME");
        ret = lcd_8bit_send_string_pos (lcd , 3 ,4 , "IBRAHEM AHMED");
        __delay_ms(2000);
        ret = lcd_8bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_8bit_send_command(lcd, _LCD_RETURN_HOME);
        
        
    
    }
    return ret ;
}
    

Std_ReturnType lcd_8bit_send_command (const chr_lcd_8bit_t * lcd , uint8_t command){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd ) {
        ret = E_NOT_OK;
    }
    else {
        ret = gpio_pin_write_logic (&(lcd->lcd_rs),GPIO_LOW);
        for (uint8_t pin_counter = 0 ; pin_counter < 8 ; pin_counter++){
            ret = gpio_pin_write_logic (&(lcd->lcd_data[pin_counter]), (command >> pin_counter) & 0x01);
            
        }
        ret = lcd_send_8bit_en (lcd);
    }
    return ret ;
    
}
Std_ReturnType lcd_8bit_send_char_data (const chr_lcd_8bit_t * lcd , uint8_t data){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd ) {
        ret = E_NOT_OK;
    }
    else {
        ret = gpio_pin_write_logic (&(lcd->lcd_rs),GPIO_HIGH);
        for (uint8_t pin_counter = 0 ; pin_counter < 8 ; pin_counter++){
            ret = gpio_pin_write_logic (&(lcd->lcd_data[pin_counter]), (data >> pin_counter) & 0x01);
        }
        ret = lcd_send_8bit_en (lcd);
    }
    return ret ;
    
}
Std_ReturnType lcd_8bit_send_char_data_pos (const chr_lcd_8bit_t * lcd , uint8_t row , uint8_t column, uint8_t data){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    }
    else {
        ret = lcd_8bit_set_cursor (lcd , row , column );
        ret = lcd_8bit_send_char_data (lcd ,data);
    }
    return ret ;
    
}
Std_ReturnType lcd_8bit_send_string (const chr_lcd_8bit_t * lcd , uint8_t *str){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd || NULL == str) {
        ret = E_NOT_OK;
    }
    else {
        for (int string_counter = 0 ; str[string_counter] != '\0' ; string_counter++ ){
                ret = lcd_8bit_send_char_data (lcd , str[string_counter]);
        }
    }
    return ret ;
    
}
Std_ReturnType lcd_8bit_send_string_pos (const chr_lcd_8bit_t * lcd , uint8_t row , uint8_t column, uint8_t *str){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd || NULL == str ) {
        ret = E_NOT_OK;
    }
    else {
        ret = lcd_8bit_set_cursor (lcd , row , column);
        for (int string_counter = 0 ; str[string_counter] != '\0' ; string_counter++ ){
                ret = lcd_8bit_send_char_data (lcd , str[string_counter]);
        }
    }
    return ret ;
    
}
Std_ReturnType lcd_8bit_send_custom_char (const chr_lcd_8bit_t * lcd , uint8_t row , uint8_t column, 
                                          const uint8_t chr[],uint8_t mem_pos){
    
    Std_ReturnType ret = E_OK;
    if (NULL == lcd ) {
        ret = E_NOT_OK;
    }
    else {
        ret = lcd_8bit_send_command(lcd, _LCD_CGRAM_START + (8 * mem_pos));
        for (int data_counter = 0 ; data_counter <=7 ; data_counter++){
            ret = lcd_8bit_send_char_data (lcd , chr[data_counter]);
        } 
        ret = lcd_8bit_send_char_data_pos (lcd , row , column , mem_pos);
    }
    return ret ;
}

// Helper functions ;

void convert_byte_into_string (uint8_t value , uint8_t *str){
    Std_ReturnType ret = E_OK;
    if (NULL == str ) {
        ret = E_NOT_OK;
    }
    else {
        memset (str , '/0',4);
        sprintf (str , "%i",value);
    }
 
    
}
void convert_short_into_string (uint16_t value , uint8_t *str){
    Std_ReturnType ret = E_OK;
    if (NULL == str ) {
        ret = E_NOT_OK;
    }
    else {
        memset (str , '/0',6);
        sprintf (str , "%i",value);
    }

    
}
void convert_int_into_string (uint32_t value , uint8_t *str){
    Std_ReturnType ret = E_OK;
    if (NULL == str ) {
        ret = E_NOT_OK;
    }
    else {
        memset (str , '/0',11);
        sprintf (str , "%i",value);
    }

    
}

static Std_ReturnType lcd_send_4bit (const chr_lcd_4bit_t * lcd , uint8_t data_command) {
    Std_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic (&(lcd->lcd_data[0]), (data_command >>0) & 0x01);
    ret = gpio_pin_write_logic (&(lcd->lcd_data[1]), (data_command >>1) & 0x01);
    ret = gpio_pin_write_logic (&(lcd->lcd_data[2]), (data_command >>2) & 0x01);
    ret = gpio_pin_write_logic (&(lcd->lcd_data[3]), (data_command >>3) & 0x01);
    return ret ; 
}

static Std_ReturnType lcd_send_8bit_en(const chr_lcd_8bit_t *lcd){
    Std_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_LOW);
    return ret;
}

static Std_ReturnType lcd_send_4bit_en(const chr_lcd_4bit_t *lcd){
    Std_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_LOW);
    return ret;
}


static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_t *lcd , uint8_t row , uint8_t column){
    Std_ReturnType ret = E_OK;
    column --;
    switch (row){
        case ROW1: ret = lcd_8bit_send_command(lcd, (0x80+ column)); break;
        case ROW2: ret = lcd_8bit_send_command(lcd, (0xC0+ column)); break;
        case ROW3: ret = lcd_8bit_send_command(lcd, (0x94+ column)); break;
        case ROW4: ret = lcd_8bit_send_command(lcd, (0xd4+ column)); break;
        default : break ;
    }
    return ret;
}

static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd , uint8_t row , uint8_t columns){
    Std_ReturnType ret = E_OK;
    columns --;
    switch (row){
        case ROW1: ret = lcd_4bit_send_command(lcd, (0x80+ columns)); break;
        case ROW2: ret = lcd_4bit_send_command(lcd, (0xC0+ columns)); break;
        case ROW3: ret = lcd_4bit_send_command(lcd, (0x94+ columns)); break;
        case ROW4: ret = lcd_4bit_send_command(lcd, (0xd4+ columns)); break;
        default : ;
    }
    return ret;
}