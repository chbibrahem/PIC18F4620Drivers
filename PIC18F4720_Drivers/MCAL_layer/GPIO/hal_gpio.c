/* 
 * File:   hal_gpio.c
 * Author: chbrahem
 *
 * Created on May 21, 2023, 10:02 PM
 */
#include "hal_gpio.h"


/* Reference to the Data Direction Control Registers*/
volatile uint8_t *tris_register[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};

/* Reference to the Data Direction Control Registers*/
volatile uint8_t *lat_register[]={&LATA,&LATB,&LATC,&LATD,&LATE};

/* Reference to the Data Direction Control Registers*/
volatile uint8_t *port_register[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};

/**
 * @brief Initializing the direction if a specific pin @ref direction_t 
 * @param _pin_config pointer to the configuration @ref pin_config_t
 * @return status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : The function has issue to perform this action 
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t * _pin_config){
    Std_ReturnType ret = E_OK;
    
    if (NULL == _pin_config || _pin_config-> pin > PORT_PIN_MAX_NUMBER-1) {
        ret = E_NOT_OK;
    }
    else {
        switch (_pin_config->direction){
            case GPIO_DIRECTION_OUTPUT:
                CLEAR_BIT(*tris_register[_pin_config->port] , _pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT :
                SET_BIT(*tris_register[_pin_config->port] , _pin_config->pin);
                break;
            default : ret = E_NOT_OK; 
        }     
    }
    return ret;
}
#endif

/**
 * 
 * @param _pin_config pointer to the configuration @ref pin_config_t
 * @param direction_status
 * @return status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : The function has issue to perform this action  
 */

#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t * _pin_config , direction_t * direction_status){
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || NULL == direction_status || _pin_config-> pin > PORT_PIN_MAX_NUMBER-1) {
        ret = E_NOT_OK;
    }
    else {
        *direction_status = READ_BIT (*tris_register[_pin_config->port] , _pin_config->pin);
        
    }
    return ret;
}
#endif

/**
 * 
 * @param _pin_config pointer to the configuration @ref pin_config_t
 * @param logic
 * @return status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : The function has issue to perform this action   
 */

#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t * _pin_config , logic_t logic){
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config-> pin > PORT_PIN_MAX_NUMBER-1) {
        ret = E_NOT_OK;
    }
    else{
        switch (logic){
            case GPIO_LOW:
                CLEAR_BIT(*lat_register[_pin_config->port] , _pin_config->pin);
                break;
            case GPIO_HIGH :
                SET_BIT(*lat_register[_pin_config->port] , _pin_config->pin);
                break;
            default : ret = E_NOT_OK; 
        } 
    }
    
    return ret;
}
#endif

/**
 * 
 * @param _pin_config pointer to the configuration @ref pin_config_t
 * @param logic
 * @return status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : The function has issue to perform this action  
 */

#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t * _pin_config , logic_t *logic){
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || NULL == logic || _pin_config-> pin > PORT_PIN_MAX_NUMBER-1) {
        ret = E_NOT_OK;
    }
    else {
        *logic = READ_BIT (*port_register[_pin_config->port] , _pin_config->pin);
    }
    
    return ret;
}
#endif

/**
 * 
 * @param _pin_config pointer to the configuration @ref pin_config_t
 * @return status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : The function has issue to perform this action  
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t * _pin_config){
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config-> pin > PORT_PIN_MAX_NUMBER-1) {
        ret = E_NOT_OK;
    }
    else {
        TOGGLE_BIT (*lat_register[_pin_config->port] , _pin_config->pin);
    }
    
    return ret;
}
#endif

/**
 * 
 * @param _pin_config pointer to the configuration @ref pin_config_t
 * @return status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : The function has issue to perform this action  
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_initialize(const pin_config_t * _pin_config){
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config-> pin > PORT_PIN_MAX_NUMBER-1) {
        ret = E_NOT_OK;
    }
    else {
        ret = gpio_pin_direction_initialize(_pin_config);
        ret = gpio_pin_write_logic(_pin_config, _pin_config->logic);
    }
    
    return ret;
    
}
#endif

/**
 * 
 * @param port
 * @param direction_status
 * @return status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : The function has issue to perform this action  
 */

#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_direction_initialize(port_index_t port, uint8_t direction){
    Std_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else {
        *tris_register[port] = direction;
    }
    
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param direction_status
 * @return status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : The function has issue to perform this action  
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8_t * direction_status){
    Std_ReturnType ret = E_OK;
    if (NULL == direction_status || port > PORT_MAX_NUMBER-1) {
        ret = E_NOT_OK;
    }
    else {
        *direction_status = *tris_register[port];
        
    }
    
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : The function has issue to perform this action  
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8_t logic){
    Std_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else {
        *lat_register[port] = logic;
        
    }
    return ret;
}
#endif


/**
 * 
 * @param port
 * @param logic
 * @return status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : The function has issue to perform this action   
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8_t * logic){
    Std_ReturnType ret = E_OK;
    if (NULL == logic || port > PORT_MAX_NUMBER-1) {
        ret = E_NOT_OK;
    }
    else {
        *logic = *lat_register[port];
    }
    
    return ret;
}
#endif


/**
 * 
 * @param port
 * @return status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : The function has issue to perform this action   
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t port){
    Std_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }
    else {
        *lat_register[port] ^= PORTC_MASK;
    }
    return ret;
}
#endif