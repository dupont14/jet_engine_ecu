#include <gpiod.h>
#include <iostream>
#include <unistd.h>

#define GPIO_CHIP "/dev/gpiochip0"
#define GPIO_LINE 17 //gpio number

int main() {
	gpiod_chip *chip; 
	gpiod_line *line;
	int value = 0;

	//open the chip fikle
	chip = gpiod_chip_open(GPIO_CHIP);
	if(!chip){
		perror("gpiod_chip_open");
		return 1;
	}
	
	line = gpiod_chip_get_line(chip, GPIO_LINE);
	if(!line)
	{
		perror("gpiod_chip_get_line");
		gpiod_chip_close(chip);
		return 1;
	}

	//requesting the line as an output
	if(gpiod_line_request_output(line,"gpio-test", 0) < 0)
	{
		perror("gpiod_line_request_output");
                gpiod_chip_close(chip);
		return 1;
	}

	std::cout << "toggling GPIO: " <<  GPIO_LINE << std::endl;
	
	//toggle gpio

	for (int i = 0; i < 10; i++)
	{
		value = !value;
		gpiod_line_set_value(line, value); // how you set the value
		std::cout << "GPIO value set to" << value << std::endl;
		sleep(1);
	}

	//releasing the hardware
	gpiod_line_release(line);
	gpiod_chip_close(chip);

	return 0;

}
