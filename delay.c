void delay_us(unsigned int del)
{
	del*=12;
	while(del--);
}

void delay_ms(unsigned int del)
{
	del*=12000;
  	while(del--);
}

void delay_s(unsigned int del)
{
	del*=12000000;
	while(del--);
}


