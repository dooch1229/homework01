#include <stdio.h>

int clearBuffer(char* screenBuf, int width, int height)
{
	int i = 0;
	int j = 0;
	while (j < height)
	{
		while (i < width + 1)
		{
			if (i == width)
				screenBuf[i + (j * (width + 1))] = '\n';
			else
			{
				if (i == 0 || i == 1 || i == (width - 1) || i == (width - 2) || j == 0 || j == (height - 1))
					screenBuf[i + (j * (width + 1))] = '#';
				else
					screenBuf[i + (j * (width + 1))] = ' ';
			}
			i = i + 1;
		}
		i = 0;
		j = j + 1;
	}
	screenBuf[height * (width + 1) - 1] = '\0';
}

void writeStringToBuffer(char* screenBuf, const char* string, int x, int y, int width)
{
	int i = 0;

	while (string[i] != '\0')
	{
		screenBuf[x + i + (y * (width + 1))] = string[i];
		i = i + 1;
	}
}

void setTitleToScreenBuffer(char* screenBuf, int width, int height)
{
	clearBuffer(screenBuf, 30, 15);
	writeStringToBuffer(screenBuf, " Maze Game ", 8, 5, width);
	writeStringToBuffer(screenBuf, "1. Game start ", 6, 8, width);
	writeStringToBuffer(screenBuf, "2. How to play ", 6, 9, width);
	writeStringToBuffer(screenBuf, "3. Exit ", 6, 10, width);
}

void setHowToPlayscreenBuffer(char* screenBuf, int width, int height)
{
	clearBuffer(screenBuf, 30, 15);
	writeStringToBuffer(screenBuf, "To find the way", 7, 6, width);
	writeStringToBuffer(screenBuf, "Press arrow keys to move",3, 9, width);
}

void setGameOverToScreenBuffer(char* screenBuf, int width, int height)
{
	clearBuffer(screenBuf, 30, 15);
	writeStringToBuffer(screenBuf, "You Died", 11, 5, width);
	writeStringToBuffer(screenBuf, "Return to title", 7, 9, width);
}

int main()
{
	int width = 30;
	int height = 15;
	char screenBuf[465];
	int game_state = 1;

	while (game_state)
	{
		int input;
		if (game_state == 1) {
			setTitleToScreenBuffer(screenBuf, width, height);
			printf("%s", screenBuf);
			scanf("%d", &input);
			if (input == 1)
			{
				game_state = 1;
				continue;
			}
			else if (input == 2) {
				game_state = 2;
				continue;
			}
			else if (input == 3) {
				game_state = 3;
				continue;;
			}
			else {
				break;
			}
		}
		else if (game_state == 2) {
			setHowToPlayscreenBuffer(screenBuf, width, height);
			printf("%s", screenBuf);
			scanf("%d", &input);
			if (input == 1)
			{
				game_state = 1;
				continue;
			}
			else if (input == 2)
			{
				game_state = 2;
				continue;
			}
			else if (input == 3) {
				game_state = 3;
				continue;
			}
			else {
				break;
			}
		}
		else if (game_state == 3) {
			setGameOverToScreenBuffer(screenBuf, width, height);
			printf("%s", screenBuf);
			scanf("%d", &input);
			if (input == 1)
			{
				game_state = 1;
				continue;
			}
			else if (input == 2)
			{
				game_state = 2;
				continue;
			}
			else if (input == 3) {

				game_state = 3;
				continue;
			}
			else {
				break;
			}
		}
		return 0;
	}
}