
class GPIO:

    def __init__(self) -> None:
        pass

    def gpio_Conf(self):
        pass 
    
    def USART_SR_Flages(self):
        SR_flags = ['OVER8', 'Reserved', 'UE', 'M', 'WAKE', 'PCE', 'PS', 'PEIE', 'TXEIE', 'TCIE', 'RXNEIE', 'IDLEIE', 'TE', 'RE', 'RWU', 'SBK']
        j=0
        for i in SR_flags:
            
            print(f'#define USART_SR_{i}_FLAG        ((uint32_t)(1U << {j}))')
            j+=1

    def USART_CR1(self):
        SR_flags = ['OVER8', 'Reserved', 'UE', 'M', 'WAKE', 'PCE', 'PS', 'PEIE', 'TXEIE', 'TCIE', 'RXNEIE', 'IDLEIE', 'TE', 'RE', 'RWU', 'SBK']
        j=0
        for i in SR_flags:
            
            print(f'#define USART_CR1_{i}        ((uint32_t)(1U << {j}))')
            j+=1




if __name__ == '__main__':

    # GPIO().USART_SR_Flages()
    GPIO().USART_CR1()
