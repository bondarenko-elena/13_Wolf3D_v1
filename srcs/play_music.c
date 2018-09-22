/*
afplay is a Mac command which plays audio file, where the last character ''&'' indicates afplay to run in the background as a job.
system("afplay ../music/music1.mp3 &");
---------------------------------------
mpg123 is analogue for Linux
*/

#include "../includes/wolf3d.h"

void	play_music()
{
	int	random;

	srand(time(NULL));
	random = rand() % 4;
	if (random == 1)
		system("mpg123  music/music1.mp3 &");
	if (random == 2)
		system("mpg123  music/music2.mp3 &");
	if (random == 3)
		system("mpg123  music/music3.mp3 &");
	if (random == 4)
		system("mpg123  music/music4.mp3 &");
}