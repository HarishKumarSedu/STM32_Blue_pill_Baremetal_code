
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





if __name__ == '__main__':

    # GPIO().USART_SR_Flages()
    # GPIO().USART_CR1()
    # GPIO().USART_CR2()
    GPIO().USART_CR3()
