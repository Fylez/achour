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
	//std::string sunnyFiles[] = {"0.flac", "1.flac", "2.flac", "3.flac", "4.flac", "5.flac", "6.flac" ,"7.flac" ,"8.flac" ,"9.flac" ,"10.flac", "11.flac" ,"12.flac", "13.flac", "14.flac", "15.flac", "16.flac", "17.flac", "18.flac" ,"19.flac" ,"20.flac" ,"21.flac" ,"22.flac", "23.flac"};
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
						return -1; // error
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
