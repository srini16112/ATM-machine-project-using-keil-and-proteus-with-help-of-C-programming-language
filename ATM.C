#include<reg51.h>

#define LCD P2;//lcd port
sbit c1=P1^0;//keypad ports 
sbit c2=P1^1;
sbit c3=P1^2;
sbit r1=P1^3;
sbit r2=P1^4;
sbit r3=P1^5;
sbit r4=P1^6;

sbit rs=P3^0; //Register port 
sbit en=P3^1; //enable port

// Function 
void delay(unsigned int ms);
void lcd_cmd(unsigned char cmd);
void lcd_dat(unsigned char dat);
void lcd_init();
void lcd_string(char *str);


unsigned int balance = 1000; // Initial balance
int i=0;
void main() {
	lcd_init();
	lcd_string("Welcome to ATM");
	delay(20);
	lcd_cmd(0x01); // Clear screen
	
	lcd_string("1:Deposit ");
	lcd_cmd(0xC0); // Move to second line
	lcd_string("2:Withdraw 3:Bal 4:Exit");
	delay(20);

	while (1) {
    r1=0;
		if(c1==0)
		{
			lcd_dat('1');
			delay(2);
			lcd_cmd(0x01); 
			if(c1=='1')
			{
			lcd_string("ONLY 500");
			delay(200);
			// (e.g., 500)
			balance += 500; // Example addition
			lcd_cmd(0x01);
			lcd_string("Deposited!");
			delay(200);
			lcd_cmd(0x01);
			}
		
			
			
		}
		if(c2==0)
		{
			lcd_dat('2');
			delay(2);
			lcd_cmd(0x01); 
			if(c2=='2')
			{
			lcd_string("ONLY 200");
			delay(200);
			//  (e.g., 200)
			if (balance >= 200) { // Check if sufficient balance
				balance -= 200;
				lcd_cmd(0x01);
				lcd_string("Withdrawn!");
			} else {
				lcd_cmd(0x01);
				lcd_string("Insufficient!");
			}
			delay(200);
			lcd_cmd(0x01);
			}
			
		}
		 if(c3==0)
		{
			lcd_dat('3');
			delay(2);
			lcd_cmd(0x01); 
			if(c3=='3')
			{
				lcd_string("Balance:");
			// Convert balance 
			lcd_cmd(0xC0);
			lcd_dat((balance / 1000) + '0');
			lcd_dat(((balance / 100) % 10) + '0');
			lcd_dat(((balance / 10) % 10) + '0');
			lcd_dat((balance % 10) + '0');
			delay(2000);
			lcd_cmd(0x01);
				
			}
			
			
		}
		r1=1;r2=0;
		if(c1==0)
		{
			lcd_dat('4');
			delay(2);
			lcd_cmd(0x01);
			if(c1=='4')
			{
			lcd_string("Thanks for visiting our ATM");
			delay(2000);
			lcd_cmd(0x01);
			}
		
			
		}
		 if(c2==0)
		{
			lcd_dat('5');
			///delay(20);
			if(c1=='5')
			{
			lcd_string("Invalid Option");
			delay(20);
			lcd_cmd(0x01);
			}
			
			
		}
	 if(c3==0)
		{
			lcd_dat('6');
			//delay(20);
			if(c1=='6')
			{
			lcd_string("Invalid Option");
			delay(20);
			lcd_cmd(0x01);
			}
			
		}
		r2=1;r3=0;
		if(c1==0)
		{
			lcd_dat('7');
			//delay(20);
			if(c1=='7')
			{
			lcd_string("Invalid Option");
			delay(20);
			lcd_cmd(0x01);
			}
			
		}
		 if(c2==0)
		{
			lcd_dat('8');
			//delay(20);
			if(c1=='8')
			{
			lcd_string("Invalid Option");
			delay(20);
			lcd_cmd(0x01);
			}
			
		}
		 if(c3==0)
		{
			lcd_dat('9');
			//delay(20);
			if(c1=='9')
			{
			lcd_string("Invalid Option");
			delay(20);
			lcd_cmd(0x01);
			}
			
		}
		r3=1;r4=0;
		if(c1==0)
		{
			lcd_dat('*');
			//delay(20);
			if(c1=='*')
			{
			lcd_string("Invalid Option");
			delay(20);
			lcd_cmd(0x01);
			}
			
		}
	 if(c2==0)
		{
			lcd_dat('0');
			//delay(20);
			if(c1=='0')
			{
			lcd_string("Invalid Option");
			delay(20);
			lcd_cmd(0x01);
			}
		
		}
		 if(c3==0)
		{
			lcd_dat('#');
			//delay(20);
			if(c1=='#')
			{
			lcd_string("Invalid Option");
			delay(20);
			lcd_cmd(0x01);
			}
		
		}
		r4=1;
			
		}
	}


// LCD Commands
void lcd_cmd(unsigned char cmd) {
	P2 = cmd;
	rs = 0; // RS = 0 for command
	en = 1; // Enable = 1
	delay(2);
	en = 0; // Enable = 0
}

void lcd_dat(unsigned char dat) {
	P2 = dat;
	rs = 1; 
	en = 1; 
	delay(2);
	en = 0; 
}

void lcd_init() {
	lcd_cmd(0x38); // 8-bit mode
	lcd_cmd(0x0C); // Display ON, Cursor OFF
	lcd_cmd(0x06); // Auto Increment cursor
	lcd_cmd(0x01); // Clear display
	delay(2);
}

void lcd_string(char *str) {
	while (*str) {
		lcd_dat(*str++);
	}
}

void delay(unsigned int ms) {
	unsigned int i, j;
	for (i = 0; i < ms; i++)
		for (j = 0; j < 1275; j++);
}
