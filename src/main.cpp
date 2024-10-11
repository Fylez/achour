#include <ctime>
#include <SFML/Audio.hpp>
#include <iostream>

int getHour()
{
	std::time_t currentTime;
	std::tm *timezone;

	currentTime = std::time(NULL);
	timezone = std::localtime(&currentTime);
	
	return(timezone->tm_hour);
}

int	main(void){

	sf::Music music;
	int hour;
	while(1)
	{
		hour = getHour();
		while(hour == getHour())
		{
	
			if(music.getStatus() == sf::SoundSource::Stopped)
			{
					if (!music.openFromFile("sunny/" + std::to_string(hour) + ".flac"))
					{
						std::cout << "error" << std::endl;
						return -1;
					}
					std::cout << "Playing " << "sunny " << "variant for " << hour << std::endl;
					music.play();
				
			}
			sf::sleep(sf::seconds(3));
		}
		if(music.getStatus() == sf::SoundSource::Playing)
			music.stop();
	}
}
