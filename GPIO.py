
class GPIO:

    def __init__(self) -> None:
        pass

    def gpio_Conf(self):
        pass 
    
    def USART_SR_Flages(self):
        SR_flags = 'CTS LBD TXE TC RXNE IDLE ORE NF FE PE'
        # SR_flags = ['OVER8', 'Reserved', 'UE', 'M', 'WAKE', 'PCE', 'PS', 'PEIE', 'TXEIE', 'TCIE', 'RXNEIE', 'IDLEIE', 'TE', 'RE', 'RWU', 'SBK']
        SR_flags = SR_flags.split(' ')
        SR_flags.reverse()
        j=0
        for i in SR_flags:
            
            print(f'#define USART_SR_{i}_FLAG        ((uint32_t)(1U << {j}))')
            j+=1

    def USART_CR1(self):
        CR1_flags = ['OVER8', 'Reserved', 'UE', 'M', 'WAKE', 'PCE', 'PS', 'PEIE', 'TXEIE', 'TCIE', 'RXNEIE', 'IDLEIE', 'TE', 'RE', 'RWU', 'SBK']
        CR1_flags.reverse()
        j=0
        for i in CR1_flags:
            
            print(f'#define USART_CR1_{i}        ((uint32_t)(1U << {j}))')
            j+=1

    def USART_CR2(self):
        CR2_flags = 'LINEN STOP CLKEN CPOL CPHA LBCL Res LBDIE LBDL Res ADD'
       
        CR2_flags = CR2_flags.split(' ')
        CR2_flags.reverse()
        j=0
        for i in CR2_flags:
            if i == 'ADD':
                print(f'#define USART_SR_{i}_FLAG        ((uint32_t)(1U << {j}))')
            
            elif i == 'LINEN' :
                print(f'#define USART_SR_{i}_FLAG        ((uint32_t)(1U << {j+3+1}))')

            else:
                print(f'#define USART_SR_{i}_FLAG        ((uint32_t)(1U << {j+3}))')
                

            j+=1

    def USART_CR3(self):
        CR3_flags = 'ONEBIT CTSIE CTSE RTSE DMAT DMAR SCEN NACK HDSEL IRLP IREN EIE'
       
        CR3_flags = CR3_flags.split(' ')
        CR3_flags.reverse()
        j=0
        for i in CR3_flags:
            print(f'#define USART_SR_{i}_FLAG        ((uint32_t)(1U << {j}))')
            j+=1


    def BaseAddress(self):
        # stm32F10xxBase_Address = {
        # 0x40023000 : 'CRC',
        # 0x40022400 : 'Reserved',
        # 0x40022000 : 'FLASH_MEMORY_INTERFACE',
        # 0x40021400 : 'Reserved',
        # 0x40021000 : 'Reset_AND_CLOCK_CONTROL_RCC',
        # 0x40020400 : 'Reserved',
        # 0x40020000 : 'DMA1',
        # 0x40014C00 : 'Reserved',
        # 0x40014800 : 'TIM17',
        # 0x40014400 : 'TIM16',
        # 0x40014000 : 'TIM15',
        # 0x40013C00 : 'Reserved ',
        # 0x40013800 : 'USART1 ',
        # 0x40013400 : 'Reserved ',
        # 0x40013000 : 'SPI1',
        # 0x40012C00 : 'TIM1',
        # 0x40012800 : 'Reserved',
        # 0x40012400 : 'ADC1',
        # 0x40011C00 : 'Reserved',
        # 0x40011800 : 'GPIO_PORT_E',
        # 0x40011400 : 'GPIO_PORT_D',
        # 0x40011000 : 'GPIO_PORT_C',
        # 0x40010C00 : 'GPIO_PORT_B',
        # 0x40010800 : 'GPIO_PORT_A',
        # 0x40010400 : 'EXTI',
        # 0x40010000 : 'AFIO',
        # 0x40007C00 : 'Reserved',
        # 0x40007800 : 'CEC',
        # 0x40007400 : 'DAC',
        # 0x40007000 : 'Power_CONTROL_PWR',
        # 0x40006C00 : 'Backup_REGISTERS',
        # 0x40005C00 : 'Reserved',
        # 0x40005800 : 'I2C2 ',
        # 0x40005400 : 'I2C1',
        # 0x40004C00 : 'Reserved',
        # 0x40004800 : 'USART3',
        # 0x40004400 : 'USART2',
        # 0x40003C00 : 'Reserved',
        # 0x40003800 : 'SPI2',
        # 0x40003400 : 'Reserved',
        # 0x40003000 : 'INDEPENDENT_WATCHDOG',
        # 0x40002C00 : 'WINDOW_WATCHDOG',
        # 0x40002800 : 'RTC',
        # 0x40001800 : 'Reserved',
        # 0x40001400 : 'TIM7',
        # 0x40001000 : 'TIM6',
        # 0x40000C00 : 'Reserved',
        # 0x40000800 : 'TIM4',
        # 0x40000400 : 'TIM3',
        # 0x40000000 : 'TIM2',
        # }
        stm32F10xxBase_Address = [
        '0x40023000__CRC',
        '0x40022400__Reserved -',
        '0x40022000__Flash_memory_interface -',
        '0x40021400__Reserved -',
        '0x40021000__Reset_and_clock_control_RCC Section 6.3.12 on page 101',
        '0x40020800__Reserved -',
        '0x40020400__DMA2 Section 9.4.7 on page 159',
        '0x40020000__DMA1 Section 9.4.7 on page 15',
        '0x40014C00__Reserved',
        '0x40014800__TIM17 timer Section 15.6.16 on page 454',
        '0x40014400__TIM16 timer Section 15.6.16 on page 454',
        '0x40014000__TIM15 timer Section 15.5.18 on page 434',
        '0x40013C00__Reserved -',
        '0x40013800__USART1 Section 23.6.8 on page 646',
        '0x40013400__Reserved -',
        '0x40013000__SPI1 Section 21.4.8 on page 565',
        '0x40012C00__TIM1 timer Section 12.4.21 on page 282',
        '0x40012800__Reserved -',
        '0x40012400__ADC1 Section 10.11.15 on page 188',
        '0x40012000__GPIO_Port_G Section 7.5 on page 130',
        '0x40011C00__GPIO_Port_F Section 7.5 on page 130',
        '0x40011800__GPIO_Port_E Section 7.5 on page 130',
        '0x40011400__GPIO_Port_D Section 7.5 on page 130',
        '0x40011000__GPIO_Port_C Section 7.5 on page 130',
        '0x40010C00__GPIO_Port_B Section 7.5 on page 130',
        '0x40010800__GPIO_Port_A Section 7.5 on page 130',
        '0x40010400__EXTI Section 8.3.7 on page 143',
        '0x40010000__AFIO Section 7.5 on page 130',
        '0x40007C00__Reserved',
        '0x40007800__CEC Section 24.9.8 on page 668',
        '0x40007400__DAC Section 11.5.15 on page 210',
        '0x40007000__Power control PWR Section 4.4.3 on page 63',
        '0x40006C00__Backup_registers (BKP) Section 5.4.5 on page 69',
        '0x40005C00__Reserved -',
        '0x40005800__I2C2 Section 22.6.10 on page 598',
        '0x40005400__I2C1 Section 22.6.10 on page 598',
        '0x40005000__UART5 Section 23.6.8 on page 646',
        '0x40004C00__UART4 Section 23.6.8 on page 646',
        '0x40004800__USART3 Section 23.6.8 on page 646',
        '0x40004400__USART2 Section 23.6.8 on page 646',
        '0x40004000__Reserved -',
        '0x40003C00__SPI3 Section 21.4.8 on page 565',
        '0x40003800__SPI2 Section 21.4.8 on page 565',
        '0x40003400__Reserved -',
        '0x40003000__Independent_watchdog (IWDG) Section 18.4.5 on page 486',
        '0x40002C00__Window_watchdog (WWDG) Section 18.4.5 on page 486',
        '0x40002800__RTC Section 17.4.7 on page 480',
        '0x40002400__Reserved -',
        '0x40002000__TIM14 timer Section 14.5.11 on page 387',
        '0x40001C00__TIM13 timer Section 14.5.11 on page 387',
        '0x40001800__TIM12 timer Section 14.4.14 on page 377',
        '0x40001400__TIM7 timer Section 16.4.9 on page 468',
        '0x40001000__TIM6 timer Section 16.4.9 on page 468',
        '0x40000C00__TIM5 timer Section 13.4.19 on page 340',
        '0x40000800__TIM4 timer Section 13.4.19 on page 340',
        '0x40000400__TIM3 timer Section 13.4.19 on page 340',
        '0x40000000__TIM2 timer Section 13.4.19 on page 340',
        ]
        for field in stm32F10xxBase_Address:
            field = field.split('__')
            baseName = field[1].split(' ')
            if baseName[0] != 'Reserved' :
                print(f'#define {baseName[0].upper()}_BASE_ADDRESS                 {field[0]}')

    def I2C_CR1(self):
        CR1_flags = 'SWRST Res. ALERT PEC POS ACK STOP START NOSTRETCH ENGC ENPEC ENARP SMBTYPE Res. SMBUS PE'
       
        CR1_flags = CR1_flags.split(' ')
        CR1_flags.reverse()
        j=0
        for i in CR1_flags:
            if i != 'Res.':
                print(f'#define I2C_CR1_{i.upper()}_FLAG        ((uint32_t)(1U << {j}))')
            j+=1

    def I2C_SR1(self):
        SR1_flags = 'SMB_ALERT TIME_OUT Res. PEC_ERR OVR AF ARLO BERR TxE RxNE Res. STOPF ADD10 BTF ADDR SB'
       
        SR1_flags = SR1_flags.split(' ')
        SR1_flags.reverse()
        j=0
        for i in SR1_flags:
            if i != 'Res.':
                print(f'#define I2C_SR1_{i.upper()}_FLAG        ((uint32_t)(1U << {j}))')
            j+=1

    def I2C_SR2(self):
        SR2_flags = 'DUALF SMB_HOST SMBDE_FAULT GEN_CALL Res. TRA BUSY MSL'
       
        SR2_flags = SR2_flags.split(' ')
        SR2_flags.reverse()
        j=0
        for i in SR2_flags:
            if i != 'Res.':
                print(f'#define I2C_SR2_{i.upper()}_FLAG        ((uint32_t)(1U << {j}))')
            j+=1

if __name__ == '__main__':

    # GPIO().USART_SR_Flages()
    # GPIO().USART_CR1()
    # GPIO().USART_CR2()
    # GPIO().USART_CR3()
    # GPIO().BaseAddress()
    # GPIO().I2C_CR1()
    # GPIO().I2C_SR1()
    GPIO().I2C_SR2()
